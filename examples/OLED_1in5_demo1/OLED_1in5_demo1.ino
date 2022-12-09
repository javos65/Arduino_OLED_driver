


#include <OLED_Driver.h>    // Arduino library for oled 1.5" RGB  WaveShare
#include "ImageData.h"      

OLED_Driver Myoled;

void setup() {

Serial.print("* Initialize system...\r\n");
Serial.print("* Oled size:");Serial.print(RGB_WIDTH);Serial.print("x");Serial.print(RGB_HEIGHT);Serial.println("pixels.");
Serial.print("* Pins - ChipSelect:");Serial.print(OLED_CS);Serial.print(", Reset:");Serial.print(OLED_RST);Serial.print(", DataCommand:");Serial.println(OLED_DC);

  Myoled.systeminit();  // init IO and SPI serial - see DevConfig.h
  Myoled.rgb_Init();    // Int
  Myoled.driverdelay_ms(500); 
  Myoled.rgb_Clear();  

//1.Create a new image size
  UBYTE *BlackImage=NULL; // image structure
Serial.print("* Create new image structure\r\n");
  Myoled.Paint_NewImage(BlackImage, RGB_WIDTH, RGB_HEIGHT, 0, BLACK);  // rotation 0 - for all drawing functions - NOT for image dump
  Myoled.Paint_SetScale(65);  // RGB resolution: 2,4,16,65

  while(1) {
    
// 2.Write directly to memory through the GUI 
Serial.print("* Drawing:page 1\r\n");
      Myoled.Paint_DrawPoint(20, 40, BLUE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
      Myoled.Paint_DrawPoint(40, 40, BRED, DOT_PIXEL_2X2, DOT_STYLE_DFT);
      Myoled.Paint_DrawPoint(60, 40, GRED, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    
      Myoled.Paint_DrawLine(10, 10, 10, 45, GBLUE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
      Myoled.Paint_DrawLine(30, 10, 30, 45, RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
      Myoled.Paint_DrawLine(50, 10, 50, 45, MAGENTA, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
      Myoled.Paint_DrawLine(70, 10, 70, 45, GREEN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    
      Myoled.Paint_DrawCircle(30, 90, 20, CYAN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
      Myoled.Paint_DrawRectangle(15, 75, 45, 105, BROWN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);   
      Myoled.Paint_DrawCircle(80, 80, 25, BROWN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      Myoled.Paint_DrawRectangle(65, 65, 95, 95, CYAN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
      Myoled.driverdelay_ms(3000);      
      Myoled.rgb_Clear(); 
    
Serial.print("* Drawing:page 2\r\n");
    for(UBYTE i=0; i<16; i++){
        Myoled.Paint_DrawRectangle(0, i*8, 127, (i+1)*8, i*4095, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    }     
    Myoled.Paint_DrawString_EN(15, 24, "Oled Demo", FONT16, BLACK,TRANSPARANT);
    Myoled.Paint_DrawString_EN(10, 48, "Transparant background", FONT8, BLUE,TRANSPARANT);
    Myoled.driverdelay_ms(3000);
    Myoled.rgb_Clear();  
    
Serial.print("* Drawing:page 3\r\n");     
      Myoled.Paint_DrawString_EN(10, 0, "Text Demo", FONT16, BLUE,BLACK);
      Myoled.Paint_DrawNum(20, 30, "123.4567", FONT12, 2, RED, BLACK); 
      Myoled.Paint_DrawString_EN(20, 60,"123.4567", FONT12, BROWN, BLACK);
      Myoled.Paint_DrawString_EN(15, 80,"  Fox ", FONT24 , BLACK, RED);
      Myoled.driverdelay_ms(3000);    
    Myoled.rgb_Clear();   
    
Serial.print("* Drawing:page 4\r\n");
    Myoled.rgb_Display_Part(gImage_1in5_rgb, 16, 16, 112, 112); // image is 90 degrees
    Myoled.Paint_DrawString_EN(32, 94, "Phone Home", FONT12, BLACK,TRANSPARANT);
    Myoled.Paint_DrawString_EN(31, 93, "Phone Home", FONT12, ORANGE,TRANSPARANT);
    Myoled.driverdelay_ms(3000);    
    Myoled.rgb_Clear();  
  }   
}

void loop() {

}
