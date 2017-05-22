#ifndef FONTS_H
#define FONTS_H

#include "fonts/SystemFont5x7.h"
#include "fonts/Font3x5.h"
#include "fonts/Arial8.h"
#include "fonts/Arial9.h"
#include "fonts/Arial12.h"
#include "fonts/Arial14.h"
#include "fonts/Arial_bold_14.h"
#include "fonts/ArialBlack20.h"
#include "fonts/ArialBlack22.h"
#include "fonts/ArialBlack24.h"
#include "fonts/ArialBlack36.h"
#include "fonts/Corsiva_12.h"
#include "fonts/DejaVuSans9.h"
#include "fonts/DejaVuSansBold9.h"
#include "fonts/DejaVuSansItalic9.h"
#include "fonts/Verdana_digits_24.h"
#include "fonts/fixednums7x15.h"
#include "fonts/fixednums8x16.h"
#include "fonts/fixednums15x31.h"
#include "fonts/dictator.h"
#include "fonts/F04b.h"
#include "fonts/Tiny.h"
#include "fonts/Webby.h"
#include "fonts/TomThumb.h"
#include "fonts/Droid_Sans_12.h"
#include "fonts/Droid_Sans_16.h"
#include "fonts/Droid_Sans_36.h"
#include "fonts/Droid_Sans_64.h"
#include "fonts/Droid_Sans_96.h"
#include "fonts/Droid_Sans_128.h"


// Font Indices
#define FONT_LENGTH             0
#define FONT_FIXED_WIDTH        2
#define FONT_HEIGHT             3
#define FONT_FIRST_CHAR         4
#define FONT_CHAR_COUNT         5
#define FONT_WIDTH_TABLE        6

typedef struct {
	unsigned char *name;
	unsigned char *data;
} font_info;

// Just comment unused fonts for reduce size
static font_info fonts_table[] = {
	{"System5x7", System5x7},
	{"Fixed3x5", Font3x5},
	{"FixedDigits7x15", fixednums7x15},
	{"FixedDigits8x16", fixednums8x16},
	{"FixedDigits15x31", fixednums15x31},
	{"Arial8", arial8},
	{"Arial9", Arial9},
	{"Arial12", Arial12},
	{"Arial14", Arial_14},
	{"ArialBold14", Arial_bold_14},
	{"ArialBlack20", ArialBlack20},
	{"ArialBlack22", ArialBlack22},
	{"ArialBlack24", ArialBlack24},
	// {"ArialBlack36", ArialBlack36},
	{"Corsiva12", Corsiva_12},
	{"Dictator", dictator},
	{"DejaVuSans9", DejaVuSans9},
	{"DejaVuSansBold9", DejaVuSansBold9},
	{"DejaVuSansItalic9", DejaVuSansItalic9},
	{"DroidSans12", Droid_Sans_12},
	{"DroidSans16", Droid_Sans_16},
	// {"DroidSans36", Droid_Sans_36},
	// {"DroidSans64", Droid_Sans_64},
	// {"DroidSans96", Droid_Sans_96},
	// {"DroidSans128", Droid_Sans_128},	
	{"VerdanaDigits24", Verdana_digits_24},
	{"F04B", F04b_03},
	{"Tiny", Tiny},
	{"TomThumb", TomThumb},
	{"WebbyCaps", WebbyCaps},
	{"WebbySmall", WebbySmall},
	{NULL, NULL}
};

#endif // FONTS_H
