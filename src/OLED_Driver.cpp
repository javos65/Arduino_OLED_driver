/*****************************************************************************
* | File      	:   OLED_Driver.cpp
* | Author      :   Waveshare team / Jay Fox
* | Function    :   1.5inch RGB OLED Module Drive function
* | Info        :
*----------------
* |	This version:   V3.0
* | Date        :   January 2023
* | Info        :   Made ready for Arduino Library, added buffe SPI, added fast fill ,added ttf anti aliased fonts
* -----------------------------------------------------------------------------
#
#
******************************************************************************/
#include "OLED_Driver.h"
#include "stdio.h"
#include "Debug.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h> //memset()
#include <math.h>
#include "fonts.h"

// GLOBALS
PAINT Paint; // Image collection
uint8_t pinCS= OLED_CS;
uint8_t pinDC = OLED_DC;
uint8_t pinRST = OLED_RST;
uint8_t displayWIDTH = RGB_WIDTH;
uint8_t displayHEIGHT = RGB_HEIGHT;
uint8_t curs_X=0, curs_X_=0, curs_Y=0;
lv_font_t *cur_FONT;
uint8_t lineBUFFER[MAXLINEBUFFER];

// FUNCTIONS
OLED_Driver::OLED_Driver()
{
}

/********************************************************************************
  function: System Init and exit
  note:
  Initialize the communication method
********************************************************************************/
uint8_t OLED_Driver::System_Init(void)
{
  
  //set pin
  //Serial.println("* Set Pins");
  pinMode(pinCS, OUTPUT);
  pinMode(pinRST, OUTPUT);
  pinMode(pinDC, OUTPUT);

#if USE_SPI_4W
  //Serial.println("* USE_SPI");
  //set OLED SPI
  //SPI.setDataMode(SPI_MODE3);  // no need MKR / UNO
  //SPI.setBitOrder(MSBFIRST);   // no need MKR / UNO
  //SPI.setClockDivider(SPI_CLOCK_DIV2); // no need MKR / UNO
  SPI.begin();
  //SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE3));
#endif
  return 0;
}

uint8_t OLED_Driver::systemio(int cs,int dc, int rst)
{
  //set pinIO pins ChipSelect, Data/Command, Reset
  pinCS=cs;
  pinDC=dc;
  pinRST=rst;
  return 0;
}

uint8_t OLED_Driver::systemsize(uint16_t x,uint16_t y)
{
  //set DisplaySize in adressable pixels
  displayWIDTH=x;
  displayHEIGHT=y;  
  return 0;
}

/*******************************************************************************
function:
            Public Dev_Config Functions
*******************************************************************************/

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
    delay(100);
    OLED_RST_0;
    delay(100);
    OLED_RST_1;
    delay(100);
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
    SPI.transfer(Reg);
    OLED_CS_1;
#endif
}

void OLED_Driver::OLED_WriteData(uint8_t Data)
{   
#if USE_SPI_4W
    OLED_DC_1;
    OLED_CS_0;
    SPI.transfer(Data);
    OLED_CS_1;
#endif
}

