/*
 * ssd1306_i2c_module.c - Python bindings for SSD1306 OLED display via I2C bus
 * Copyright (C) 2015, mail@aliaksei.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc.
 */
#include <Python.h>
#include <structmember.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include "fonts.h"

#define I2CDEV_MAXPATH	128

#define SSD1306_WIDTH	128
#define SSD1306_HEIGHT	64
#define SSD1306_FBSIZE	SSD1306_WIDTH * SSD1306_HEIGHT / 8	//	128x8
#define SSD1306_MAXROW	8

//command macro
#define SSD1306_CMD_DISPLAY_OFF 0xAE	// turn off the OLED
#define SSD1306_CMD_DISPLAY_ON 0xAF		// turn on oled panel

typedef struct {
	PyObject_HEAD
	
	int fd;	/* open file descriptor: /dev/i2c-X */	
	uint8_t width;
	uint8_t height;

	unsigned char *font;
	int color, bg_color, char_spacing;
	int cursor_x;
	int cursor_y;
	
	unsigned char frame[SSD1306_FBSIZE];
} SSD1306PyObject;

static PyMemberDef ssd1306_members[] = {
	{"cursor_x", T_INT, offsetof(SSD1306PyObject, cursor_x), 0,
		"Cursor X position"},
	{"cursor_y", T_INT, offsetof(SSD1306PyObject, cursor_y), 0,
		"Cursor Y position"},
	{NULL}  /* Sentinel */
};


static void ssd1306_command(SSD1306PyObject *self, uint8_t c);
static void ssd1306_pixel(SSD1306PyObject *self, int x, int y, int color);
static int ssd1306_char(SSD1306PyObject *self, unsigned char ch);
static int ssd1306_charWidth(SSD1306PyObject *self, unsigned char ch);
static void swap(int *a, int *b);


static int
ssd1306_init(SSD1306PyObject *self, PyObject *args, PyObject *kwds) {
	int bus, address;
	char path[I2CDEV_MAXPATH];
	static char *kwlist[] = {"bus", "address", NULL};

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "ii", kwlist, &bus, &address))
		return -1;

	if (snprintf(path, I2CDEV_MAXPATH, "/dev/i2c-%d", bus) >= I2CDEV_MAXPATH) {
		return -1;
	}
	
	if ((self->fd = open(path, O_RDWR)) < 0) {
		return -1;
	}
	
	if (ioctl(self->fd, I2C_SLAVE, address) < 0) {
		return -2;
	}
	
	self->width = SSD1306_WIDTH;
	self->height = SSD1306_HEIGHT;
	self->color = 1;
	self->bg_color = 0;
	self->cursor_x = 0;
	self->cursor_y = 0;

	self->font = System5x7;
	self->char_spacing = 1;

	//write command to the screen registers.
	ssd1306_command(self, SSD1306_CMD_DISPLAY_OFF);//display off
	ssd1306_command(self, 0x00);	//Set Memory Addressing Mode
	ssd1306_command(self, 0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	ssd1306_command(self, 0x40);	//Set Page Start Address for Page Addressing Mode,0-7
	ssd1306_command(self, 0xB0);	//Set COM Output Scan Direction
	ssd1306_command(self, 0x81);	//---set low column address
	ssd1306_command(self, 0xCF);	//---set high column address
	ssd1306_command(self, 0xA1);	//--set start line address
	ssd1306_command(self, 0xA6);	//--set contrast control register
	ssd1306_command(self, 0xA8);
	ssd1306_command(self, 0x3F);	//--set segment re-map 0 to 127
	ssd1306_command(self, 0xC8);	//--set normal display
	ssd1306_command(self, 0xD3);	//--set multiplex ratio(1 to 64)
	ssd1306_command(self, 0x00);	//
	ssd1306_command(self, 0xD5);	//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	ssd1306_command(self, 0x80);	//-set display offset
	ssd1306_command(self, 0xD9);	//-not offset
	ssd1306_command(self, 0xF1);	//--set display clock divide ratio/oscillator frequency
	ssd1306_command(self, 0xDA);	//--set divide ratio
	ssd1306_command(self, 0x12);	//--set pre-charge period
	ssd1306_command(self, 0xDB);	//
	ssd1306_command(self, 0x40);	//--set com pins hardware configuration
	ssd1306_command(self, 0x8D);	//--set vcomh
	ssd1306_command(self, 0x14);	//0x20,0.77xVcc
	ssd1306_command(self, 0xAF);	//--set DC-DC enable
	ssd1306_command(self, SSD1306_CMD_DISPLAY_ON);	//--turn on oled panel

	return 0;
}

