/*

Demo for use of the OLED_Driver library

(C) 2022 Jay Fox

*/

#include <OLED_Driver.h>    // Arduino library for oled 1.5" RGB  WaveShare
#include "ImageData.h"      // define spin image array

OLED_Driver Myoled;

void setup() {
Serial.begin(115200);
delay(2000);

Serial.print("* Initialize system...\r\n");
Serial.print("* Oled size: ");Serial.print(RGB_WIDTH);Serial.print("x");Serial.print(RGB_HEIGHT);Serial.println(" pixels.");
Serial.print("* Pins - ChipSelect:");Serial.print(OLED_CS);Serial.print(", Reset:");Serial.print(OLED_RST);Serial.print(", DataCommand:");Serial.println(OLED_DC);

  Myoled.systeminit();  // init IO and SPI serial - see DevConfig.h
  Myoled.rgb_Init();    // Int
  Myoled.driverdelay_ms(500); 

//1.Create a new image size
  UBYTE *BlackImage=NULL; // image structure
Serial.print("* Create new image structure\r\n");
  Myoled.Paint_NewImage(BlackImage, RGB_WIDTH, RGB_HEIGHT, 0, 0xefbe);  // rotation 0 - for all drawing functions - NOT for image dump
  Myoled.Paint_SetScale(65);  // RGB resolution: 2,4,16,65


}

void loop() {

   
Myoled.rgb_Clear(); 
Myoled.Paint_DrawString_EN(16, 96, "Loading..", FONT16, BLACK,0xefbe);
for(int t=0;t<6;++t){
    for (int i=0;i<IPICT;++i){
    Myoled.rgb_Display_Part(&spin[15-i][0], 40, 40, 40+ISIZEX, 40+ISIZEY); // image is 90 degrees
    }    
  }

Myoled.rgb_Display_Part(&spin[16][0], 40, 40, 40+ISIZEX, 40+ISIZEY); // image is 90 degrees
Myoled.Paint_DrawString_EN(16, 96, " Ready ! ", FONT16, RED,0xefbe);
Myoled.driverdelay_ms(2000);    
  
}
