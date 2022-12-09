/*****************************************************************************
* | File      	:   OLED_Driver.cpp
* | Author      :   Waveshare team / Jay Fox
* | Function    :   1.5inch RGB OLED Module Drive function
* | Info        :
*----------------
* |	This version:   V3.0
* | Date        :   22022
* | Info        :   Made ready for Arduino Library
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "OLED_Driver.h"
#include "stdio.h"
#include "Debug.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h> //memset()
#include <math.h>
PAINT Paint; // Image collection

OLED_Driver::OLED_Driver()
{
}

/*******************************************************************************
function:
            Public Dev_Config Functions
*******************************************************************************/
void OLED_Driver::driverdelay_ms(unsigned long xms)
{
    Driver_Delay_ms(xms);
}

void OLED_Driver::driverdelay_us(int xus)
{
    Driver_Delay_us(xus);
}

uint8_t OLED_Driver::systeminit(void)
{
    return System_Init();
}

/*******************************************************************************
function:
            Hardware reset
*******************************************************************************/
void OLED_Driver::OLED_Reset(void)
{
    OLED_RST_1;
    Driver_Delay_ms(100);
    OLED_RST_0;
    Driver_Delay_ms(100);
    OLED_RST_1;
    Driver_Delay_ms(100);
}

/*******************************************************************************
function:
            Write register address and data
*******************************************************************************/
void OLED_Driver::OLED_WriteReg(uint8_t Reg)
{

#if USE_SPI_4W
    OLED_DC_0;
    OLED_CS_0;
    SPI4W_Write_Byte(Reg);
    OLED_CS_1;
#endif
}

void OLED_WriteData(uint8_t Data)
{   
#if USE_SPI_4W
    OLED_DC_1;
    OLED_CS_0;
    SPI4W_Write_Byte(Data);
    OLED_CS_1;
#endif
}

/*******************************************************************************
function:
        Common register initialization
*******************************************************************************/
void OLED_Driver::OLED_InitReg(void)
{
    OLED_WriteReg(0xfd);  // command lock
    OLED_WriteData(0x12);
    OLED_WriteReg(0xfd);  // command lock
    OLED_WriteData(0xB1);

    OLED_WriteReg(0xae);  // display off
    OLED_WriteReg(0xa4);  // Normal Display mode

    OLED_WriteReg(0x15);  //set column address
    OLED_WriteData(0x00);     //column address start 00
    OLED_WriteData(0x7f);     //column address end 127
    OLED_WriteReg(0x75);  //set row address
    OLED_WriteData(0x00);     //row address start 00
    OLED_WriteData(0x7f);     //row address end 127    

    OLED_WriteReg(0xB3);
    OLED_WriteData(0xF1);

    OLED_WriteReg(0xCA);  
    OLED_WriteData(0x7F);

    OLED_WriteReg(0xa0);  //set re-map & data format
    OLED_WriteData(0x74);     //Horizontal address increment

    OLED_WriteReg(0xa1);  //set display start line
    OLED_WriteData(0x00);     //start 00 line

    OLED_WriteReg(0xa2);  //set display offset
    OLED_WriteData(0x00);

    OLED_WriteReg(0xAB);  
    OLED_WriteReg(0x01);  

    OLED_WriteReg(0xB4);  
    OLED_WriteData(0xA0);   
    OLED_WriteData(0xB5);  
    OLED_WriteData(0x55);    

    OLED_WriteReg(0xC1);  
    OLED_WriteData(0xC8); 
    OLED_WriteData(0x80);
    OLED_WriteData(0xC0);

    OLED_WriteReg(0xC7);  
    OLED_WriteData(0x0F);

    OLED_WriteReg(0xB1);  
    OLED_WriteData(0x32);

    OLED_WriteReg(0xB2);  
    OLED_WriteData(0xA4);
    OLED_WriteData(0x00);
    OLED_WriteData(0x00);

    OLED_WriteReg(0xBB);  
    OLED_WriteData(0x17);

    OLED_WriteReg(0xB6);
    OLED_WriteData(0x01);

    OLED_WriteReg(0xBE);
    OLED_WriteData(0x05);

    OLED_WriteReg(0xA6);
}