static PyObject *
ssd1306_update(SSD1306PyObject *self, PyObject *unused) {
	unsigned int  i = 0;
	unsigned char m, n;
	unsigned char tmpbuf[SSD1306_WIDTH+2];

	for(m=0; m<8; m++) {
		ssd1306_command(self, 0xb0+m);	// page0-page1
		ssd1306_command(self, 0x00);	// low column start address
		ssd1306_command(self, 0x10);	// high column start address

		tmpbuf[0] = 0x40;
		for (n=0; n<SSD1306_WIDTH; n++) {
			tmpbuf[n+1] = self->frame[i++];
		}

		write(self->fd, tmpbuf, SSD1306_WIDTH+1);
	}

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_clear(SSD1306PyObject *self, PyObject *unused) {
	memset(self->frame, 0x00, SSD1306_FBSIZE);

	ssd1306_update(self, NULL);

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_drawPixel(SSD1306PyObject *self, PyObject *args) {
	int x, y, color;

	if (!PyArg_ParseTuple(args, "iii", &x, &y, &color)) {
		return NULL;
	}

	ssd1306_pixel(self, x, y, color);

	Py_RETURN_NONE;
}

// Bresenham's algorithm - thx wikpedia
static PyObject *
ssd1306_drawLine(SSD1306PyObject *self, PyObject *args) {
	int x0, y0, x1, y1, color;
	
	if (!PyArg_ParseTuple(args, "iiiii", &x0, &y0, &x1, &y1, &color)) {
		return NULL;
	}
	
	int16_t steep = abs(y1 - y0) > abs(x1 - x0);

	if (steep) {
		swap(&x0, &y0);
		swap(&x1, &y1);
	}

	if (x0 > x1) {
		swap(&x0, &x1);
		swap(&y0, &y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1) {
		ystep = 1;
	} else {
		ystep = -1;
	}

	for (; x0<=x1; x0++) {
		if (steep) {
			ssd1306_pixel(self, y0, x0, color);
		} else {
			ssd1306_pixel(self, x0, y0, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_drawFastVLine(SSD1306PyObject *self, PyObject *args) {
	int x, y, len, color;
    PyObject *pArgs;
	
	if (!PyArg_ParseTuple(args, "iiii", &x, &y, &len, &color)) {
		return NULL;
	}

	pArgs = Py_BuildValue("iiiii", x, y, x, y+len-1, color);
	ssd1306_drawLine(self, pArgs);
	
	Py_RETURN_NONE;
}

static PyObject *
ssd1306_drawFastHLine(SSD1306PyObject *self, PyObject *args) {
	int x, y, len, color;
    PyObject *pArgs;
	
	if (!PyArg_ParseTuple(args, "iiii", &x, &y, &len, &color)) {
		return NULL;
	}

	pArgs = Py_BuildValue("iiiii", x, y, x+len-1, y, color);
	ssd1306_drawLine(self, pArgs);
	
	Py_RETURN_NONE;
}


static PyObject *
ssd1306_drawRect(SSD1306PyObject *self, PyObject *args) {
	int i;
	int x, y, w, h, color;
    PyObject *pArgs;

	if (!PyArg_ParseTuple(args, "iiiii", &x, &y, &w, &h, &color)) {
		return NULL;
	}

	pArgs = Py_BuildValue("iiii", x, y, w, color);
	ssd1306_drawFastHLine(self, pArgs);

	pArgs = Py_BuildValue("iiii", x, y+h-1, w, color);
	ssd1306_drawFastHLine(self, pArgs);

	pArgs = Py_BuildValue("iiii", x, y, h, color);
	ssd1306_drawFastVLine(self, pArgs);

	pArgs = Py_BuildValue("iiii", x+w-1, y, h, color);
	ssd1306_drawFastVLine(self, pArgs);
	
	Py_RETURN_NONE;
}

static PyObject *
ssd1306_fillRect(SSD1306PyObject *self, PyObject *args) {
	int i;
	int x, y, w, h, color;
    PyObject *pArgs;

	if (!PyArg_ParseTuple(args, "iiiii", &x, &y, &w, &h, &color)) {
		return NULL;
	}

	// Update in subclasses if desired!
	for (i=x; i<x+w; i++) {
		pArgs = Py_BuildValue("iiii", i, y, h, color);
		ssd1306_drawFastVLine(self, pArgs);
	}

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_drawCircle(SSD1306PyObject *self, PyObject *args) {
	int x0, y0, r, color;

	if (!PyArg_ParseTuple(args, "iiii", &x0, &y0, &r, &color)) {
		return NULL;
	}
	
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	ssd1306_pixel(self, x0, y0+r, color);
	ssd1306_pixel(self, x0, y0-r, color);
	ssd1306_pixel(self, x0+r, y0, color);
	ssd1306_pixel(self, x0-r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		ssd1306_pixel(self, x0 + x, y0 + y, color);
		ssd1306_pixel(self, x0 - x, y0 + y, color);
		ssd1306_pixel(self, x0 + x, y0 - y, color);
		ssd1306_pixel(self, x0 - x, y0 - y, color);
		ssd1306_pixel(self, x0 + y, y0 + x, color);
		ssd1306_pixel(self, x0 - y, y0 + x, color);
		ssd1306_pixel(self, x0 + y, y0 - x, color);
		ssd1306_pixel(self, x0 - y, y0 - x, color);
	}

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_setCursor(SSD1306PyObject *self, PyObject *args) {
	int x, y;
	
	if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
		return NULL;
	}

	self->cursor_x = x;
	self->cursor_y = y;

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_setFont(SSD1306PyObject *self, PyObject *args, PyObject *kwds) {
	int i, spacing = 1;
	unsigned char *font;
	font_info *f = fonts_table;
	static char *kwlist[] = {"font", "spacing", NULL};

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "s|i",  kwlist, &font, &spacing)) {
		return NULL;
	}
	
	self->char_spacing = spacing;

	while (f->name != NULL) {
		if (strcmp(f->name, font) == 0) {
			self->font = f->data;
			break;
		}
		f++;
	}

	Py_RETURN_NONE;
}

static PyObject *
ssd1306_drawChar(SSD1306PyObject *self, PyObject *args, PyObject *kwds) {
	int x = self->cursor_x, y = self->cursor_y, size = 1;
	int color = 1, bg = 0;
	unsigned char ch;
	static char *kwlist[] = {"ch", "x", "y", "color", NULL};

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "c|iii", kwlist, &ch, &x, &y, &color)) {
		return NULL;
	}
	
	self->cursor_x = x;
	self->cursor_y = y;
	self->color = color;

	ssd1306_char(self, ch);
	
	Py_RETURN_NONE;
}

static PyObject *
ssd1306_writeString(SSD1306PyObject *self, PyObject *args, PyObject *kwds) {
	int i, w;
	unsigned char *str, ch;
	int x = self->cursor_x, y = self->cursor_y, color = self->color;
	static char *kwlist[] = {"str", "x", "y", "color", NULL};
	unsigned char *font = self->font;
	
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "s|iii", kwlist, &str, &x, &y, &color)) {
		return NULL;
	}
	
	self->cursor_x = x;
	self->cursor_y = y;
	self->color = color;

	for(i=0; i<strlen(str); i++) {
		ch = str[i];
		w = ssd1306_charWidth(self, ch) + self->char_spacing;
		ssd1306_char(self, ch);
		
		if ((self->cursor_x + w) <= self->width) {
			self->cursor_x += w;
		}
		else if ((self->cursor_y + font[FONT_HEIGHT] + self->char_spacing) <= self->height) {
			self->cursor_x = 0;
			self->cursor_y += font[FONT_HEIGHT] + self->char_spacing;
		}
	}

	Py_RETURN_NONE;
}

static
void ssd1306_command(SSD1306PyObject *self, uint8_t c) {
	unsigned char buf[4] = {0};

	buf[0] = 0x00;
	buf[1] = c;
	write(self->fd, buf, 2);
}

static
void ssd1306_pixel(SSD1306PyObject *self, int x, int y, int color) {
	unsigned char row;
	unsigned char offset;
	unsigned char preData;	//previous data.
	unsigned char val;
	int16_t  index;

	if ((x < 0) || (x >= self->width) || (y < 0) || (y >= self->height))
		return;

	//get the previous data;
	row = y / 8;
	offset = y % 8;
	index = row * self->width + x;
	preData = self->frame[index];

	//set pixel;
	val = 1 << offset;
	if(color != 0) {	//white! set bit.
		self->frame[index] = preData | val;
	} else {	//black! clear bit.
		self->frame[index] = preData & (~val);
	}
}


static
int ssd1306_char(SSD1306PyObject *self, unsigned char ch) {
	int bX = self->cursor_x, bY = self->cursor_y, fgcolour = self->color, bgcolour = self->bg_color;
	int i, j, k;
	char c = ch;
	unsigned char *font = self->font;
	uint8_t width = 0;
	uint8_t height = font[FONT_HEIGHT];
	uint8_t bytes = (height + 7) / 8;
	uint8_t firstChar = font[FONT_FIRST_CHAR];
	uint8_t charCount = font[FONT_CHAR_COUNT];
	uint16_t index = 0;

	if (bX >= self->width || bY >= self->height) return -1;

	if (c == ' ') {
		width = ssd1306_charWidth(self, ' ');
		PyObject *pArgs = Py_BuildValue("iiiii", bX, bY, bX + width, bY + height, bgcolour);
		ssd1306_fillRect(self, pArgs);

		return width;
	}

	if (c < firstChar || c >= (firstChar + charCount)) return 0;
	c -= firstChar;

	if (font[FONT_LENGTH] == 0 && font[FONT_LENGTH + 1] == 0) {
		// zero length is flag indicating fixed width font (array does not contain width data entries)
		width = font[FONT_FIXED_WIDTH];
		index = c * bytes * width + FONT_WIDTH_TABLE;
	} else {
		// variable width font, read width data, to get the index
		for (i = 0; i < c; i++) {
			index += font[FONT_WIDTH_TABLE + i];
		}
		index = index * bytes + charCount + FONT_WIDTH_TABLE;
		width = font[FONT_WIDTH_TABLE + c];
	}

	if (bX < -width || bY < -height) return width;

	// last but not least, draw the character
	for (j = 0; j < width; j++) { // Width
		// for (i = bytes - 1; i < 254; i--) { // Vertical Bytes
		for (i = 0; i < bytes; i++) { // Vertical Bytes
			uint8_t data = font[index + j + (i * width)];
			int offset = (i * 8);

			if ((i == bytes - 1) && bytes > 1) {
				offset = height - 8;
			} else if (height<8) {
				offset = height - 7;
			}

			for (k = 0; k < 8; k++) { // Vertical bits
				if ((offset+k >= i*8) && (offset+k <= height)) {
					if (data & (1 << k)) {
						ssd1306_pixel(self, bX + j, bY + offset + k, fgcolour);
					} else {
						ssd1306_pixel(self, bX + j, bY + offset + k, bgcolour);
					}
				}
			}
		}
	}

	return width;
}

static
int ssd1306_charWidth(SSD1306PyObject *self, unsigned char ch) {
    char c = ch;

    // Space is often not included in font so use width of 'n'
    if (c == ' ') c = 'n';
    uint8_t width = 0;

    uint8_t firstChar = self->font[FONT_FIRST_CHAR];
    uint8_t charCount = self->font[FONT_FIRST_CHAR];

    uint16_t index = 0;

    if (c < firstChar || c >= (firstChar + charCount)) {
	    return 0;
    }
    c -= firstChar;

	if (self->font[FONT_LENGTH] == 0 && self->font[FONT_LENGTH + 1] == 0) {
	    // zero length is flag indicating fixed width font (array does not contain width data entries)
	    width = self->font[FONT_FIXED_WIDTH];
    } else {
	    // variable width font, read width data
		width = self->font[FONT_WIDTH_TABLE + c];
    }

    return width;
}

static
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b   = *a;
	*a   = temp;   
}


static PyMethodDef ssd1306_methods[] = {
	{"update", (PyCFunction)ssd1306_update, METH_NOARGS,
		"update()\n\n Update OLED display image from buffer."},
	{"clear", (PyCFunction)ssd1306_clear, METH_NOARGS,
		"clear()\n\n Clear OLED display."},
	{"pixel", (PyCFunction)ssd1306_drawPixel, METH_VARARGS,
		"pixel(x, y, color)\n\n Draws pixel at specified location and color on OLED display."},
	{"circle", (PyCFunction)ssd1306_drawCircle, METH_VARARGS,
		"circle(x, y, radius, color)\n\n Draws circle at specified location, radius and color on OLED display."},
	{"line", (PyCFunction)ssd1306_drawLine, METH_VARARGS,
		"line(x0, y0, x1, y1, color)\n\n Draws line at specified locations and color on OLED display."},
	{"line_vertical", (PyCFunction)ssd1306_drawFastVLine, METH_VARARGS,
		"line_vertical(x, y, len, color)\n\n Draws vertical line at specified location, length and color on OLED display."},
	{"line_horisontal", (PyCFunction)ssd1306_drawFastHLine, METH_VARARGS,
		"line_horisontal(x, y, len, color)\n\n Draws horisontal line at specified location, length and color on OLED display."},
	{"rect", (PyCFunction)ssd1306_drawRect, METH_VARARGS,
		"rect(x, y, w, h, color)\n\n Draws rect at specified location, width, height and color on OLED display."},
	{"rect_fill", (PyCFunction)ssd1306_fillRect, METH_VARARGS,
		"rect_fill(x, y, w, h, color)\n\n Draws and fills rect at specified location, width, height and color on OLED display."},
	{"cursor", (PyCFunction)ssd1306_setCursor, METH_VARARGS,
		"cursor(x, y)\n\n Set text cursor at specified location."},
	{"font", (PyCFunction)ssd1306_setFont, METH_VARARGS | METH_KEYWORDS,
		"font(name, spacing=1)\n\n Set text font name and char spacing."},
	{"char", (PyCFunction)ssd1306_drawChar, METH_VARARGS | METH_KEYWORDS,
		"char(ch, x=0, y=0, color=1)\n\n Draw char at current or specified position with current font and size."},
	{"write", (PyCFunction)ssd1306_writeString, METH_VARARGS | METH_KEYWORDS,
		"write(string, x=0, y=0, color=1)\n\n Draw string at current or specified position with current font and size."},
	{NULL}
};

static PyTypeObject SSD1306ObjectType = {
	PyObject_HEAD_INIT(NULL)
	0,				/* ob_size        */
	"SSD1306",		/* tp_name        */
	sizeof(SSD1306PyObject),		/* tp_basicsize   */
	0,				/* tp_itemsize    */
	0,				/* tp_dealloc     */
	0,				/* tp_print       */
	0,				/* tp_getattr     */
	0,				/* tp_setattr     */
	0,				/* tp_compare     */
	0,				/* tp_repr        */
	0,				/* tp_as_number   */
	0,				/* tp_as_sequence */
	0,				/* tp_as_mapping  */
	0,				/* tp_hash        */
	0,				/* tp_call        */
	0,				/* tp_str         */
	0,				/* tp_getattro    */
	0,				/* tp_setattro    */
	0,				/* tp_as_buffer   */
	Py_TPFLAGS_DEFAULT,		/* tp_flags       */
	"SSD1306(bus, address) -> OLED\n\nReturn a new SSD1306 object that is connected to the specified bus and I2C address.\n",	/* tp_doc         */
	0,				/* tp_traverse       */
	0,				/* tp_clear          */
	0,				/* tp_richcompare    */
	0,				/* tp_weaklistoffset */
	0,				/* tp_iter           */
	0,				/* tp_iternext       */
	ssd1306_methods,	/* tp_methods        */
	ssd1306_members,	/* tp_members        */
	0,				/* tp_getset         */
	0,				/* tp_base           */
	0,				/* tp_dict           */
	0,				/* tp_descr_get      */
	0,				/* tp_descr_set      */
	0,				/* tp_dictoffset     */
	(initproc)ssd1306_init,		/* tp_init           */
};

PyMODINIT_FUNC
initssd1306_i2c(void) 
{
	PyObject* m;

	SSD1306ObjectType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&SSD1306ObjectType) < 0)
		return;

	m = Py_InitModule3("ssd1306_i2c", NULL,
		   "Python bindings for SSD1306 OLED display via I2C bus");
	if (m == NULL)
		return;

	Py_INCREF(&SSD1306ObjectType);
	PyModule_AddObject(m, "SSD1306", (PyObject *)&SSD1306ObjectType);
}
