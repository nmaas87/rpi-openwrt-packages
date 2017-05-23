Python SSD1306
==============

This project contains a python module for interfacing with SSD1306 OLED device connected via I2C bus.

Partially based on Adafruit Arduino code

All code is GPLv2 licensed unless explicitly stated otherwise.

Building
--------

Use Black-Swift [VirtualBox VM] (http://www.black-swift.com/wiki/index.php?title=C/C%2B%2B_Building_and_Remote_Debugging_with_Eclipse)
In virtual machine change directory to /home/openwrt/openwrt
Copy sources to package/bsb_ssd1306_i2c/ directory, for example

Run and say yes for new bsb_ssd1306_i2c package:
```make oldconfig```

Run for compile package:
```make *package/bsb_ssd1306_i2c/compile V=s*.```

Check bin/brcm2708/packages/base/ for results (like ssd1306-i2c_0.3-1_brcm2708.ipk)

Usage
-----

First, setup I2C on your Black Swift board:

```
opkg install kmod-i2c-gpio-custom i2c-tools
insmod i2c-dev
insmod i2c-gpio-custom bus0=0,18,19
```

This mean that SDA connected to GPIO18 and SCL to GPIO19

Connect your SSD1306 OLED display. Don't forget about pull-up resistors!

Check your connections:
```
i2cdetect -y 1
```

Example programm

```python
from ssd1306_i2c import SSD1306
ssd = SSD1306(1, 0x3c) # /dev/i2c-1, device address 0x3c
ssd.clear()
ssd.circle(25, 25, 15, 1)
ssd.line(0, 0, 127, 20, 1);
ssd.update()
ssd.write("SSD1306 I2C", x=5, y=6)
ssd.update()

ssd.font("Fixed3x5")
ssd.write("1234567890", x=5, y=9, color=1)
ssd.font("Arial14")
ssd.write("1234567890", x=5, y=20, color=1)
ssd.font("Corsiva12")
ssd.write("1234567890", x=5, y=40, color=1)
ssd.update()
```

Methods
-------

    SSD1306(bus, address)

Connects to the specified I2C bus using device address

    update()

Update OLED display image from buffer.

    clear()

Clear OLED display.

    pixel(x, y, color)

Draws pixel at specified location and color on OLED display.

    circle(x0, y0, radius, color)

Draws circle at specified location, radius and color on LCD display.

    line(x0, y0, x1, y1, color)

Draws line at specified locations and color on OLED display.

    line_vertical(x, y, len, color)

Draws vertical line at specified location, length and color on OLED display.

    line_horisontal(x, y, len, color)

Draws horisontal line at specified location, length and color on OLED display.

    rect(x, y, w, h, color)

Draws rect at specified location, width, height and color on OLED display.

    rect_fill(x, y, w, h, color)

Draws and fills rect at specified location, width, height and color on OLED display.

    cursor(x, y)

Set text cursor at specified location.

    font(name, spacing=1)

Set text font name and char spacing.

    char(ch, x=0, y=0, color=1)

Draw char at current or specified position with current font and size.

    write(string, x=0, y=0, color=1)

Draw string at current or specified position with current font and size.
