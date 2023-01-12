/*

Demo for use of the OLED_Driver library
Demo 3 - TTF font

(C) 2023 Jay Fox

*/

#include <OLED_Driver.h>    // Arduino library for oled 1.5" RGB  WaveShare
#include "ImageData.h"

//
//Defines
//
#define DEBUG_X 1  // Debug info for messages
//#define DEBUG_XX 1  // Debug info for stream data
#define VERSION "1.1.0"               // Software verson nr


//
//Globals
//
OLED_Driver Myoled;
//
//SETUP
//
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
  Myoled.rgb_Clear(DARKER_GRAY);
// Create a new image size
 #if DEBUG_X
  Serial.println("* Oled Intialized\r\n");
#endif 
  
} // End SETUP



void loop() {
uint8_t t=0;
long u=0;
char message[32]="Ohm Meter";
uint16_t R_color[12]={BLACK,BROWN,RED,ORANGE,YELLOW,GREEN,MARINE_BLUE,VIOLET,GRAY,WHITE,GOLD,SILVER};

Myoled.rgb_Set_Block(0,30,128,70,BLACK );

sprintf(message,"Ohm Meter");
Myoled.set_font(&Arcon24);Myoled.set_cursor(16,4); t+=Myoled.draw_string(message,YELLOW,DARKER_GRAY,0);

u=random(120,920);
sprintf(message,"%ld", u);
Myoled.set_font(&HeavyNumber36);Myoled.set_cursor(38,32);t+=Myoled.draw_string(message,WHITE,BLACK,2);

sprintf(message,"E12"); 
Myoled.set_font(&Arial16);Myoled.set_cursor(1,32);t+=Myoled.draw_string(message,WHITE,BLACK,1);

sprintf(message,"K~");  // ~ is modified ohm symbol in Arial16 font
Myoled.set_font(&Arial16);Myoled.set_cursor(104,48);t+=Myoled.draw_string(message,WHITE,BLACK,0);

u=random(1200,9200)*100;
sprintf(message,"M: 5%ld @ 10%%", u ); 
Myoled.set_font(&ArialB14);Myoled.set_cursor(4,74);t+=Myoled.draw_string(message,LIGHT_GRAY,DARKER_GRAY,1);

Myoled.rgb_Set_Block(0,92,128,128,BLACK );
Myoled.rgb_Display_Part(resistor,12, 96, 12+RESISTOR_WIDTH, 96+RESISTOR_HEIGHT); 

Myoled.rgb_Set_Block(47,102,52,120,R_color[random(0,9)]);
Myoled.rgb_Set_Block(56,102,61,120,R_color[random(0,9)]);
Myoled.rgb_Set_Block(65,102,70,120,R_color[random(0,9)]);
Myoled.rgb_Set_Block(82,102,87,120,R_color[random(10,1)]);

 #if DEBUG_X
  Serial.print("* Printed characters");  Serial.println(t);
#endif 
  

delay(2000);
}