void OLED_Driver::OLED_WriteBuffer(uint8_t *Buf, uint16_t Count)
{   
#if USE_SPI_4W
    OLED_DC_1;
    OLED_CS_0;
    SPI.transfer(Buf,Count);
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
    OLED_WriteData(0x12); // unlock driver : 12h (A[2]=0b) can unlock the OLED driver IC
    OLED_WriteReg(0xfd);  // command lock
    OLED_WriteData(0xB1); // A[7:0] = B1b, Command A2,B1,B3,BB,BE,C1 accessible if in unlock state 


    OLED_WriteReg(0xae);  // display off
    OLED_WriteReg(0xa4);  // Normal Display mode

    OLED_WriteReg(0x15);  //set column address
    OLED_WriteData(0x00);     //column address start 00
    OLED_WriteData(0x7f);     //column address end 127
    OLED_WriteReg(0x75);  //set row address
    OLED_WriteData(0x00);     //row address start 00
    OLED_WriteData(0x7f);     //row address end 127    

    OLED_WriteReg(0xB3);   //Front Clock Divider (DivSet)/Oscillator Frequency 
    OLED_WriteData(0xF1);  // 0001 A[3:0] [reset=0001], divide by DIVSET divide by 2
                           // 1111 A[7:4] Oscillator frequency, frequency increases as level  increases [reset=1101b] 

    OLED_WriteReg(0xCA);   // Set MUX Ratio
    OLED_WriteData(0x7F);  // 127

    OLED_WriteReg(0xa0);  //set re-map & data format : Set Re-map / Color Depth 
    OLED_WriteData(0x74);   // 0 A[0]=0b, Horizontal address increment [reset] -> A[0]=1b, Vertical address increment 
                            // 0 A[1]=0b, Column address 0 is mapped to SEG0 [reset] 
                            // 1 A[2]=0b, Color sequence: A-B-C [reset] , A[2]=1b, Color sequence is swapped: C-B-A
                            // 0 A[3] reserved = 0
                            // 1 A[4]=0b, Scan from COM0 to COM[N-1] [reset]  / A[4]=1b, Scan from COM[N-1] to COM0. 
                            // 1 A[5]=1b, Enable COM Split Odd Even [reset] 
                            // 01 A[7:6] Set Color Depth : 00b / 01b: 65k color [reset] 

    OLED_WriteReg(0xa1);  //set display start line
    OLED_WriteData(0x00); //start 00 line

    OLED_WriteReg(0xa2);  //set display offset
    OLED_WriteData(0x00); //line zero

    OLED_WriteReg(0xAB);  // Function select    
    OLED_WriteReg(0x01);  // A[7:6]=00b, Select 8-bit parallel interface [reset]  / A[0]=1b, Enable internal VDD regulator [reset]

    OLED_WriteReg(0xB4);  //Set Segment Low Voltage (VSL) 
    OLED_WriteData(0xA0); // A[1:0]=00 External VSL [reset] 
    OLED_WriteData(0xB5); // fixed
    OLED_WriteData(0x55); // fixed

    OLED_WriteReg(0xC1);   //Set Contrast Current for Color A,B,C 
    OLED_WriteData(0xC8);  // A[7:0] Contrast Value Color A [reset=10001010b] 
    OLED_WriteData(0x80);  // B[7:0] Contrast Value Color B [reset=01010001b] 
    OLED_WriteData(0xC0);  // C[7:0] Contrast Value Color C [reset=10001010b]

    OLED_WriteReg(0xC7);   // Master Contrast Current Control 
    OLED_WriteData(0x0F);  //0000 1111b no change [reset]

    OLED_WriteReg(0xB1);   // Set Reset (Phase 1) / Pre-charge (Phase 2) period 
    OLED_WriteData(0x32);   // A[7:4] Phase 2 period of 3~15 DCLK(s) clocks : 3 = 3 DCLK
                            // A[3:0] Phase 1 period of 5~31 DCLK(s) clocks : 2 = 5 DCLKs 

    OLED_WriteReg(0xB2);   // Display Enhancement
    OLED_WriteData(0xA4);  //A[7:0] = A4h, B[7:0] = 00h, C[7:0] = 00h enhance display performance
    OLED_WriteData(0x00);  // fixed
    OLED_WriteData(0x00);  // fixed

    OLED_WriteReg(0xBB);   // Set Pre-charge voltage 
    OLED_WriteData(0x17); // A[4:0]  0000= 0.20 x VCC    .. 11111 = 0.60 x VC

    OLED_WriteReg(0xB6);   // Set Second Pre-charge Period
    OLED_WriteData(0x01);  // 0001b 1 DCLKS 

    OLED_WriteReg(0xBE);   // Set VCOMH Voltage  -> comm detect voltage
    OLED_WriteData(0x05);  // A[2:0]  : 101  = 0.82 x VCC [reset]

    OLED_WriteReg(0xA6);    // A6h : Reset to normal display [reset
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
    delay(200);
    //Turn on the OLED display
    OLED_WriteReg(0xAF);
    Paint.Color = BLACK;
    Paint.Width = displayWIDTH;
    Paint.Height = displayHEIGHT;
}

