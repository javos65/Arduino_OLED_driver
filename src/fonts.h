	
#ifndef __FONTS_H
#define __FONTS_H

/*
#define SEGMENTNUMBER56     &SegmentNumber56
#define FATREGULAR32        &Fatregular32
#define HEAVYNUMBER36       &HeavyNumber36
#define ARCON24             &Arcon24
#define ARCON16             &Arcon16
#define ARIALI16            &ArialI16   // italic
#define ARIAL16             &Arial16
#define ARIALB14            &ArialB14   // Bold
#define COURIER12           &Courier12
*/




/** Describes the properties of a glyph. */
typedef struct {
    uint8_t w_px; 
    uint16_t glyph_index;
} lv_font_glyph_dsc_t;

/** Describe the properties of a font*/
typedef struct  {
    uint8_t unicode_first; 
    uint8_t unicode_last;
    uint8_t h_px;           	        /*Font height in pixels*/
    const uint8_t *glyph_bitmap; 	    /*Bitmap of glyphs*/
    const lv_font_glyph_dsc_t *glyph_dsc;   /*Description of glyphs*/
    uint8_t glyph_cnt;            		/*Number of glyphs in the font*/
    uint8_t bpp;				              /*Bit per pixel*/
    uint8_t monospace;              	/*Fix width (0: if not used)*/
} lv_font_t;

#endif // __FONTS_H 