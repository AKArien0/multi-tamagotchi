#ifndef SPI_H
#include <SPI.h>
#endif
#ifndef WIRE_H
#include <Wire.h>
#endif
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

typedef struct image_struct{
	int size;
	int break_point;
	const unsigned int data[];
} image;


int TestBit(unsigned int number, int nth);

void draw_image(Adafruit_SSD1306 &screen, image *to_draw, int pixel_colour, int origin_x, int origin_y);
