// colors "RRRGGGBB"
uint16_t getColor(const char* name);
uint16_t initScreen();
void clearScreen();
void closeScreen();
void writeText( uint16_t x, uint16_t y, uint16_t fontSize, unsigned char *text, uint8_t bgColor, uint8_t fgColor );
void drawSquare(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void fillSquare(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void drawLine(uint16_t fromX, uint16_t fromY, uint16_t toX, uint16_t toY);
void drawCircle(uint16_t x, uint16_t y, uint16_t radius);
void fillCircle(uint16_t x, uint16_t y, uint16_t radius);
setPenColor(uint16_t color);