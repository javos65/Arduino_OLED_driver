
#include <OLED_Driver.h>    // Arduino library for oled 1.5" RGB  WaveShare
#include "ImageData.h"      
//
//Defines
//
#define DEBUG_X 1  // Debug info for messages
//
//Globals
//
OLED_Driver Myoled;

void setup() {

  /*********** Serial SETUP  **********/
 #if DEBUG_X
int t=10;  //Initialize serial and wait for port to open, max 10 second waiting
  Serial.begin(115200);
  while (!Serial) {
    ; delay(1000);
    if ( (t--)== 0 ) break;
  }
Serial.println("* Oled Demo3, serial setup, starting Initialisation");
#endif 
/*********** OLED DISPLAY SETUP  **********/
 #if DEBUG_X
  Serial.print("* Oled size:");Serial.print(RGB_WIDTH);Serial.print("x");Serial.print(RGB_HEIGHT);Serial.println("pixels.");
#endif 
  Myoled.systemio(10,9,8);      // set IO ports for CS / DC / RTS
  Myoled.systeminit();          // HW init IO and SPI serial - see DevConfig.h
  Myoled.systemsize(128,128);   // Set pixel size display
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE3));
  Myoled.rgb_Init();            // Init screen : rest display, intialiseregisters
  Myoled.rgb_Clear(BLACK);
// Create a new image size
 #if DEBUG_X
  Serial.println("* Oled Intialized\r\n");
#endif 

char message[64];

  while(1) {
    
// 2.Write directly to memory through the GUI 
Serial.print("* Drawing:page 1\r\n");
      Myoled.Paint_DrawPoint(20, 40, BLUE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
      Myoled.Paint_DrawPoint(40, 40, RED, DOT_PIXEL_2X2, DOT_STYLE_DFT);
      Myoled.Paint_DrawPoint(60, 40, RED, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    
      Myoled.Paint_DrawLine(10, 10, 10, 45, MARINE_BLUE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
      Myoled.Paint_DrawLine(30, 10, 30, 45, RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
      Myoled.Paint_DrawLine(50, 10, 50, 45, MAGENTA, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
      Myoled.Paint_DrawLine(70, 10, 70, 45, GREEN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    
      Myoled.Paint_DrawCircle(30, 90, 20, CYAN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
      Myoled.Paint_DrawRectangle(15, 75, 45, 105, BROWN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);   
      Myoled.Paint_DrawCircle(100, 80, 25, BROWN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      Myoled.Paint_DrawRectangle(85, 65, 115, 95, YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      delay(3000);      
      Myoled.rgb_Clear(DARK_GRAY); 
    
Serial.print("* Drawing:page 2\r\n");

    sprintf(message,"BAMM !!");
    Myoled.set_font(&Fatregular32);Myoled.set_cursor(22,26); t+=Myoled.draw_string(message,BLACK,DARK_GRAY,0);
        Myoled.set_font(&Fatregular32);Myoled.set_cursor(20,24); t+=Myoled.draw_string(message,ORANGE,TRANSPARANT,0);
    sprintf(message,"Font Demo to the oled with text and more.");
    Myoled.set_font(&ArialB14);Myoled.set_cursor(2,60); t+=Myoled.draw_string(message,WHITE,DARK_GRAY,0);
    sprintf(message," Small ugly Courier12 ");
    Myoled.set_font(&Courier12);Myoled.set_cursor(4,110); t+=Myoled.draw_string(message,RED,BLACK,0);
    delay(3000);
    Myoled.rgb_Clear(BLACK);  
    
Serial.print("* Drawing:page 3\r\n");
    Myoled.rgb_Display_Part(gImage_1in5_rgb, 16, 10, 112, 106); // image is 90 degrees
    sprintf(message,"Phone Home");
    Myoled.set_font(&ArialI16);Myoled.set_cursor(24,88); t+=Myoled.draw_string(message,YELLOW,TRANSPARANT,0);
    Myoled.set_font(&ArialI16);Myoled.set_cursor(24,112); t+=Myoled.draw_string(message,YELLOW,BLACK,0);
    delay(3000);    
    Myoled.rgb_Clear(BLACK);  
  }   
}

void loop() {

}
