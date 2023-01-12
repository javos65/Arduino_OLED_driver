#include <stdint.h>
#include "fonts.h"


/***********************************************************************************
 * Courier Prime Sans Bold.ttf 12 px Font in U+0020 ( ) .. U+007e (~)  range with 2 bpp
***********************************************************************************/

/*Store the image of the letters (glyph)*/
const uint8_t Courier12_glyph_bitmap[] = 
{
  /*Unicode: U+0020 ( ) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0021 (!) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0x50,  //++ 
  0x00,  //.. 
  0x00,  //.. 
  0xa0,  //%% 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0022 (") , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x35, 0xc0,  //.@++@. 
  0x35, 0xc0,  //.@++@. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0023 (#) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0c, 0xc0,  //..@.@. 
  0x7f, 0xe0,  //+@@@@% 
  0x2a, 0x80,  //.%%%%. 
  0xbf, 0xd0,  //%@@@@+ 
  0x33, 0x00,  //.@.@.. 
  0x23, 0x00,  //.%.@.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0024 ($) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x05, 0x00,  //..++.. 
  0x1f, 0x40,  //.+@@+. 
  0x3f, 0xc0,  //.@@@@. 
  0x3f, 0x40,  //.@@@+. 
  0x0b, 0xc0,  //..%@@. 
  0x3f, 0xc0,  //.@@@@. 
  0x1f, 0x40,  //.+@@+. 
  0x05, 0x00,  //..++.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0025 (%) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x78, 0x00,  //+@%... 
  0xb8, 0xd0,  //%@%.@+ 
  0x07, 0x00,  //..+@.. 
  0x1e, 0xd0,  //.+@%@+ 
  0x73, 0xa0,  //+@.@%% 
  0x01, 0xd0,  //...+@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0026 (&) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x40,  //.+@@+. 
  0x39, 0x00,  //.@%+.. 
  0x28, 0x40,  //.%%.+. 
  0x3f, 0xc0,  //.@@@@. 
  0x77, 0xc0,  //+@+@@. 
  0x2e, 0xc0,  //.%@%@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0027 (') , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0xa0,  //%% 
  0xa0,  //%% 
  0x50,  //++ 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0028 (() , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x09,  //..%+ 
  0x3c,  //.@@. 
  0x70,  //+@.. 
  0xa0,  //%%.. 
  0x90,  //%+.. 
  0xa0,  //%%.. 
  0x70,  //+@.. 
  0x2c,  //.%@. 
  0x09,  //..%+ 
  0x00,  //.... 


  /*Unicode: U+0029 ()) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x60,  //+%.. 
  0x3c,  //.@@. 
  0x0d,  //..@+ 
  0x0a,  //..%% 
  0x06,  //..+% 
  0x0a,  //..%% 
  0x0d,  //..@+ 
  0x38,  //.@%. 
  0x60,  //+%.. 
  0x00,  //.... 


  /*Unicode: U+002a (*) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x05, 0x00,  //..++.. 
  0x3a, 0xc0,  //.@%%@. 
  0x0f, 0x00,  //..@@.. 
  0x1a, 0x40,  //.+%%+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+002b (+) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x3f, 0xc0,  //.@@@@. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+002c (,) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x38,  //.@% 
  0x30,  //.@. 
  0x20,  //.%. 
  0x00,  //... 


  /*Unicode: U+002d (-) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+002e (.) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0xa0,  //%% 
  0xa0,  //%% 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+002f (/) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x40,  //....+. 
  0x00, 0xc0,  //....@. 
  0x02, 0x80,  //...%%. 
  0x03, 0x40,  //...@+. 
  0x07, 0x00,  //..+@.. 
  0x0a, 0x00,  //..%%.. 
  0x0c, 0x00,  //..@... 
  0x1c, 0x00,  //.+@... 
  0x34, 0x00,  //.@+... 
  0x30, 0x00,  //.@.... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0030 (0) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x40,  //.+@@+. 
  0x35, 0xc0,  //.@++@. 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0031 (1) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0a, 0x00,  //..%%.. 
  0x3e, 0x00,  //.@@%.. 
  0x06, 0x00,  //..+%.. 
  0x06, 0x00,  //..+%.. 
  0x0b, 0x00,  //..%@.. 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0032 (2) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x40,  //.%@@+. 
  0x16, 0xc0,  //.++%@. 
  0x02, 0xc0,  //...%@. 
  0x07, 0x00,  //..+@.. 
  0x1d, 0x00,  //.+@+.. 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0033 (3) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x3f, 0x40,  //.@@@+ 
  0x16, 0xc0,  //.++%@ 
  0x0f, 0x40,  //..@@+ 
  0x02, 0xc0,  //...%@ 
  0x16, 0xc0,  //.++%@ 
  0x3f, 0x40,  //.@@@+ 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 


  /*Unicode: U+0034 (4) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x03, 0x40,  //...@+. 
  0x0f, 0x40,  //..@@+. 
  0x27, 0x40,  //.%+@+. 
  0x7f, 0xd0,  //+@@@@+ 
  0x03, 0x40,  //...@+. 
  0x03, 0x40,  //...@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0035 (5) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x34, 0x00,  //.@+... 
  0x3f, 0x40,  //.@@@+. 
  0x16, 0xc0,  //.++%@. 
  0x16, 0xc0,  //.++%@. 
  0x2f, 0x40,  //.%@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0036 (6) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x07, 0xc0,  //..+@@. 
  0x2d, 0x00,  //.%@+.. 
  0x3f, 0x80,  //.@@@%. 
  0x35, 0xc0,  //.@++@. 
  0x39, 0xc0,  //.@%+@. 
  0x1f, 0x40,  //.+@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0037 (7) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x02, 0xc0,  //...%@. 
  0x03, 0x40,  //...@+. 
  0x07, 0x00,  //..+@.. 
  0x0a, 0x00,  //..%%.. 
  0x0c, 0x00,  //..@... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0038 (8) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x40,  //.+@@+. 
  0x3a, 0xc0,  //.@%%@. 
  0x2f, 0x40,  //.%@@+. 
  0x35, 0xc0,  //.@++@. 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0039 (9) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x40,  //.%@@+. 
  0x36, 0xc0,  //.@+%@. 
  0x3f, 0xc0,  //.@@@@. 
  0x01, 0xc0,  //...+@. 
  0x07, 0x80,  //..+@%. 
  0x2e, 0x00,  //.%@%.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+003a (:) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0xe0,  //@% 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0xf0,  //@@ 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+003b (;) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x38,  //.@% 
  0x00,  //... 
  0x00,  //... 
  0x2c,  //.%@ 
  0x34,  //.@+ 
  0x30,  //.@. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+003c (<) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x01, 0xc0,  //...+@. 
  0x1f, 0x40,  //.+@@+. 
  0x78, 0x00,  //+@%... 
  0x1f, 0x40,  //.+@@+. 
  0x01, 0xc0,  //...+@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+003d (=) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+003e (>) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x34, 0x00,  //.@+... 
  0x1f, 0x40,  //.+@@+. 
  0x02, 0xd0,  //...%@+ 
  0x1f, 0x40,  //.+@@+. 
  0x34, 0x00,  //.@+... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+003f (?) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x7d,  //+@@+ 
  0x5b,  //++%@ 
  0x0b,  //..%@ 
  0x2d,  //.%@+ 
  0x24,  //.%+. 
  0x00,  //.... 
  0x38,  //.@%. 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0040 (@) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x80,  //.+@@%. 
  0x7f, 0xd0,  //+@@@@+ 
  0x9e, 0x60,  //%+@%+% 
  0xdb, 0x60,  //@+%@+% 
  0xae, 0xc0,  //%%@%@. 
  0x3f, 0x00,  //.@@@.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0041 (A) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0a, 0x00,  //..%%.. 
  0x0f, 0x00,  //..@@.. 
  0x1f, 0x40,  //.+@@+. 
  0x35, 0xc0,  //.@++@. 
  0x3f, 0xc0,  //.@@@@. 
  0xb0, 0xd0,  //%@..@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0042 (B) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0x80,  //.@@@%. 
  0x35, 0xc0,  //.@++@. 
  0x3f, 0x80,  //.@@@%. 
  0x35, 0xd0,  //.@++@+ 
  0x35, 0xd0,  //.@++@+ 
  0x3f, 0x80,  //.@@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0043 (C) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0xc0,  //.+@@@. 
  0x38, 0x40,  //.@%.+. 
  0x70, 0x00,  //+@.... 
  0x70, 0x00,  //+@.... 
  0x38, 0x40,  //.@%.+. 
  0x1f, 0xc0,  //.+@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0044 (D) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0x40,  //.@@@+. 
  0x31, 0xc0,  //.@.+@. 
  0x30, 0xd0,  //.@..@+ 
  0x30, 0xd0,  //.@..@+ 
  0x31, 0xc0,  //.@.+@. 
  0x3f, 0x40,  //.@@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0045 (E) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x34, 0x00,  //.@+... 
  0x3f, 0x00,  //.@@@.. 
  0x34, 0x00,  //.@+... 
  0x34, 0x00,  //.@+... 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0046 (F) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0xff, 0x00,  //@@@@. 
  0xd0, 0x00,  //@+... 
  0xd0, 0x00,  //@+... 
  0xfe, 0x00,  //@@@%. 
  0xd0, 0x00,  //@+... 
  0xd0, 0x00,  //@+... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 


  /*Unicode: U+0047 (G) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0xc0,  //.+@@@. 
  0x75, 0x40,  //+@+++. 
  0xb3, 0xd0,  //%@.@@+ 
  0xb0, 0xd0,  //%@..@+ 
  0x75, 0xd0,  //+@++@+ 
  0x1f, 0x80,  //.+@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0048 (H) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x7f, 0xd0,  //+@@@@+ 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0049 (I) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x3f, 0xc0,  //.@@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+004a (J) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x1f, 0xc0,  //.+@@@ 
  0x02, 0xc0,  //...%@ 
  0x01, 0xc0,  //...+@ 
  0x01, 0xc0,  //...+@ 
  0x26, 0x80,  //.%+%% 
  0x2f, 0x40,  //.%@@+ 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 


  /*Unicode: U+004b (K) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0xc0,  //.@..@. 
  0x33, 0x80,  //.@.@%. 
  0x3f, 0x00,  //.@@@.. 
  0x3f, 0x00,  //.@@@.. 
  0x32, 0xc0,  //.@.%@. 
  0x30, 0xd0,  //.@..@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+004c (L) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0xc0, 0x00,  //@.... 
  0xc0, 0x00,  //@.... 
  0xc0, 0x00,  //@.... 
  0xc0, 0x00,  //@.... 
  0xd0, 0x00,  //@+... 
  0xff, 0x00,  //@@@@. 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 


  /*Unicode: U+004d (M) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x75, 0xd0,  //+@++@+ 
  0x7f, 0xd0,  //+@@@@+ 
  0x6f, 0xd0,  //+%@@@+ 
  0x60, 0x90,  //+%..%+ 
  0x60, 0x90,  //+%..%+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+004e (N) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x7c, 0xd0,  //+@@.@+ 
  0x7d, 0xd0,  //+@@+@+ 
  0x77, 0xd0,  //+@+@@+ 
  0x72, 0xd0,  //+@.%@+ 
  0x70, 0xd0,  //+@..@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+004f (O) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x80,  //.%@@%. 
  0x75, 0xd0,  //+@++@+ 
  0xa0, 0xa0,  //%%..%% 
  0xa0, 0xa0,  //%%..%% 
  0x75, 0xd0,  //+@++@+ 
  0x2f, 0x80,  //.%@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0050 (P) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0x80,  //.@@@%. 
  0x35, 0xd0,  //.@++@+ 
  0x30, 0xd0,  //.@..@+ 
  0x3f, 0xc0,  //.@@@@. 
  0x34, 0x00,  //.@+... 
  0x30, 0x00,  //.@.... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0051 (Q) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x80,  //.%@@%. 
  0x75, 0xd0,  //+@++@+ 
  0xa0, 0xa0,  //%%..%% 
  0xa1, 0xa0,  //%%.+%% 
  0x77, 0xd0,  //+@+@@+ 
  0x2f, 0xc0,  //.%@@@. 
  0x00, 0xc0,  //....@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0052 (R) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0x40,  //.@@@+. 
  0x35, 0xc0,  //.@++@. 
  0x30, 0xc0,  //.@..@. 
  0x3f, 0x80,  //.@@@%. 
  0x37, 0x80,  //.@+@%. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0053 (S) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x80,  //.%@@%. 
  0x35, 0x40,  //.@+++. 
  0x3e, 0x00,  //.@@%.. 
  0x06, 0xc0,  //..+%@. 
  0x15, 0xc0,  //.+++@. 
  0x2f, 0x80,  //.%@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0054 (T) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x7f, 0xd0,  //+@@@@+ 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0055 (U) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0056 (V) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x60, 0x90,  //+%..%+ 
  0x30, 0xd0,  //.@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x0f, 0x00,  //..@@.. 
  0x0a, 0x00,  //..%%.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0057 (W) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x90, 0x60,  //%+..+% 
  0xa0, 0xa0,  //%%..%% 
  0x6a, 0x90,  //+%%%%+ 
  0x7f, 0xd0,  //+@@@@+ 
  0x7a, 0xd0,  //+@%%@+ 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0058 (X) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0xc0,  //.@..@. 
  0x3a, 0xc0,  //.@%%@. 
  0x0f, 0x00,  //..@@.. 
  0x0f, 0x00,  //..@@.. 
  0x3a, 0xc0,  //.@%%@. 
  0x70, 0xd0,  //+@..@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0059 (Y) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x0f, 0x00,  //..@@.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+005a (Z) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x03, 0x80,  //...@%. 
  0x07, 0x00,  //..+@.. 
  0x0d, 0x00,  //..@+.. 
  0x3c, 0x00,  //.@@... 
  0x7f, 0xd0,  //+@@@@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+005b ([) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0xbd,  //%@@+ 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xa0,  //%%.. 
  0xbd,  //%@@+ 
  0x00,  //.... 


  /*Unicode: U+005c (\) , Width: 6 */
  0x00, 0x00,  //...... 
  0x10, 0x00,  //.+.... 
  0x30, 0x00,  //.@.... 
  0x28, 0x00,  //.%%... 
  0x1c, 0x00,  //.+@... 
  0x0d, 0x00,  //..@+.. 
  0x0a, 0x00,  //..%%.. 
  0x03, 0x00,  //...@.. 
  0x03, 0x40,  //...@+. 
  0x01, 0xc0,  //...+@. 
  0x00, 0xc0,  //....@. 
  0x00, 0x00,  //...... 


  /*Unicode: U+005d (]) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x7e,  //+@@% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x0a,  //..%% 
  0x7e,  //+@@% 
  0x00,  //.... 


  /*Unicode: U+005e (^) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x28,  //.%%. 
  0x3c,  //.@@. 
  0xaa,  //%%%% 
  0xc3,  //@..@ 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+005f (_) , Width: 7 */
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0x00, 0x00,  //....... 
  0xff, 0xf0,  //@@@@@@. 
  0x00, 0x00,  //....... 


  /*Unicode: U+0060 (`) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x60,  //+%. 
  0x2c,  //.%@ 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0061 (a) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x40,  //.%@@+. 
  0x15, 0xc0,  //.+++@. 
  0x3f, 0xc0,  //.@@@@. 
  0x76, 0xc0,  //+@+%@. 
  0x2e, 0xc0,  //.%@%@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0062 (b) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0x00,  //.@.... 
  0x30, 0x00,  //.@.... 
  0x3b, 0x80,  //.@%@%. 
  0x39, 0xc0,  //.@%+@. 
  0x30, 0xd0,  //.@..@+ 
  0x39, 0xc0,  //.@%+@. 
  0x3b, 0x80,  //.@%@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0063 (c) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x80,  //.+@@%. 
  0x39, 0x80,  //.@%+%. 
  0x70, 0x00,  //+@.... 
  0x39, 0x80,  //.@%+%. 
  0x1f, 0x80,  //.+@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0064 (d) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0xc0,  //....@. 
  0x00, 0xc0,  //....@. 
  0x2e, 0xc0,  //.%@%@. 
  0x36, 0xc0,  //.@+%@. 
  0x70, 0xc0,  //+@..@. 
  0x36, 0xc0,  //.@+%@. 
  0x2e, 0xc0,  //.%@%@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0065 (e) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x40,  //.+@@+. 
  0x35, 0xc0,  //.@++@. 
  0x7f, 0xd0,  //+@@@@+ 
  0x39, 0x80,  //.@%+%. 
  0x1f, 0xc0,  //.+@@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0066 (f) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0b, 0xd0,  //..%@@+ 
  0x0d, 0x00,  //..@+.. 
  0x3f, 0xc0,  //.@@@@. 
  0x0d, 0x00,  //..@+.. 
  0x0c, 0x00,  //..@... 
  0x0c, 0x00,  //..@... 
  0x0c, 0x00,  //..@... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0067 (g) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2e, 0xc0,  //.%@%@. 
  0x36, 0xc0,  //.@+%@. 
  0x70, 0xc0,  //+@..@. 
  0x36, 0xc0,  //.@+%@. 
  0x2f, 0xc0,  //.%@@@. 
  0x11, 0xc0,  //.+.+@. 
  0x3f, 0x40,  //.@@@+. 
  0x00, 0x00,  //...... 


  /*Unicode: U+0068 (h) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0x00,  //.@.... 
  0x30, 0x00,  //.@.... 
  0x3b, 0x80,  //.@%@%. 
  0x39, 0xc0,  //.@%+@. 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0069 (i) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x0a, 0x00,  //..%%.. 
  0x00, 0x00,  //...... 
  0x3e, 0x00,  //.@@%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x3f, 0xd0,  //.@@@@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+006a (j) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x02, 0x40,  //...%+ 
  0x00, 0x00,  //..... 
  0x3f, 0x40,  //.@@@+ 
  0x03, 0x40,  //...@+ 
  0x02, 0x40,  //...%+ 
  0x02, 0x40,  //...%+ 
  0x02, 0x40,  //...%+ 
  0x27, 0x40,  //.%+@+ 
  0x2f, 0x00,  //.%@@. 
  0x00, 0x00,  //..... 


  /*Unicode: U+006b (k) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0x00,  //.@.... 
  0x30, 0x00,  //.@.... 
  0x31, 0xc0,  //.@.+@. 
  0x3b, 0x80,  //.@%@%. 
  0x3f, 0x00,  //.@@@.. 
  0x37, 0xc0,  //.@+@@. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+006c (l) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3e, 0x00,  //.@@%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x0a, 0x00,  //..%%.. 
  0x3f, 0xd0,  //.@@@@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+006d (m) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0xad, 0xd0,  //%%@+@+ 
  0xbb, 0xa0,  //%@%@%% 
  0xaa, 0xa0,  //%%%%%% 
  0xaa, 0xa0,  //%%%%%% 
  0xaa, 0xa0,  //%%%%%% 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+006e (n) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x37, 0x80,  //.@+@%. 
  0x39, 0xc0,  //.@%+@. 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+006f (o) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1f, 0x40,  //.+@@+. 
  0x35, 0xc0,  //.@++@. 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x1f, 0x40,  //.+@@+. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0070 (p) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3b, 0x80,  //.@%@%. 
  0x39, 0xc0,  //.@%+@. 
  0x30, 0xd0,  //.@..@+ 
  0x39, 0xc0,  //.@%+@. 
  0x3b, 0x80,  //.@%@%. 
  0x30, 0x00,  //.@.... 
  0x30, 0x00,  //.@.... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0071 (q) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2e, 0xc0,  //.%@%@. 
  0x36, 0xc0,  //.@+%@. 
  0x70, 0xc0,  //+@..@. 
  0x36, 0xc0,  //.@+%@. 
  0x2e, 0xc0,  //.%@%@. 
  0x00, 0xc0,  //....@. 
  0x00, 0xc0,  //....@. 
  0x00, 0x00,  //...... 


  /*Unicode: U+0072 (r) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x9f, 0x00,  //%+@@. 
  0xb4, 0x00,  //%@+.. 
  0xa0, 0x00,  //%%... 
  0x90, 0x00,  //%+... 
  0x90, 0x00,  //%+... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 


  /*Unicode: U+0073 (s) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x2f, 0x80,  //.%@@%. 
  0x35, 0x40,  //.@+++. 
  0x2f, 0x80,  //.%@@%. 
  0x11, 0xc0,  //.+.+@. 
  0x2f, 0x80,  //.%@@%. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0074 (t) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x1c, 0x00,  //.+@... 
  0x7f, 0xc0,  //+@@@@. 
  0x1c, 0x00,  //.+@... 
  0x1c, 0x00,  //.+@... 
  0x0d, 0x80,  //..@+%. 
  0x0b, 0xc0,  //..%@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0075 (u) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x30, 0xc0,  //.@..@. 
  0x36, 0xc0,  //.@+%@. 
  0x2d, 0xc0,  //.%@+@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0076 (v) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x2a, 0x80,  //.%%%%. 
  0x0f, 0x00,  //..@@.. 
  0x0f, 0x00,  //..@@.. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0077 (w) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x90, 0x60,  //%+..+% 
  0xaa, 0xa0,  //%%%%%% 
  0x7f, 0xd0,  //+@@@@+ 
  0x3b, 0xc0,  //.@%@@. 
  0x35, 0xc0,  //.@++@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0078 (x) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x30, 0xc0,  //.@..@. 
  0x2f, 0x80,  //.%@@%. 
  0x0f, 0x00,  //..@@.. 
  0x2f, 0x80,  //.%@@%. 
  0x30, 0xc0,  //.@..@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+0079 (y) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x70, 0xd0,  //+@..@+ 
  0x35, 0xc0,  //.@++@. 
  0x2a, 0x80,  //.%%%%. 
  0x0f, 0x00,  //..@@.. 
  0x0f, 0x00,  //..@@.. 
  0x0d, 0x00,  //..@+.. 
  0x1c, 0x00,  //.+@... 
  0x00, 0x00,  //...... 


  /*Unicode: U+007a (z) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3f, 0xc0,  //.@@@@. 
  0x07, 0x80,  //..+@%. 
  0x0f, 0x00,  //..@@.. 
  0x2d, 0x00,  //.%@+.. 
  0x7f, 0xd0,  //+@@@@+ 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


  /*Unicode: U+007b ({) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0x07, 0xc0,  //..+@@ 
  0x0e, 0x00,  //..@%. 
  0x0d, 0x00,  //..@+. 
  0x0d, 0x00,  //..@+. 
  0x38, 0x00,  //.@%.. 
  0x1d, 0x00,  //.+@+. 
  0x0d, 0x00,  //..@+. 
  0x0e, 0x00,  //..@%. 
  0x07, 0xc0,  //..+@@ 
  0x00, 0x00,  //..... 


  /*Unicode: U+007c (|) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0xa0,  //%% 
  0x00,  //.. 


  /*Unicode: U+007d (}) , Width: 5 */
  0x00, 0x00,  //..... 
  0x00, 0x00,  //..... 
  0xf0, 0x00,  //@@... 
  0x2c, 0x00,  //.%@.. 
  0x1c, 0x00,  //.+@.. 
  0x1c, 0x00,  //.+@.. 
  0x0b, 0x00,  //..%@. 
  0x1d, 0x00,  //.+@+. 
  0x1c, 0x00,  //.+@.. 
  0x2c, 0x00,  //.%@.. 
  0xf4, 0x00,  //@@+.. 
  0x00, 0x00,  //..... 


  /*Unicode: U+007e (~) , Width: 6 */
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x3c, 0x80,  //.@@.%. 
  0x27, 0xc0,  //.%+@@. 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 
  0x00, 0x00,  //...... 


};