/********************************************************************************
function:
            initialization
********************************************************************************/
void OLED_Driver::rgb_Init(void)
{
    //Hardware reset
    OLED_Reset();

    //Set the initialization register
    OLED_InitReg();
    Driver_Delay_ms(200);

    //Turn on the OLED display
    OLED_WriteReg(0xAF);
}

/********************************************************************************
function:
            Clear screen
********************************************************************************/
void OLED_Driver::rgb_Clear(void)
{
    UWORD i;

    OLED_WriteReg(0x15);
    OLED_WriteData(0);
    OLED_WriteData(127);
    OLED_WriteReg(0x75);
    OLED_WriteData(0);
    OLED_WriteData(127);
    // fill!
    OLED_WriteReg(0x5C);

    for(i=0; i<RGB_WIDTH*RGB_HEIGHT*2; i++){
        OLED_WriteData(0x00);
    }
}

/********************************************************************************
function:   Draw a point
********************************************************************************/
void OLED_Driver::rgb_Set_Point(UBYTE Xpoint, UBYTE Ypoint, UWORD Color)
{
    OLED_WriteReg(0x15);
    OLED_WriteData(Xpoint);
    OLED_WriteData(Xpoint);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ypoint);
    OLED_WriteData(Ypoint);
    // fill!
    OLED_WriteReg(0x5C);   
    
    OLED_WriteData(Color>>8);
    OLED_WriteData(Color);
}

/********************************************************************************
function:   Update all memory to OLED
********************************************************************************/
void OLED_Driver::rgb_Display(const UBYTE *Image)
{
    UWORD i, j, temp;

    OLED_WriteReg(0x15);
    OLED_WriteData(0);
    OLED_WriteData(127);
    OLED_WriteReg(0x75);
    OLED_WriteData(0);
    OLED_WriteData(127);
    // fill!
    OLED_WriteReg(0x5C);   
    
    for(i=0; i<RGB_HEIGHT; i++)
        for(j=0; j<RGB_WIDTH*2; j++)
        {
            temp = Image[j + i*256];
            OLED_WriteData(temp);
			
        }
}

/********************************************************************************
function:   Update all memory to OLED
********************************************************************************/
void OLED_Driver::rgb_Display_Part(const UBYTE *Image, UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend)
{
    UWORD i, j, temp;

    OLED_WriteReg(0x15);
    OLED_WriteData(Xstart);
    OLED_WriteData(Xend-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ystart);
    OLED_WriteData(Yend-1);
    // fill!
    OLED_WriteReg(0x5C);   
    
    for(i=0; i<Yend-Ystart; i++)
        for(j=0; j<(Xend-Xstart)*2; j++)
        {
            temp = pgm_read_byte(&Image[j + i*(Xend-Xstart)*2]);
            OLED_WriteData(temp);
        }
}






/******************************************************************************
function: Create Image
parameter:
    image   :   Pointer to the image cache
    width   :   The width of the picture
    Height  :   The height of the picture
    Color   :   Whether the picture is inverted
******************************************************************************/
void OLED_Driver::Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color)
{
    Paint.Image = NULL;
    Paint.Image = image;

    Paint.WidthMemory = Width;
    Paint.HeightMemory = Height;
    Paint.Color = Color;    
    Paint.Scale = 2;
    
    Paint.WidthByte = (Width % 8 == 0)? (Width / 8 ): (Width / 8 + 1);
    Paint.HeightByte = Height;    
//    printf("WidthByte = %d, HeightByte = %d\r\n", Paint.WidthByte, Paint.HeightByte);
//    printf(" EPD_WIDTH / 8 = %d\r\n",  122 / 8);
   
    Paint.Rotate = Rotate;
    Paint.Mirror = MIRROR_NONE;
    
    if(Rotate == ROTATE_0 || Rotate == ROTATE_180) {
        Paint.Width = Width;
        Paint.Height = Height;
    } else {
        Paint.Width = Height;
        Paint.Height = Width;
    }
}

