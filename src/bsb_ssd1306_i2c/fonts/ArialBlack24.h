/*
 *
 * ArialBlack24
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : ArialBlack24.h
 * Date                : 23.05.2009
 * Font size in bytes  : 30174
 * Font width          : 10
 * Font height         : 24
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>

#ifndef ARIALBLACK24_H
#define ARIALBLACK24_H

#define ARIALBLACK24_WIDTH 10
#define ARIALBLACK24_HEIGHT 24

static uint8_t ArialBlack24[] = {
    0x75, 0xDE, // size
    0x0A, // width
    0x18, // height
    0x20, // first char
    0x60, // char count

    // char widths
    0x00, 0x05, 0x0B, 0x0F, 0x0F, 0x17, 0x13, 0x05, 0x07, 0x07,
    0x09, 0x0D, 0x05, 0x07, 0x05, 0x07, 0x0F, 0x0A, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x05, 0x05, 0x0E, 0x0D,
    0x0E, 0x0D, 0x13, 0x13, 0x10, 0x11, 0x10, 0x0F, 0x0E, 0x12,
    0x11, 0x06, 0x0E, 0x13, 0x0E, 0x14, 0x11, 0x13, 0x0F, 0x13,
    0x11, 0x10, 0x10, 0x11, 0x13, 0x19, 0x13, 0x13, 0x11, 0x07,
    0x07, 0x07, 0x0D, 0x0D, 0x05, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F,
    0x0A, 0x0E, 0x0D, 0x05, 0x07, 0x0E, 0x05, 0x16, 0x0D, 0x0F,
    0x0E, 0x0E, 0x09, 0x0D, 0x09, 0x0E, 0x0F, 0x17, 0x10, 0x0F,
    0x0D, 0x09, 0x03, 0x09, 0x0E, 0x00,

    // font data
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x9F, 0x9F, 0x9F, 0x9F, 0x80, 0x07, 0x07, 0x07, 0x07, 0x07, // 33
    0x7E, 0xFE, 0xFE, 0xFE, 0x0C, 0x00, 0x7E, 0xFE, 0xFE, 0xFE, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0xE0, 0xE0, 0xE0, 0xE0, 0xFE, 0xFE, 0xFE, 0xE2, 0xE0, 0xE0, 0xFE, 0xFE, 0xFE, 0xE6, 0xE0, 0x71, 0xF1, 0xFD, 0xFF, 0xFF, 0x7F, 0x71, 0xF1, 0xFD, 0xFF, 0xFF, 0x7F, 0x71, 0x71, 0x70, 0x00, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, // 35
    0x40, 0xF8, 0xFC, 0xFC, 0xFE, 0x9E, 0xFF, 0xFF, 0x1E, 0x3E, 0x3E, 0x3C, 0x3C, 0x10, 0x00, 0xC0, 0xC1, 0xC3, 0xE7, 0xC7, 0x87, 0xFF, 0xFF, 0x1F, 0x9F, 0xFF, 0xFE, 0xFE, 0xFC, 0x70, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x1F, 0x3F, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, // 36
    0x70, 0xFC, 0xFE, 0xFE, 0x06, 0x06, 0xFE, 0xFE, 0xFC, 0x70, 0x00, 0x00, 0xC0, 0xF0, 0x7C, 0x1E, 0x0E, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0xC1, 0xF0, 0x7C, 0x1F, 0x07, 0xE1, 0xF0, 0xF8, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03, 0x01, // 37
    0x00, 0x00, 0x00, 0xF8, 0xFC, 0xFE, 0xFE, 0xCE, 0x8E, 0xCE, 0xFE, 0xFE, 0xFC, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0x8F, 0x0F, 0x0F, 0x1F, 0x3F, 0xFF, 0xFD, 0xF8, 0xF8, 0xFC, 0xF8, 0xF8, 0x88, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x07, 0x03, 0x01, // 38
    0x3E, 0xFE, 0xFE, 0xFE, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 39
    0x00, 0xC0, 0xF0, 0xF8, 0xFE, 0x7E, 0x0E, 0x38, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x07, 0x1F, 0x3F, 0xFF, 0xFC, 0xE0, // 40
    0x02, 0x1E, 0xFE, 0xFE, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xF0, 0xFF, 0xFF, 0x3F, 0x0F, 0x03, // 41
    0x10, 0x18, 0xB8, 0xF0, 0x7E, 0xFE, 0xF0, 0xB8, 0x18, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE7, 0xF7, 0x7F, 0x3F, 0x0F, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x07, 0x07, 0x07, 0x07, 0x07, // 46
    0x00, 0x00, 0x00, 0xE0, 0xFE, 0x7E, 0x06, 0x00, 0xE0, 0xFE, 0x7F, 0x07, 0x00, 0x00, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, // 47
    0xC0, 0xF0, 0xFC, 0xFC, 0xFE, 0x3E, 0x0E, 0x0E, 0x1E, 0x7E, 0xFE, 0xFC, 0xF8, 0xF0, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x80, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, // 48
    0xE0, 0xE0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0x01, 0x01, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, // 49
    0x60, 0x78, 0x7C, 0x7E, 0x7E, 0x1E, 0x1E, 0x0E, 0x1E, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xF8, 0xFC, 0xBE, 0x9F, 0x9F, 0x8F, 0x87, 0x83, 0x81, 0x80, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 50
    0x00, 0x38, 0x3C, 0x3C, 0x3E, 0x1E, 0x0E, 0x8E, 0xDE, 0xFE, 0xFE, 0xFC, 0xF8, 0x30, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x07, 0x07, 0x07, 0xDF, 0xFF, 0xFF, 0xFC, 0xFC, 0x20, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, // 51
    0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0x7C, 0x7E, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0xFC, 0xFE, 0xFF, 0xFF, 0xF7, 0xF3, 0xF1, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, // 52
    0x00, 0xF0, 0xFE, 0xFE, 0xFE, 0xFE, 0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x1E, 0x1E, 0x1E, 0x00, 0xC0, 0xC7, 0xC7, 0xC7, 0xC7, 0x87, 0x03, 0x03, 0x07, 0xCF, 0xFF, 0xFF, 0xFF, 0xFE, 0x30, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, // 53
    0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0x3E, 0x0E, 0x8E, 0x8E, 0x9E, 0xBE, 0x1C, 0x1C, 0x18, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x07, 0x03, 0x07, 0x87, 0xFF, 0xFF, 0xFF, 0xFE, 0x78, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, // 54
    0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x9E, 0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x3E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x00, 0xF8, 0xFC, 0xFC, 0xFE, 0x9E, 0x0E, 0x0E, 0x8E, 0xFE, 0xFE, 0xFC, 0xFC, 0x70, 0x00, 0x70, 0xF8, 0xFD, 0xFF, 0xFF, 0x8F, 0x07, 0x07, 0x07, 0xDF, 0xFF, 0xFF, 0xFD, 0xF8, 0x20, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, // 56
    0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0x1E, 0x0E, 0x0E, 0x1E, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x03, 0x87, 0x8F, 0x9F, 0xDF, 0x9E, 0x1C, 0x1C, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x06, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, // 57
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0x07, 0x07, 0x07, 0x07, 0x07, // 58
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xE7, 0xF7, 0x7F, 0x3F, 0x0F, // 59
    0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0x78, 0x78, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x79, 0x79, 0xF1, 0xF0, 0xF0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, // 60
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x78, 0x78, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0x79, 0x79, 0x7B, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0x70, 0x78, 0x7C, 0x7E, 0x7E, 0x1E, 0x1E, 0x9E, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x98, 0x9E, 0x9F, 0x9F, 0x9F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, // 63
    0x00, 0xC0, 0xF0, 0x38, 0x1C, 0xCC, 0xE6, 0x66, 0x66, 0x66, 0xE6, 0xC6, 0xE6, 0xEC, 0x0C, 0x38, 0xF0, 0xE0, 0x00, 0x7F, 0xFF, 0x80, 0x10, 0xFF, 0xFF, 0x81, 0x00, 0x00, 0x80, 0xF8, 0xFF, 0xFF, 0x81, 0x80, 0xC0, 0x78, 0x3F, 0x02, 0x00, 0x01, 0x07, 0x0E, 0x0C, 0x19, 0x19, 0x33, 0x31, 0x31, 0x31, 0x31, 0x13, 0x19, 0x19, 0x0C, 0x0C, 0x04, 0x00, // 64
    0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFC, 0xFE, 0xFE, 0x7E, 0xFE, 0xFE, 0xFE, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xC0, 0x00, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, // 65
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0xDF, 0xFF, 0xFF, 0xFD, 0xFC, 0xF8, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, // 66
    0x00, 0xE0, 0xF8, 0xF8, 0xFC, 0xFE, 0x7E, 0x3E, 0x1E, 0x1E, 0x1E, 0x3E, 0x7E, 0x7C, 0x7C, 0x78, 0x70, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, // 67
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x3E, 0x1E, 0x1E, 0x1E, 0x3E, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, // 68
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x9E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x80, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 69
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0x80, 0xE0, 0xF8, 0xF8, 0xFC, 0xFE, 0x7E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x3E, 0x7E, 0x7C, 0x3C, 0x38, 0x20, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0x80, 0x9E, 0x9E, 0x9E, 0xDE, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, // 71
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 72
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, // 74
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x80, 0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7E, 0x3E, 0x1E, 0x0E, 0x06, 0x02, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x3F, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x04, // 75
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 76
    0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0xFE, 0xFE, 0xF8, 0x80, 0x00, 0x00, 0xC0, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x03, 0x3F, 0xFF, 0xFF, 0xF8, 0xFE, 0xFF, 0xFF, 0x1F, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, // 77
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x07, 0x1F, 0x3F, 0xFF, 0xFE, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 78
    0x00, 0xE0, 0xF8, 0xF8, 0xFC, 0xFE, 0x7E, 0x3E, 0x1E, 0x1E, 0x1E, 0x3E, 0x7E, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0E, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, // 79
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x1E, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0x00, 0xE0, 0xF8, 0xF8, 0xFC, 0xFE, 0x7E, 0x3E, 0x1E, 0x1E, 0x1E, 0x3E, 0x7E, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0x00, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0xA0, 0xB0, 0xF0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x06, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x1E, 0x0E, // 81
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE3, 0x80, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, // 82
    0x00, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0x8E, 0x8E, 0x8E, 0x9E, 0x3E, 0x3E, 0x3C, 0x3C, 0x38, 0x00, 0x60, 0xE1, 0xE3, 0xE3, 0xE7, 0xC7, 0x87, 0x0F, 0x0F, 0x8F, 0xDF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, // 83
    0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, // 85
    0x02, 0x1E, 0xFE, 0xFE, 0xFE, 0xFE, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFC, 0xFE, 0xFE, 0xFE, 0x3E, 0x0E, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x7F, 0xFF, 0xFF, 0xFC, 0xE0, 0xF0, 0xFE, 0xFF, 0xFF, 0x3F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x06, 0xFE, 0xFE, 0xFE, 0xFE, 0xF8, 0x00, 0x00, 0xC0, 0xF8, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xC0, 0x00, 0x00, 0xF8, 0xFE, 0xFE, 0xFE, 0xFE, 0x06, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0x7F, 0x07, 0x01, 0x07, 0x7F, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, // 87
    0x00, 0x02, 0x0E, 0x3E, 0x7E, 0xFE, 0xFE, 0xF8, 0xF0, 0xC0, 0xE0, 0xF0, 0xFC, 0xFE, 0xFE, 0x7E, 0x1E, 0x06, 0x02, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF9, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x04, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, // 88
    0x02, 0x06, 0x1E, 0x3E, 0xFE, 0xFE, 0xFC, 0xF8, 0xE0, 0x80, 0xC0, 0xF0, 0xF8, 0xFE, 0xFE, 0x7E, 0x3E, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x9E, 0xDE, 0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x3E, 0x1E, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xBF, 0x9F, 0x87, 0x83, 0x81, 0x80, 0x80, 0x80, 0x80, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 90
    0xFE, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, // 91
    0x06, 0x7E, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x7F, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x04, // 92
    0x1E, 0x1E, 0x1E, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, // 93
    0x00, 0x80, 0xE0, 0xF8, 0xFE, 0x7E, 0x1E, 0xFE, 0xFC, 0xF0, 0xC0, 0x00, 0x00, 0x06, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // 95
    0x02, 0x06, 0x0E, 0x0E, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xC0, 0xE3, 0xF3, 0xF3, 0xF3, 0x3B, 0x39, 0x19, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x04, // 97
    0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x03, 0x83, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0x3C, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, // 98
    0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x01, 0x01, 0x01, 0x83, 0xC7, 0xC7, 0xC3, 0xC3, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, // 99
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x83, 0x83, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, // 100
    0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xBB, 0x39, 0x39, 0x39, 0xBB, 0xBF, 0xBF, 0xBF, 0x3F, 0x3C, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, // 101
    0xC0, 0xC0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFE, 0xCE, 0xCE, 0x0E, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, // 102
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x83, 0x83, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x10, 0x79, 0x73, 0xF3, 0xF3, 0xF3, 0xE3, 0xE3, 0xE1, 0xFF, 0xFF, 0x7F, 0x7F, 0x1F, // 103
    0xFE, 0xFE, 0xFE, 0xFE, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, // 104
    0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, // 105
    0x00, 0x00, 0xDE, 0xDE, 0xDE, 0xDE, 0xCE, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, // 106
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3F, 0xFF, 0xFF, 0xFF, 0xF3, 0xC1, 0x80, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x06, // 107
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, // 108
    0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, // 109
    0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, // 110
    0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x01, 0x01, 0x03, 0xC7, 0xFF, 0xFF, 0xFF, 0xFE, 0x38, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, // 111
    0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x83, 0x83, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, // 112
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x83, 0x83, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // 113
    0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, // 114
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x86, 0x8F, 0x9F, 0x9F, 0xBF, 0x3D, 0x3C, 0x39, 0x7B, 0xFB, 0xF9, 0xF1, 0xE1, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, // 115
    0xC0, 0xC0, 0xF8, 0xF8, 0xFC, 0xFC, 0xC0, 0xC0, 0xC0, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x03, 0x03, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 116
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, // 117
    0x40, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x03, 0x0F, 0x3F, 0xFF, 0xFF, 0xFC, 0xE0, 0xF0, 0xFE, 0xFF, 0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, // 118
    0x40, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x03, 0x1F, 0x7F, 0xFF, 0xFE, 0xE0, 0xF0, 0xFE, 0xFF, 0x7F, 0x0F, 0x1F, 0xFF, 0xFF, 0xFC, 0xE0, 0xF8, 0xFF, 0xFF, 0x7F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, // 119
    0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x40, 0x00, 0x00, 0x01, 0xC3, 0xEF, 0xFF, 0xFF, 0xFF, 0x7E, 0xFF, 0xFF, 0xFF, 0xE7, 0x83, 0x00, 0x00, 0x04, 0x06, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, // 120
    0x40, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x01, 0x0F, 0x3F, 0xFF, 0xFF, 0xFC, 0xE0, 0xE0, 0xFE, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xF1, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, // 121
    0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x81, 0xC1, 0xE1, 0xF1, 0xF9, 0xFF, 0x7F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 122
    0x00, 0x00, 0x00, 0xFC, 0xFE, 0xFE, 0xFE, 0x3E, 0x1E, 0x38, 0x7C, 0xFE, 0xFF, 0xFF, 0xEF, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, // 123
    0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // 124
    0x1E, 0x1E, 0x3E, 0xFE, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0x7C, 0xF0, 0xF0, 0xF8, 0xFF, 0xFF, 0x7F, 0x3F, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x1F, 0x1E, 0x1E, 0x1E, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126

};

#endif
