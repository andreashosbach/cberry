#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "tft.h"
#include "RAIO8870.h"


uint16_t init()
{
	if (!bcm2835_init())
		return 0;

	TFT_init_board();
	TFT_hard_reset();
	RAIO_init();
	return 1;
}

void clear()
{
	RAIO_clear_screen();
}

void close()
{
	bcm2835_close();
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

void drawLine(uint16_t fromX, uint16_t fromY, uint16_t toX, uint16_t toY)
{
	Set_Geometric_Coordinate( fromX, fromY, toX, toY);
	RAIO_StartDrawing( LINE );
}

void drawCircle(uint16_t x, uint16_t y, uint16_t radius)
{
	Set_Geometric_Coordinate( x, y, x + 2 * radius, y + 2 * radius );
	RAIO_StartDrawing ( CIRCLE_NONFILL );
}

int main( int argc, char **argv )
{
	init();

	writeText(10, 150, "Hello C-Berry", COLOR_RED, COLOR_GREEN);

	close();

   	return 0;
}

