/******************************************************************************
function: Select Image
parameter:
    image : Pointer to the image cache
******************************************************************************/
void OLED_Driver::Paint_SelectImage(UBYTE *image)
{
    Paint.Image = image;
}

/******************************************************************************
function: Select Image Rotate
parameter:
    Rotate : 0,90,180,270
******************************************************************************/
void OLED_Driver::Paint_SetRotate(UWORD Rotate)
{
    if(Rotate == ROTATE_0 || Rotate == ROTATE_90 || Rotate == ROTATE_180 || Rotate == ROTATE_270) {
        Debug("Set image Rotate %d\r\n", Rotate);
        Paint.Rotate = Rotate;
    } else {
        Debug("rotate = 0, 90, 180, 270\r\n");
    }
}

void OLED_Driver::Paint_SetScale(UBYTE scale)
{
    if(scale == 2){
        Paint.Scale = scale;
        Paint.WidthByte = (Paint.WidthMemory % 8 == 0)? (Paint.WidthMemory / 8 ): (Paint.WidthMemory / 8 + 1);
    }else if(scale == 4){
        Paint.Scale = scale;
        Paint.WidthByte = (Paint.WidthMemory % 4 == 0)? (Paint.WidthMemory / 4 ): (Paint.WidthMemory / 4 + 1);
    }else if(scale ==16) {
        Paint.Scale = scale;
        Paint.WidthByte = (Paint.WidthMemory%2==0) ? (Paint.WidthMemory/2) : (Paint.WidthMemory/2+1); 
    }else if(scale ==65) {
        Paint.Scale = scale;
        Paint.WidthByte = Paint.WidthMemory*2; 
    }else{
        Debug("Set Scale Input parameter error\r\n");
        Debug("Scale Only support: 2 4 16 65\r\n");
    }
}
/******************************************************************************
function: Select Image mirror
parameter:
    mirror   :Not mirror,Horizontal mirror,Vertical mirror,Origin mirror
******************************************************************************/
void OLED_Driver::Paint_SetMirroring(UBYTE mirror)
{
    if(mirror == MIRROR_NONE || mirror == MIRROR_HORIZONTAL || 
        mirror == MIRROR_VERTICAL || mirror == MIRROR_ORIGIN) {
        Debug("mirror image x:%s, y:%s\r\n",(mirror & 0x01)? "mirror":"none", ((mirror >> 1) & 0x01)? "mirror":"none");
        Paint.Mirror = mirror;
    } else {
        Debug("mirror should be MIRROR_NONE, MIRROR_HORIZONTAL, \
        MIRROR_VERTICAL or MIRROR_ORIGIN\r\n");
    }    
}

