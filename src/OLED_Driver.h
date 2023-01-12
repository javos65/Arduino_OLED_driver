/*****************************************************************************
* | File      	:   OLED_Driver.h
* | Author      :   Waveshare team - Jay Fox
* | Function    :   1.5inch RGB OLED Module Drive function
* | Info        :
*----------------
* |	This version:   V3.0
* | Date        :   2022
* | Info        :	Pushed into Arduino Library format
* -----------------------------------------------------------------------------
#
#
******************************************************************************/
#ifndef __OLED_DRIVER_H
#define __OLED_DRIVER_H		

#include <SPI.h>
#include "fonts.h"

/**
 * data types
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t
#define USE_SPI_4W  1  // MKR / Nano

/****************************************************************************************
    //IO Use the  library function definition
*****************************************************************************************/
//GPIO config
#define OLED_CS 10    // Orange : Uno 10 / Mkr 3 / Nano 10
#define OLED_CS_0     digitalWrite(pinCS, LOW)
#define OLED_CS_1     digitalWrite(pinCS, HIGH)

#define OLED_DC 9   //Green : 7 Uno / 6 MKR / Nano 9
#define OLED_DC_0     digitalWrite(pinDC, LOW)
#define OLED_DC_1     digitalWrite(pinDC, HIGH)

#define OLED_RST 8   // White : 8 Uno  / 7 MKR / Nano 8
#define OLED_RST_0    digitalWrite(pinRST, LOW)
#define OLED_RST_1    digitalWrite(pinRST, HIGH)

/********************************************************************************
		Define the full screen height length of the display
********************************************************************************/
#define RGB_WIDTH  128          //OLED width base
#define RGB_HEIGHT 128          //OLED height base
#define MAXLINEBUFFER 256

/********************************************************************************
		Define used fonths
********************************************************************************/
//extern lv_font_t SegmentNumber56;
extern lv_font_t HeavyNumber36;
extern lv_font_t Fatregular32;
extern lv_font_t Arcon24;
//extern lv_font_t Arcon16;
extern lv_font_t ArialI16; // italic
extern lv_font_t Arial16;
extern lv_font_t ArialB14; // old
extern lv_font_t Courier12;

/*
 * Image attributes
**/
typedef struct {
    UBYTE *Image;
    UWORD Width;
    UWORD Height;
    UWORD WidthMemory;
    UWORD HeightMemory;
    UWORD Color;
    UWORD Rotate;
    UWORD Mirror;
    UWORD WidthByte;
    UWORD HeightByte;
    UWORD Scale;
} PAINT;
extern PAINT Paint;

/**
 * image color
**/
#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x101F
#define MARINE_BLUE    0x2B5F
#define DARK_BLUE      0x00EC
#define GREEN_BLUE     0x0792
#define LIGHT_BLUE     0x74FF
#define RED            0xF800
#define DARK_RED       0x6000
#define LIGHT_RED      0xF9C7
#define PINK           0xFCB2
#define MEDIUM_RED     0xD800

#define VIOLET         0xc035
#define MAGENTA        0xF81F
#define PURPLE         0x981F
#define ORANGE         0xFC61
#define GREEN          0x07E0
#define BRIGHT_GREEN   0x77E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0
#define BROWN          0x79A0
#define GRAY           0X8430
#define LIGHT_GRAY     0xF7BE
#define DARK_GRAY      0x4228
#define DARKER_GRAY    0x18E3
#define GOLD           0xDD8D
#define SILVER         0xad76
#define TRANSPARANT    0X0001// USED FOR TEXT on TRANSPARANT BACKGROUND, close to Black

/**
 * The size of the point
**/
typedef enum {
    DOT_PIXEL_1X1  = 1, // 1 x 1
    DOT_PIXEL_2X2  ,    // 2 X 2
    DOT_PIXEL_3X3  ,    // 3 X 3
    DOT_PIXEL_4X4  ,    // 4 X 4
    DOT_PIXEL_5X5  ,    // 5 X 5
    DOT_PIXEL_6X6  ,    // 6 X 6
    DOT_PIXEL_7X7  ,    // 7 X 7
    DOT_PIXEL_8X8  ,    // 8 X 8
} DOT_PIXEL;
#define DOT_PIXEL_DFT  DOT_PIXEL_1X1  //Default dot pilex

/**
 * Point size fill style
**/
typedef enum {
    DOT_FILL_AROUND  = 1,   // dot pixel 1 x 1
    DOT_FILL_RIGHTUP  ,     // dot pixel 2 X 2
} DOT_STYLE;
#define DOT_STYLE_DFT  DOT_FILL_AROUND  //Default dot pilex

/**
 * Line style, solid or dashed
**/
typedef enum {
    LINE_STYLE_SOLID = 0,
    LINE_STYLE_DOTTED,
} LINE_STYLE;

/**
 * Whether the graphic is filled
**/
typedef enum {
    DRAW_FILL_EMPTY = 0,
    DRAW_FILL_FULL,
} DRAW_FILL;

/**
 * Custom structure of a time attribute
**/


class OLED_Driver
{
public:
	OLED_Driver();
	void rgb_Init(void);
	void rgb_Clear(UWORD Color);
	void rgb_Set_Point(UBYTE Xpoint, UBYTE Ypoint, UWORD Color);
    void rgb_Set_Block(UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend,UWORD Color);
    void rgb_Set_BlockF(UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend,UWORD Color1,UWORD Color2);
	void rgb_Display(const UBYTE *Image);
	void rgb_Display_Part(const UBYTE *Image, UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend);
    void rgb_Display_Line( UBYTE *Line, UBYTE Xstart, UBYTE Ystart, UBYTE Length); 
	uint8_t systeminit(void);
    uint8_t systemio(int cs,int dc, int rst);
    uint8_t systemsize(uint16_t x,uint16_t yt);
// Character Font handling    
    void set_font(lv_font_t *f);
    void set_cursor(uint8_t x, uint8_t y);
    uint8_t draw_string(char *s, uint16_t color,uint16_t bcolor, int8_t space);
    uint8_t draw_char(char c, uint16_t color,uint16_t bcolor,int8_t space);

//init and Clear
	void Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color);
	void Paint_SetPixel(UWORD Xpoint, UWORD Ypoint, UWORD Color);

//Drawing
	void Paint_DrawPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_FillWay);
	void Paint_DrawLine(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style);
	void Paint_DrawRectangle(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill);
	void Paint_DrawCircle(UWORD X_Center, UWORD Y_Center, UWORD Radius, UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill);

private:
	void OLED_Reset(void);
	void OLED_WriteReg(uint8_t Reg);
    void OLED_WriteData(uint8_t Data);    
    void OLED_WriteBuffer(uint8_t *Buf, uint16_t Count);
	void OLED_InitReg(void);
    uint8_t System_Init(void);

};
#endif  