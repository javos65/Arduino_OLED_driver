/*

Demo for use of the OLED_Driver library

(C) 2022 Jay Fox

*/

#include <OLED_Driver.h>    // Arduino library for oled 1.5" RGB  WaveShare
#include "ImageData.h"      // define spin image array

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
  Myoled.rgb_Clear(0xefbe);
// Create a new image size
 #if DEBUG_X
  Serial.println("* Oled Intialized\r\n");
#endif 

}

void loop() {
char message[64];
int t=0;
   
Myoled.rgb_Clear(0xefbe); 
sprintf(message,"Loading..");
Myoled.set_font(&ArialI16);Myoled.set_cursor(36,96); t+=Myoled.draw_string(message,BLACK,0xefbe,0);
for(int t=0;t<10;++t){
    for (int i=0;i<IPICT;++i){
    Myoled.rgb_Display_Part(&spin[15-i][0], 40, 40, 40+ISIZEX, 40+ISIZEY); 
    delay(10);
    }    
  }

Myoled.rgb_Display_Part(&spin[16][0], 40, 40, 40+ISIZEX, 40+ISIZEY); 
sprintf(message," Ready !!");
Myoled.set_font(&ArialI16);Myoled.set_cursor(36,96); t+=Myoled.draw_string(message,DARK_RED,0xefbe,0); 
  delay(2000);
}