/******************************************************************************
function: Draw Pixels
parameter:
    Xpoint : At point X
    Ypoint : At point Y
    Color  : Painted colors
******************************************************************************/
void OLED_Driver::Paint_SetPixel(UWORD Xpoint, UWORD Ypoint, UWORD Color)
{
    if(Xpoint > Paint.Width || Ypoint > Paint.Height){
        Debug("Exceeding display boundaries\r\n");
        return;
    }      
    UWORD X, Y;

    switch(Paint.Rotate) {
    case 0:
        X = Xpoint;
        Y = Ypoint;  
        break;
    case 90:
        X = Paint.WidthMemory - Ypoint - 1;
        Y = Xpoint;
        break;
    case 180:
        X = Paint.WidthMemory - Xpoint - 1;
        Y = Paint.HeightMemory - Ypoint - 1;
        break;
    case 270:
        X = Ypoint;
        Y = Paint.HeightMemory - Xpoint - 1;
        break;
    default:
        return;
    }
    
    switch(Paint.Mirror) {
    case MIRROR_NONE:
        break;
    case MIRROR_HORIZONTAL:
        X = Paint.WidthMemory - X - 1;
        break;
    case MIRROR_VERTICAL:
        Y = Paint.HeightMemory - Y - 1;
        break;
    case MIRROR_ORIGIN:
        X = Paint.WidthMemory - X - 1;
        Y = Paint.HeightMemory - Y - 1;
        break;
    default:
        return;
    }

    if(X > Paint.WidthMemory || Y > Paint.HeightMemory){
        Debug("Exceeding display boundaries\r\n");
        return;
    }
    
    if(Paint.Scale == 2){
        UDOUBLE Addr = X / 8 + Y * Paint.WidthByte;
        UBYTE Rdata = Paint.Image[Addr];
        if(Color == BLACK)
            Paint.Image[Addr] = Rdata & ~(0x80 >> (X % 8));
        else
            Paint.Image[Addr] = Rdata | (0x80 >> (X % 8));
    }else if(Paint.Scale == 4){
        UDOUBLE Addr = X / 4 + Y * Paint.WidthByte;
        Color = Color % 4;//Guaranteed color scale is 4  --- 0~3
        UBYTE Rdata = Paint.Image[Addr];
        
        Rdata = Rdata & (~(0xC0 >> ((X % 4)*2)));
        Paint.Image[Addr] = Rdata | ((Color << 6) >> ((X % 4)*2));
    }else if(Paint.Scale == 16) {
        UDOUBLE Addr = X / 2 + Y * Paint.WidthByte;
        UBYTE Rdata = Paint.Image[Addr];
        Color = Color % 16;
        Rdata = Rdata & (~(0xf0 >> ((X % 2)*4)));
        Paint.Image[Addr] = Rdata | ((Color << 4) >> ((X % 2)*4));
    }else if(Paint.Scale == 65) {
        rgb_Set_Point(X, Y, Color);
    }
}

/******************************************************************************
function: Clear the color of the picture
parameter:
    Color : Painted colors
******************************************************************************/
void OLED_Driver::Paint_Clear(UWORD Color)
{
    if(Paint.Scale == 2 || Paint.Scale == 4) {
        for (UWORD Y = 0; Y < Paint.HeightByte; Y++) {
            for (UWORD X = 0; X < Paint.WidthByte; X++ ) {//8 pixel =  1 byte
                UDOUBLE Addr = X + Y*Paint.WidthByte;
                Paint.Image[Addr] = Color;
            }
        }
    }else if(Paint.Scale == 16) {
        for (UWORD Y = 0; Y < Paint.HeightByte; Y++) {
            for (UWORD X = 0; X < Paint.WidthByte; X++ ) {//8 pixel =  1 byte
                UDOUBLE Addr = X + Y*Paint.WidthByte;
                Color = Color & 0x0f;
                Paint.Image[Addr] = (Color<<4) | Color;
            }
        }
    }else if(Paint.Scale == 65) {
        for (UWORD Y = 0; Y < Paint.HeightByte; Y++) {
            for (UWORD X = 0; X < Paint.WidthByte; X++ ) {//8 pixel =  1 byte
                rgb_Set_Point(X, Y, Color);
            }
        }
    }
}

/******************************************************************************
function: Clear the color of a window
parameter:
    Xstart : x starting point
    Ystart : Y starting point
    Xend   : x end point
    Yend   : y end point
    Color  : Painted colors
******************************************************************************/
void OLED_Driver::Paint_ClearWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color)
{
    UWORD X, Y;
    for (Y = Ystart; Y < Yend; Y++) {
        for (X = Xstart; X < Xend; X++) {//8 pixel =  1 byte
            Paint_SetPixel(X, Y, Color);
        }
    }
}

