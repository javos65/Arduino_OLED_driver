/*****************************************************************************
* | File      	:   ImageData.h
* | Author      :   Jay Fox
* | Function    :	
*----------------
* |	This version:   V1.0
* | Date        :   2022
* | Info        :
*
#
******************************************************************************/

#ifndef _IMAGEDATA_H_
#define _IMAGEDATA_H_

#define ISIZEX 48
#define ISIZEY 48
#define IPICT 16 // plus one for extra Icon - picture
extern const unsigned char spin[IPICT+1][ISIZEX*ISIZEY*2];   //rotate 90, MSB first

#endif
/* FILE END */
