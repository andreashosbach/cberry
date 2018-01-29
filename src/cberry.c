#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "tft.h"
#include "RAIO8870.h"


uint16_t initScreen()
{
	if (!bcm2835_init())
		return 0;

	TFT_init_board();
	TFT_hard_reset();
	RAIO_init();
	return 1;
}

void clearScreen()
{
	RAIO_clear_screen();
}

void closeScreen()
{
	bcm2835_close();
}

uint16_t getColor(const char* name) {
	int i = 0;
	char * names[9] = {"RED", "BLUE", "GREEN", "BLACK", "WHITE", "CYAN", "YELLOW", "MAGENTA", "DARK_GREEN"};
	uint16_t colors[9] = {0xE0, 0x03, 0x1C, 0x00, 0xFF, 0x1F, 0xFC, 0xE3, 0x0C};

	for(i = 0; i < 9; i = i + 1)
	{
		if(!strcmp(names[i], name))
		{
			return colors[i];
		}
	}

	return 0x00;
}


void writeText( uint16_t x, uint16_t y, uint16_t fontSize, unsigned char *text, uint8_t bgColor, uint8_t fgColor )
{
    RAIO_SetFontSizeFactor ( fontSize );
    RAIO_print_text ( x, y, text, bgColor , fgColor );
}

void drawSquare(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	Set_Geometric_Coordinate( y, y, x + width, y + height );
	RAIO_StartDrawing ( SQUARE_NONFILL );
}

void fillSquare(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	Set_Geometric_Coordinate( y, y, x + width, y + height );
	RAIO_StartDrawing ( SQUARE_FILL );
}

void drawLine(uint16_t fromX, uint16_t fromY, uint16_t toX, uint16_t toY)
{
	Set_Geometric_Coordinate( fromX, fromY, toX, toY);
	RAIO_StartDrawing( LINE );
}

void drawCircle(uint16_t x, uint16_t y, uint16_t radius)
{
	Set_Geometric_Coordinate_circle( x , y , radius );
	RAIO_StartDrawing ( CIRCLE_NONFILL );
}

void fillCircle(uint16_t x, uint16_t y, uint16_t radius)
{
	Set_Geometric_Coordinate_circle( x , y , radius );
	RAIO_StartDrawing ( CIRCLE_FILL );
}

setPenColor(uint16_t color)
{
	Text_Foreground_Color(color);
}