/******************************************************************************
function: Draw Point(Xpoint, Ypoint) Fill the color
parameter:
    Xpoint    : The Xpoint coordinate of the point
    Ypoint    : The Ypoint coordinate of the point
    Color   : Painted color
    Dot_Pixel : point size
    Dot_Style : point Style
******************************************************************************/
void OLED_Driver::Paint_DrawPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color,
                     DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_Style)
{
    if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
        Debug("Paint_DrawPoint Input exceeds the normal display range\r\n");
        printf("Xpoint = %d , Paint.Width = %d  \r\n ",Xpoint,Paint.Width);
        printf("Ypoint = %d , Paint.Height = %d  \r\n ",Ypoint,Paint.Height);
        return;
    }

    int16_t XDir_Num , YDir_Num;
    if (Dot_Style == DOT_FILL_AROUND) {
        for (XDir_Num = 0; XDir_Num < 2 * Dot_Pixel - 1; XDir_Num++) {
            for (YDir_Num = 0; YDir_Num < 2 * Dot_Pixel - 1; YDir_Num++) {
                if(Xpoint + XDir_Num - Dot_Pixel < 0 || Ypoint + YDir_Num - Dot_Pixel < 0)
                    break;
                // printf("x = %d, y = %d\r\n", Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel);
                Paint_SetPixel(Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel, Color);
            }
        }
    } else {
        for (XDir_Num = 0; XDir_Num <  Dot_Pixel; XDir_Num++) {
            for (YDir_Num = 0; YDir_Num <  Dot_Pixel; YDir_Num++) {
                Paint_SetPixel(Xpoint + XDir_Num - 1, Ypoint + YDir_Num - 1, Color);
            }
        }
    }
}

/******************************************************************************
function: Draw a line of arbitrary slope
parameter:
    Xstart ：Starting Xpoint point coordinates
    Ystart ：Starting Xpoint point coordinates
    Xend   ：End point Xpoint coordinate
    Yend   ：End point Ypoint coordinate
    Color  ：The color of the line segment
    Line_width : Line width
    Line_Style: Solid and dotted lines
******************************************************************************/
void OLED_Driver::Paint_DrawLine(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend,
                    UWORD Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style)
{
    if (Xstart > Paint.Width || Ystart > Paint.Height ||
        Xend > Paint.Width || Yend > Paint.Height) {
        Debug("Paint_DrawLine Input exceeds the normal display range\r\n");
        return;
    }

    UWORD Xpoint = Xstart;
    UWORD Ypoint = Ystart;
    int dx = (int)Xend - (int)Xstart >= 0 ? Xend - Xstart : Xstart - Xend;
    int dy = (int)Yend - (int)Ystart <= 0 ? Yend - Ystart : Ystart - Yend;

    // Increment direction, 1 is positive, -1 is counter;
    int XAddway = Xstart < Xend ? 1 : -1;
    int YAddway = Ystart < Yend ? 1 : -1;

    //Cumulative error
    int Esp = dx + dy;
    char Dotted_Len = 0;

    for (;;) {
        Dotted_Len++;
        //Painted dotted line, 2 point is really virtual
        if (Line_Style == LINE_STYLE_DOTTED && Dotted_Len % 3 == 0) {
            //Debug("LINE_DOTTED\r\n");
            if(Color)
              Paint_DrawPoint(Xpoint, Ypoint, BLACK, Line_width, DOT_STYLE_DFT);
            else
              Paint_DrawPoint(Xpoint, Ypoint, WHITE, Line_width, DOT_STYLE_DFT);
            Dotted_Len = 0;
        } else {
            Paint_DrawPoint(Xpoint, Ypoint, Color, Line_width, DOT_STYLE_DFT);
        }
        if (2 * Esp >= dy) {
            if (Xpoint == Xend)
                break;
            Esp += dy;
            Xpoint += XAddway;
        }
        if (2 * Esp <= dx) {
            if (Ypoint == Yend)
                break;
            Esp += dx;
            Ypoint += YAddway;
        }
    }
}