/*Store the glyph descriptions*/
static const lv_font_glyph_dsc_t Courier12_glyph_dsc[] = 
{
  {.w_px = 4,	.glyph_index = 0},	/*Unicode: U+0020 ( )*/
  {.w_px = 2,	.glyph_index = 12},	/*Unicode: U+0021 (!)*/
  {.w_px = 6,	.glyph_index = 24},	/*Unicode: U+0022 (")*/
  {.w_px = 6,	.glyph_index = 48},	/*Unicode: U+0023 (#)*/
  {.w_px = 6,	.glyph_index = 72},	/*Unicode: U+0024 ($)*/
  {.w_px = 6,	.glyph_index = 96},	/*Unicode: U+0025 (%)*/
  {.w_px = 6,	.glyph_index = 120},	/*Unicode: U+0026 (&)*/
  {.w_px = 2,	.glyph_index = 144},	/*Unicode: U+0027 (')*/
  {.w_px = 4,	.glyph_index = 156},	/*Unicode: U+0028 (()*/
  {.w_px = 4,	.glyph_index = 168},	/*Unicode: U+0029 ())*/
  {.w_px = 6,	.glyph_index = 180},	/*Unicode: U+002a (*)*/
  {.w_px = 6,	.glyph_index = 204},	/*Unicode: U+002b (+)*/
  {.w_px = 3,	.glyph_index = 228},	/*Unicode: U+002c (,)*/
  {.w_px = 6,	.glyph_index = 240},	/*Unicode: U+002d (-)*/
  {.w_px = 2,	.glyph_index = 264},	/*Unicode: U+002e (.)*/
  {.w_px = 6,	.glyph_index = 276},	/*Unicode: U+002f (/)*/
  {.w_px = 6,	.glyph_index = 300},	/*Unicode: U+0030 (0)*/
  {.w_px = 6,	.glyph_index = 324},	/*Unicode: U+0031 (1)*/
  {.w_px = 6,	.glyph_index = 348},	/*Unicode: U+0032 (2)*/
  {.w_px = 5,	.glyph_index = 372},	/*Unicode: U+0033 (3)*/
  {.w_px = 6,	.glyph_index = 396},	/*Unicode: U+0034 (4)*/
  {.w_px = 6,	.glyph_index = 420},	/*Unicode: U+0035 (5)*/
  {.w_px = 6,	.glyph_index = 444},	/*Unicode: U+0036 (6)*/
  {.w_px = 6,	.glyph_index = 468},	/*Unicode: U+0037 (7)*/
  {.w_px = 6,	.glyph_index = 492},	/*Unicode: U+0038 (8)*/
  {.w_px = 6,	.glyph_index = 516},	/*Unicode: U+0039 (9)*/
  {.w_px = 2,	.glyph_index = 540},	/*Unicode: U+003a (:)*/
  {.w_px = 3,	.glyph_index = 552},	/*Unicode: U+003b (;)*/
  {.w_px = 6,	.glyph_index = 564},	/*Unicode: U+003c (<)*/
  {.w_px = 6,	.glyph_index = 588},	/*Unicode: U+003d (=)*/
  {.w_px = 6,	.glyph_index = 612},	/*Unicode: U+003e (>)*/
  {.w_px = 4,	.glyph_index = 636},	/*Unicode: U+003f (?)*/
  {.w_px = 6,	.glyph_index = 648},	/*Unicode: U+0040 (@)*/
  {.w_px = 6,	.glyph_index = 672},	/*Unicode: U+0041 (A)*/
  {.w_px = 6,	.glyph_index = 696},	/*Unicode: U+0042 (B)*/
  {.w_px = 6,	.glyph_index = 720},	/*Unicode: U+0043 (C)*/
  {.w_px = 6,	.glyph_index = 744},	/*Unicode: U+0044 (D)*/
  {.w_px = 6,	.glyph_index = 768},	/*Unicode: U+0045 (E)*/
  {.w_px = 5,	.glyph_index = 792},	/*Unicode: U+0046 (F)*/
  {.w_px = 6,	.glyph_index = 816},	/*Unicode: U+0047 (G)*/
  {.w_px = 6,	.glyph_index = 840},	/*Unicode: U+0048 (H)*/
  {.w_px = 6,	.glyph_index = 864},	/*Unicode: U+0049 (I)*/
  {.w_px = 5,	.glyph_index = 888},	/*Unicode: U+004a (J)*/
  {.w_px = 6,	.glyph_index = 912},	/*Unicode: U+004b (K)*/
  {.w_px = 5,	.glyph_index = 936},	/*Unicode: U+004c (L)*/
  {.w_px = 6,	.glyph_index = 960},	/*Unicode: U+004d (M)*/
  {.w_px = 6,	.glyph_index = 984},	/*Unicode: U+004e (N)*/
  {.w_px = 6,	.glyph_index = 1008},	/*Unicode: U+004f (O)*/
  {.w_px = 6,	.glyph_index = 1032},	/*Unicode: U+0050 (P)*/
  {.w_px = 6,	.glyph_index = 1056},	/*Unicode: U+0051 (Q)*/
  {.w_px = 6,	.glyph_index = 1080},	/*Unicode: U+0052 (R)*/
  {.w_px = 6,	.glyph_index = 1104},	/*Unicode: U+0053 (S)*/
  {.w_px = 6,	.glyph_index = 1128},	/*Unicode: U+0054 (T)*/
  {.w_px = 6,	.glyph_index = 1152},	/*Unicode: U+0055 (U)*/
  {.w_px = 6,	.glyph_index = 1176},	/*Unicode: U+0056 (V)*/
  {.w_px = 6,	.glyph_index = 1200},	/*Unicode: U+0057 (W)*/
  {.w_px = 6,	.glyph_index = 1224},	/*Unicode: U+0058 (X)*/
  {.w_px = 6,	.glyph_index = 1248},	/*Unicode: U+0059 (Y)*/
  {.w_px = 6,	.glyph_index = 1272},	/*Unicode: U+005a (Z)*/
  {.w_px = 4,	.glyph_index = 1296},	/*Unicode: U+005b ([)*/
  {.w_px = 6,	.glyph_index = 1308},	/*Unicode: U+005c (\)*/
  {.w_px = 4,	.glyph_index = 1332},	/*Unicode: U+005d (])*/
  {.w_px = 4,	.glyph_index = 1344},	/*Unicode: U+005e (^)*/
  {.w_px = 7,	.glyph_index = 1356},	/*Unicode: U+005f (_)*/
  {.w_px = 3,	.glyph_index = 1380},	/*Unicode: U+0060 (`)*/
  {.w_px = 6,	.glyph_index = 1392},	/*Unicode: U+0061 (a)*/
  {.w_px = 6,	.glyph_index = 1416},	/*Unicode: U+0062 (b)*/
  {.w_px = 6,	.glyph_index = 1440},	/*Unicode: U+0063 (c)*/
  {.w_px = 6,	.glyph_index = 1464},	/*Unicode: U+0064 (d)*/
  {.w_px = 6,	.glyph_index = 1488},	/*Unicode: U+0065 (e)*/
  {.w_px = 6,	.glyph_index = 1512},	/*Unicode: U+0066 (f)*/
  {.w_px = 6,	.glyph_index = 1536},	/*Unicode: U+0067 (g)*/
  {.w_px = 6,	.glyph_index = 1560},	/*Unicode: U+0068 (h)*/
  {.w_px = 6,	.glyph_index = 1584},	/*Unicode: U+0069 (i)*/
  {.w_px = 5,	.glyph_index = 1608},	/*Unicode: U+006a (j)*/
  {.w_px = 6,	.glyph_index = 1632},	/*Unicode: U+006b (k)*/
  {.w_px = 6,	.glyph_index = 1656},	/*Unicode: U+006c (l)*/
  {.w_px = 6,	.glyph_index = 1680},	/*Unicode: U+006d (m)*/
  {.w_px = 6,	.glyph_index = 1704},	/*Unicode: U+006e (n)*/
  {.w_px = 6,	.glyph_index = 1728},	/*Unicode: U+006f (o)*/
  {.w_px = 6,	.glyph_index = 1752},	/*Unicode: U+0070 (p)*/
  {.w_px = 6,	.glyph_index = 1776},	/*Unicode: U+0071 (q)*/
  {.w_px = 5,	.glyph_index = 1800},	/*Unicode: U+0072 (r)*/
  {.w_px = 6,	.glyph_index = 1824},	/*Unicode: U+0073 (s)*/
  {.w_px = 6,	.glyph_index = 1848},	/*Unicode: U+0074 (t)*/
  {.w_px = 6,	.glyph_index = 1872},	/*Unicode: U+0075 (u)*/
  {.w_px = 6,	.glyph_index = 1896},	/*Unicode: U+0076 (v)*/
  {.w_px = 6,	.glyph_index = 1920},	/*Unicode: U+0077 (w)*/
  {.w_px = 6,	.glyph_index = 1944},	/*Unicode: U+0078 (x)*/
  {.w_px = 6,	.glyph_index = 1968},	/*Unicode: U+0079 (y)*/
  {.w_px = 6,	.glyph_index = 1992},	/*Unicode: U+007a (z)*/
  {.w_px = 5,	.glyph_index = 2016},	/*Unicode: U+007b ({)*/
  {.w_px = 2,	.glyph_index = 2040},	/*Unicode: U+007c (|)*/
  {.w_px = 5,	.glyph_index = 2052},	/*Unicode: U+007d (})*/
  {.w_px = 6,	.glyph_index = 2076},	/*Unicode: U+007e (~)*/
};

lv_font_t Courier12 = 
{
    .unicode_first = 32,	/*First Unicode letter in this font*/
    .unicode_last = 126,	/*Last Unicode letter in this font*/
    .h_px = 12,				/*Font height in pixels*/
    .glyph_bitmap = Courier12_glyph_bitmap,	/*Bitmap of glyphs*/
    .glyph_dsc = Courier12_glyph_dsc,		/*Description of glyphs*/
    .glyph_cnt = 95,			/*Number of glyphs in the font*/
    .bpp = 2,				/*Bit per pixel*/
    .monospace = 0,				/*Fix width (0: if not used)*/

};