/********************************************************************************
function:
            Clear screen
********************************************************************************/
void OLED_Driver::rgb_Clear(UWORD color)
{
    UWORD i,j;
    // use Global lineBUFFER[]

    OLED_WriteReg(0x15);
    OLED_WriteData(0);
    OLED_WriteData(displayWIDTH-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(0);
    OLED_WriteData(displayHEIGHT-1);
    // fill!
    OLED_WriteReg(0x5C);


    for(i=0; i<displayHEIGHT; i++) {
        for(j=0; j<displayWIDTH*2; j=j+2)  // create color buffer line
       { 
        lineBUFFER[j]=(color>>8)&0xff;
        lineBUFFER[j+1]=(color)&0xff;
        }
        OLED_WriteBuffer(lineBUFFER,displayWIDTH*2); // send out buffer line, buffer is cleared after send !!!
    }

/*
    for(i=0; i<displayHEIGHT; i++){
        for(i=0; i<displayWIDTH; i++)
        OLED_WriteData(Paint.Color>>8);
        OLED_WriteData(Paint.Color);
    }
*/
}

/********************************************************************************
function:   Draw a point
********************************************************************************/
void OLED_Driver::rgb_Set_Point(UBYTE Xpoint, UBYTE Ypoint, UWORD Color)
{
    if( (Xpoint>displayWIDTH-1) || (Ypoint>displayHEIGHT-1) ) return;
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
    // iuse gobal uint8_t lineBUFFER[]
    temp=displayWIDTH*2;

    OLED_WriteReg(0x15);
    OLED_WriteData(0);
    OLED_WriteData(displayWIDTH-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(0);
    OLED_WriteData(displayHEIGHT-1);
    // fill!
    OLED_WriteReg(0x5C);   
    
    for(i=0; i<displayHEIGHT; i++)
        {
        for(j=0; j<temp; j++) lineBUFFER[j] = Image[j + i*temp];
        OLED_WriteBuffer(lineBUFFER,temp);	
        }
}

/********************************************************************************
function:   Update image line to OLED,   --->> Length = BUFFERLENGTH in BYTES NOt pixel width
********************************************************************************/
void OLED_Driver::rgb_Display_Line( UBYTE *Line, UBYTE Xstart, UBYTE Ystart, UBYTE Length)
{
    UBYTE *temp;
    if( ((Xstart + (Length/2) )>displayWIDTH-1 ) || (Ystart>displayHEIGHT-1 ) || (Line==0) ) return;
    OLED_WriteReg(0x15);
    OLED_WriteData(Xstart);
    OLED_WriteData(Xstart+Length/2);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ystart);
    OLED_WriteData(Ystart);
    // fill!
    OLED_WriteReg(0x5C);   

    temp = Line;         // point to data line
    OLED_WriteBuffer(temp,Length); 
}
/********************************************************************************
function:   Update image/buffer to partial OLED
********************************************************************************/
void OLED_Driver::rgb_Display_Part(const UBYTE *Image, UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend)
{
    UWORD i, j, temp;
    UBYTE z;
    // uise global uint8_t lineBUFFER[]
    if (Xstart>Xend) {z=Xend;Xend=Xstart;Xstart=z; } // check start and end values
    if (Ystart>Yend) {z=Yend;Yend=Ystart;Ystart=z; } // check start and end values
    if( (Xstart>displayWIDTH) || (Xend>displayWIDTH) || (Ystart>displayHEIGHT) || (Yend>displayHEIGHT) ) return; // check boundaries

    OLED_WriteReg(0x15);
    OLED_WriteData(Xstart);
    OLED_WriteData(Xend-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ystart);
    OLED_WriteData(Yend-1);
    // fill!
    OLED_WriteReg(0x5C);   

    temp = (Xend-Xstart)*2;         // data with in bytes : 2 bytes per pixel graphics
    for(i=0; i<Yend-Ystart; i++){
        for(j=0; j<temp; j++) lineBUFFER[j]=pgm_read_byte(&Image[j+i*temp]);
        OLED_WriteBuffer(lineBUFFER,temp);
        }
}

/********************************************************************************
function:   write block to screen
********************************************************************************/
void OLED_Driver::rgb_Set_Block(UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend,UWORD Color)
{
    UWORD i, j, temp;
    UBYTE z;
    // uise global uint8_t lineBUFFER[]
    if (Xstart>Xend) {z=Xend;Xend=Xstart;Xstart=z; } // check start and end values
    if (Ystart>Yend) {z=Yend;Yend=Ystart;Ystart=z; } // check start and end values
    if (Xend>displayWIDTH)  Xend = displayWIDTH; 
    if (Yend>displayHEIGHT) Yend = displayHEIGHT;
    if( (Xstart>displayWIDTH)|| (Ystart>displayHEIGHT) ) return; // check boundaries

    OLED_WriteReg(0x15);
    OLED_WriteData(Xstart);
    OLED_WriteData(Xend-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ystart);
    OLED_WriteData(Yend-1);
    // fill!
    OLED_WriteReg(0x5C);   

    temp = (Xend-Xstart)*2;         // data with in bytes : 2 bytes per pixel graphics
    for(i=0; i<Yend-Ystart; i++) {
        for(j=0; j<temp; j=j+2)         // Create buffer line
            { 
            lineBUFFER[j]=(Color>>8)&0xff;
            lineBUFFER[j+1]=(Color)&0xff;
            }        
        OLED_WriteBuffer(lineBUFFER,temp);  // buffer is cleared after send !!!
        }
}

/********************************************************************************
function:   write block to screen with color fade
********************************************************************************/
void OLED_Driver::rgb_Set_BlockF(UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend,UWORD Color1,UWORD Color2)
{
    uint16_t C;
    UWORD i, j, temp;
    UBYTE z;
    // uise global uint8_t lineBUFFER[]
    if (Xstart>Xend) {z=Xend;Xend=Xstart;Xstart=z; } // check start and end values
    if (Ystart>Yend) {z=Yend;Yend=Ystart;Ystart=z; } // check start and end values
    if (Xend>displayWIDTH-1)  Xend = displayWIDTH-1;
    if (Yend>displayHEIGHT-1) Yend = displayHEIGHT-1;
    if( (Xstart>displayWIDTH-1)|| (Ystart>displayHEIGHT-1) ) return; // check boundaries

    OLED_WriteReg(0x15);
    OLED_WriteData(Xstart);
    OLED_WriteData(Xend-1);
    OLED_WriteReg(0x75);
    OLED_WriteData(Ystart);
    OLED_WriteData(Yend-1);
    // fill!
    OLED_WriteReg(0x5C);   

    temp = (Xend-Xstart)*2;         // data with in bytes : 2 bytes per pixel graphics
    for(i=0; i<Yend-Ystart; i++) {
        for(j=0; j<temp; j=j+2)         // Create buffer line
            { 
            C= Color1 - ( (Color1-Color2)*i/(Yend-Ystart) );    
            lineBUFFER[j]=(C>>8)&0xff;
            lineBUFFER[j+1]=(C)&0xff;
            }        
        OLED_WriteBuffer(lineBUFFER,temp);  // buffer is cleared after send !!!
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
    Paint.Scale = 65;
    
    Paint.WidthByte = (Width % 8 == 0)? (Width / 8 ): (Width / 8 + 1);
    Paint.HeightByte = Height;    
//    printf("WidthByte = %d, HeightByte = %d\r\n", Paint.WidthByte, Paint.HeightByte);
//    printf(" EPD_WIDTH / 8 = %d\r\n",  122 / 8);
   
    Paint.Rotate = Rotate;
        Paint.Width = Height;
        Paint.Height = Width;
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
                rgb_Set_Point(Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel, Color);
            }
        }
    } else {
        for (XDir_Num = 0; XDir_Num <  Dot_Pixel; XDir_Num++) {
            for (YDir_Num = 0; YDir_Num <  Dot_Pixel; YDir_Num++) {
                rgb_Set_Point(Xpoint + XDir_Num - 1, Ypoint + YDir_Num - 1, Color);
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
functions for Character Font handling
set_font
set_cursor
draw_string
draw_character
******************************************************************************/

// needs to be called before drawing any characters!
void OLED_Driver::set_font(lv_font_t *f)
{
    if (f)
        cur_FONT = f;
}

// set upper left position for draw_char()
void OLED_Driver::set_cursor(uint8_t x, uint8_t y)
{
    curs_X = x;
    curs_X_ = x;
    curs_Y = y;
}

uint8_t OLED_Driver::draw_string(char *s, uint16_t color,uint16_t bcolor, int8_t space)
{
int i=0;
if (s == NULL) return(0);
while (s[i]!=0)  
  {
  draw_char(s[i],color,bcolor,space);
  i=i+1;
  }
return(i);
}

uint8_t OLED_Driver::draw_char(char c, uint16_t color,uint16_t bcolor,int8_t space)
{
uint8_t width,height,bidth,gly,bpp,i,j,k; // use Global lineBUFFER[]
uint16_t index,clr,a,mask,pixelcounter;
uint32_t r,g,b,rc,gc,bc,rb,gb,bb;        // color calculators, large numbers for divisions and multiplication accuracy
const lv_font_glyph_dsc_t *glist;
const uint8_t *mappointer;
char t;
height=cur_FONT->h_px; bpp=cur_FONT->bpp; glist=cur_FONT->glyph_dsc;
if(c<32)return(0); 
gly= c-cur_FONT->unicode_first; if(gly>cur_FONT->glyph_cnt) return(0); // check ascii glyph: no imprintable characters, no characters out of font scope
width= glist[gly].w_px;
index = glist[gly].glyph_index;
mappointer = cur_FONT->glyph_bitmap;
bidth=(width*bpp)/8; if ((width*bpp)%8) bidth=bidth+1;            // calculate number of line - bytes to read
mask=1; for(i=0;i<bpp;++i){mask=mask*2;} mask=mask-1;             // mask bits LSB , ie bpp=4 = 4 bits = 0x0f
if( (curs_X+width+space) > 128) {curs_Y+=height;curs_X=curs_X_;}  // check boundries of screen, dapt cursor
if(curs_Y>128) return(0);                                         // check boundries
// split out RGB565 colors to rgb
rc= (color>>11)&0x1f; rb=((bcolor>>11)&0x1f); 
gc= (color>>5)&0x3f; gb=((bcolor>>5)&0x3f);
bc= color&0x1f;  bb=(bcolor&0x1f);

//Serial.print("* Character [");  Serial.print(c);Serial.print("] has glyphindex [");  Serial.print(gly);Serial.println("]");
//Serial.print("* Height ");  Serial.print(height);Serial.print(", width "); Serial.print(width);Serial.print(", bpp "); Serial.print(bpp);;Serial.print(", Mapped bytes "); Serial.println(bidth);
//Serial.print("* BitMap index "); Serial.print(index);Serial.print(".");Serial.print(", mask "); Serial.print(mask,BIN);Serial.println(".");    

for(i=0;i<height;++i) // loop all data lines
  {
  pixelcounter=0;    
    for(j=0;j<bidth;++j) // loop all line bytes
    {
     t=mappointer[index + i*bidth + j];
     for(k=8/bpp;k>0;--k) // check msb to lsb of the line byte, depending on bpp
          {
         a = (t>>((k-1)*bpp))&mask; // shift bit parttern into a
            r= ( ((rc*a)/mask) + (rb*(mask-a)/mask) )&0x001f;
            g= ( ((gc*a)/mask) + (gb*(mask-a)/mask) )&0x003f;
            b= ( ((bc*a)/mask) + (bb*(mask-a)/mask) )&0x001f;
        clr= (r<<11) + (g<<5) + b; 
//Serial.print("* Processing "); Serial.print((int) t);Serial.print(", masked "); Serial.print(a);Serial.print(", line:byte:pix "); Serial.print(i);;Serial.print(":"); Serial.print(j);Serial.print(i);;Serial.print(":"); Serial.print(pixelcounter);
//Serial.print(", rgb "); Serial.print(r);Serial.print(","); Serial.print(g);Serial.print(","); Serial.print(b);;Serial.print(", Color "); Serial.println(clr,HEX);
          if(bcolor==TRANSPARANT) { 
            if(a!=0) rgb_Set_Point(curs_X+pixelcounter,curs_Y+i,clr); // in transparant mode set each pixel on - skip zero value = but no anti aliasing
          }
          else {
            lineBUFFER[2*pixelcounter]=(clr>>8)&0xff;
            lineBUFFER[2*pixelcounter+1]=clr&0xff;        // build up line buffer
            }
          pixelcounter++; if(pixelcounter>width) k=1;
          }
    }
     if(bcolor!=TRANSPARANT) rgb_Display_Line( lineBUFFER, curs_X, curs_Y+i, width*2); // send line buffer
  } // end character i- loop
curs_X=curs_X+width+space;
return(1);
}