/******************************************************************************
function: Draw a rectangle
parameter:
    Xstart ：Rectangular  Starting Xpoint point coordinates
    Ystart ：Rectangular  Starting Xpoint point coordinates
    Xend   ：Rectangular  End point Xpoint coordinate
    Yend   ：Rectangular  End point Ypoint coordinate
    Color  ：The color of the Rectangular segment
    Line_width: Line width
    Draw_Fill : Whether to fill the inside of the rectangle
******************************************************************************/
void OLED_Driver::Paint_DrawRectangle(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend,
                         UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
{
    if (Xstart > Paint.Width || Ystart > Paint.Height ||
        Xend > Paint.Width || Yend > Paint.Height) {
        Debug("Input exceeds the normal display range\r\n");
        return;
    }

    if (Draw_Fill) {
        UWORD Ypoint;
        for(Ypoint = Ystart; Ypoint < Yend; Ypoint++) {
            Paint_DrawLine(Xstart, Ypoint, Xend, Ypoint, Color , Line_width, LINE_STYLE_SOLID);
        }
    } else {
        Paint_DrawLine(Xstart, Ystart, Xend, Ystart, Color, Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xstart, Ystart, Xstart, Yend, Color, Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xend, Yend, Xend, Ystart, Color, Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xend, Yend, Xstart, Yend, Color, Line_width, LINE_STYLE_SOLID);
    }
}

/******************************************************************************
function: Use the 8-point method to draw a circle of the
            specified size at the specified position->
parameter:
    X_Center  ：Center X coordinate
    Y_Center  ：Center Y coordinate
    Radius    ：circle Radius
    Color     ：The color of the ：circle segment
    Line_width: Line width
    Draw_Fill : Whether to fill the inside of the Circle
******************************************************************************/
void OLED_Driver::Paint_DrawCircle(UWORD X_Center, UWORD Y_Center, UWORD Radius,
                      UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
{
    if (X_Center > Paint.Width || Y_Center >= Paint.Height) {
        Debug("Paint_DrawCircle Input exceeds the normal display range\r\n");
        return;
    }

    //Draw a circle from(0, R) as a starting point
    int16_t XCurrent, YCurrent;
    XCurrent = 0;
    YCurrent = Radius;

    //Cumulative error,judge the next point of the logo
    int16_t Esp = 3 - (Radius << 1 );

    int16_t sCountY;
    if (Draw_Fill == DRAW_FILL_FULL) {
        while (XCurrent <= YCurrent ) { //Realistic circles
            for (sCountY = XCurrent; sCountY <= YCurrent; sCountY ++ ) {
                Paint_DrawPoint(X_Center + XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//1
                Paint_DrawPoint(X_Center - XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//2
                Paint_DrawPoint(X_Center - sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//3
                Paint_DrawPoint(X_Center - sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//4
                Paint_DrawPoint(X_Center - XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//5
                Paint_DrawPoint(X_Center + XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//6
                Paint_DrawPoint(X_Center + sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//7
                Paint_DrawPoint(X_Center + sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);
            }
            if (Esp < 0 )
                Esp += 4 * XCurrent + 6;
            else {
                Esp += 10 + 4 * (XCurrent - YCurrent );
                YCurrent --;
            }
            XCurrent ++;
        }
    } else { //Draw a hollow circle
        while (XCurrent <= YCurrent ) {
            Paint_DrawPoint(X_Center + XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//1
            Paint_DrawPoint(X_Center - XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//2
            Paint_DrawPoint(X_Center - YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//3
            Paint_DrawPoint(X_Center - YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//4
            Paint_DrawPoint(X_Center - XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//5
            Paint_DrawPoint(X_Center + XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//6
            Paint_DrawPoint(X_Center + YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//7
            Paint_DrawPoint(X_Center + YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//0

            if (Esp < 0 )
                Esp += 4 * XCurrent + 6;
            else {
                Esp += 10 + 4 * (XCurrent - YCurrent );
                YCurrent --;
            }
            XCurrent ++;
        }
    }
}

/******************************************************************************
function: Show English characters
parameter:
    Xpoint           ：X coordinate
    Ypoint           ：Y coordinate
    Acsii_Char       ：To display the English characters
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void OLED_Driver::Paint_DrawChar(UWORD Xpoint, UWORD Ypoint, const char Acsii_Char,
                    sFONT* Font, UWORD Color_Foreground, UWORD Color_Background)
{

  UWORD Page, Column;

  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
    //Debug("Paint_DrawChar Input exceeds the normal display range\r\n");
    return;
  }
  uint32_t Char_Offset = (Acsii_Char - ' ') * Font->Height * (Font->Width / 8 + (Font->Width % 8 ? 1 : 0));
  const unsigned char *ptr = &Font->table[Char_Offset];

  for ( Page = 0; Page < Font->Height; Page ++ ) {
    for ( Column = 0; Column < Font->Width; Column ++ ) {

      //To determine whether the font background color and screen background color is consistent
      if ( (Paint.Color == Color_Background) || (TRANSPARANT == Color_Background)) { //this process is to speed up the scan or wrtie transparant background
        if (pgm_read_byte(ptr) & (0x80 >> (Column % 8)))
          Paint_SetPixel (Xpoint + Column, Ypoint + Page, Color_Foreground );
      } else {
        if (pgm_read_byte(ptr) & (0x80 >> (Column % 8))) {
          Paint_SetPixel (Xpoint + Column, Ypoint + Page, Color_Foreground );
        } else {
          Paint_SetPixel (Xpoint + Column, Ypoint + Page, Color_Background );
        }
      }
      //One pixel is 8 bits
      if (Column % 8 == 7) {
        ptr++;
      }
    }/* Write a line */
    if (Font->Width % 8 != 0) {
      ptr++;
    }
  }/* Write all */
}

/******************************************************************************
function: Display the string
parameter:
    Xstart           ：X coordinate
    Ystart           ：Y coordinate
    pString          ：The first address of the English string to be displayed
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void OLED_Driver::Paint_DrawString_EN(UWORD Xstart, UWORD Ystart, const char * pString,
                         sFONT* Font, UWORD Color_Foreground, UWORD Color_Background)
{
    UWORD Xpoint = Xstart;
    UWORD Ypoint = Ystart;

    if (Xstart > Paint.Width || Ystart > Paint.Height) {
        Debug("Paint_DrawString_EN Input exceeds the normal display range\r\n");
        return;
    }

    while (* pString != '\0') {
        //if X direction filled , reposition to(Xstart,Ypoint),Ypoint is Y direction plus the Height of the character
        if ((Xpoint + Font->Width ) > Paint.Width ) {
            Xpoint = Xstart;
            Ypoint += Font->Height;
        }

        // If the Y direction is full, reposition to(Xstart, Ystart)
        if ((Ypoint  + Font->Height ) > Paint.Height ) {
            Xpoint = Xstart;
            Ypoint = Ystart;
        }
        Paint_DrawChar(Xpoint, Ypoint, * pString, Font, Color_Foreground, Color_Background);

        //The next character of the address
        pString ++;

        //The next word of the abscissa increases the font of the broadband
        Xpoint += Font->Width;
    }
}



/******************************************************************************
function: Display nummber
parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    Number           : The number displayed
    Font             ：A structure pointer that displays a character size
    Digit            : Fractional width
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
#define  ARRAY_LEN 255
void OLED_Driver::Paint_DrawNum(UWORD Xpoint, UWORD Ypoint,const char * Number,
                   sFONT* Font, UWORD Digit,UWORD Color_Foreground, UWORD Color_Background)
{ 
    uint8_t Str_Array[ARRAY_LEN] = {0};
    uint8_t *pStr = Str_Array;
    uint8_t i, len = 0;
    int16_t arr[2] = {0, -1};
    int16_t *p = arr;
    if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
        Debug("Paint_DisNum Input exceeds the normal display range\r\n");
        return;
    }

    while(Number[len] != '\0') {  
      len++;                                    //get total length
      (*p)++;                                   //get the integer part length 
      if(Number[len] == '.') p++;               //get fractional part length
    }

    if(Digit > 0) {    
      if(Digit <= arr[1]) {                     
        for(i=0; i<len-(arr[1]-Digit); i++)      //cut some Number
          Str_Array[i] = Number[i];
      }
      else {
        for(i=0; i<len+(Digit-arr[1]); i++) {
          if(i >= len)                           //add '0'
            Str_Array[i] = '0';
          else
            Str_Array[i] = Number[i];
        }
      }
    }
    else
      for(i=0; i<len; i++) {
        Str_Array[i] = Number[i];
        }
  
    //show
    Paint_DrawString_EN(Xpoint, Ypoint, (const char*)pStr, Font, Color_Foreground, Color_Background);
}

/******************************************************************************
function: Display time
parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    pTime            : Time-related structures
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/
void OLED_Driver::Paint_DrawTime(UWORD Xstart, UWORD Ystart, PAINT_TIME *pTime, sFONT* Font,
                    UWORD Color_Foreground, UWORD Color_Background)
{
    uint8_t value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    UWORD Dx = Font->Width;

    //Write data into the cache
    Paint_DrawChar(Xstart                           , Ystart, value[pTime->Hour / 10], Font, Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx                      , Ystart, value[pTime->Hour % 10], Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx  + Dx / 4 + Dx / 2   , Ystart, ':'                    , Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx * 2 + Dx / 2         , Ystart, value[pTime->Min / 10] , Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx * 3 + Dx / 2         , Ystart, value[pTime->Min % 10] , Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx * 4 + Dx / 2 - Dx / 4, Ystart, ':'                    , Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx * 5                  , Ystart, value[pTime->Sec / 10] , Font,  Color_Foreground, Color_Background);
    Paint_DrawChar(Xstart + Dx * 6                  , Ystart, value[pTime->Sec % 10] , Font, Color_Foreground, Color_Background);
}

/******************************************************************************
function: Display monochrome bitmap
parameter:
    image_buffer ：A picture data converted to a bitmap
info:
    Use a computer to convert the image into a corresponding array,
    and then embed the array directly into Imagedata.cpp as a .c file.
******************************************************************************/
void OLED_Driver::Paint_DrawBitMap(const unsigned char* image_buffer)
{
    UWORD x, y;
    UDOUBLE Addr = 0;

    for (y = 0; y < Paint.HeightByte; y++) {
        for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
            Addr = x + y * Paint.WidthByte;
            Paint.Image[Addr] = (unsigned char)image_buffer[Addr];
        }
    }
}

///******************************************************************************
//function: SDisplay half of monochrome bitmap
//parameter:  
//  Region : 1 Upper half 
//           2 Lower half 
//info: 
//******************************************************************************/ 
//void OLED_Driver::Paint_DrawBitMap_Half(const unsigned char* image_buffer, UBYTE Region) 
//{ 
//    UWORD x, y; 
//    UDOUBLE Addr = 0; 
//    
//    if(Region == 1){
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr];
//          }
//      }
//    }else{
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte ;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte];
//          }
//      }
//    }
//}

///******************************************************************************
//function: SDisplay half of monochrome bitmap
//parameter:
//  Region : 1 Upper half
//           2 Lower half
//info:
//******************************************************************************/
//void OLED_Driver::Paint_DrawBitMap_OneQuarter(const unsigned char* image_buffer, UBYTE Region)
//{
//    UWORD x, y;
//    UDOUBLE Addr = 0;
//    
//    if(Region == 1){
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr];
//          }
//      }
//    }else if(Region == 2){
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte ;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte];
//          }
//      }
//    }else if(Region == 3){
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte ;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte*2];
//          }
//      }
//    }else if(Region == 4){
//      for (y = 0; y < Paint.HeightByte; y++) {
//          for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
//              Addr = x + y * Paint.WidthByte ;
//              Paint.Image[Addr] = (unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte*3];
//          }
//      }
//    }
//}

void OLED_Driver::Paint_DrawBitMap_Block(const unsigned char* image_buffer, UBYTE Region)
{
    UWORD x, y;
    UDOUBLE Addr = 0;
    for (y = 0; y < Paint.HeightByte; y++) {
        for (x = 0; x < Paint.WidthByte; x++) {//8 pixel =  1 byte
            Addr = x + y * Paint.WidthByte ;
            Paint.Image[Addr] = \
            (unsigned char)image_buffer[Addr+ (Paint.HeightByte)*Paint.WidthByte*(Region - 1)];
        }
    }
}
