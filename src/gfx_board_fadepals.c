

#include <gb/gb.h>
#include <gb/cgb.h>

#include "gfx_board_fadepals.h"


// Convert from GIMP export palettes with:
// tools/javascript GIMP export Palette to BGR array converter.html
// or
// https://jsfiddle.net/7rg4yz3f/32/
//
// Use Last 4 (4 colors x R/G/B) sets of source palette

const UINT8 fade_sky_pals[FADE_SKY_PALS_COUNT][FADE2PAL_NUM_PALS * COLORS_PER_PAL * BYTES_PER_COLOR] = {
    // Default blue sky
{
    0x1f, 0x1e, 0x18,
    0x1e, 0x1c, 0x14,
    0x1c, 0x1a, 0x10,
    0x11, 0x0c, 0x00,

    0x0f, 0x1b, 0x09,
    0x0e, 0x18, 0x08,
    0x0c, 0x14, 0x07,
    0x0b, 0x11, 0x06,

    0x0b, 0x13, 0x14,
    0x0a, 0x10, 0x11,
    0x0b, 0x11, 0x06,
    0x08, 0x0d, 0x0e,

    0x1c, 0x1a, 0x10,
    0x1f, 0x1e, 0x18,
    0x1d, 0x1c, 0x13,
    0x03, 0x03, 0x03,
},
{
    // Pale blue green sky
    0x18, 0x1f, 0x17,
    0x15, 0x1e, 0x11,
    0x17, 0x1b, 0x11,
    0x0b, 0x0c, 0x00,

    0x1b, 0x19, 0x0e,
    0x19, 0x16, 0x0d,
    0x17, 0x13, 0x07,
    0x15, 0x10, 0x05,

    0x0f, 0x16, 0x11,
    0x0d, 0x14, 0x0f,
    0x15, 0x11, 0x08,
    0x0b, 0x12, 0x0d,

    0x17, 0x1b, 0x11,
    0x1a, 0x1f, 0x1b,
    0x1a, 0x1d, 0x16,
    0x03, 0x03, 0x03,
},
{
    // Yellowy Orangey Sky
    0x16, 0x1a, 0x1d,
    0x12, 0x19, 0x1d,
    0x10, 0x15, 0x1c,
    0x00, 0x0a, 0x11,

    0x0f, 0x09, 0x1d,
    0x0c, 0x08, 0x18,
    0x0a, 0x07, 0x14,
    0x08, 0x06, 0x12,

    0x14, 0x0b, 0x0d,
    0x11, 0x0a, 0x0c,
    0x08, 0x06, 0x12,
    0x0e, 0x08, 0x09,

    0x10, 0x15, 0x1c,
    0x1b, 0x1d, 0x1f,
    0x12, 0x19, 0x1d,
    0x03, 0x03, 0x03,
},
{
    //2b, Pinkish Sky
    0x1f, 0x17, 0x1e,
    0x1c, 0x10, 0x1f,
    0x15, 0x11, 0x1d,
    0x07, 0x00, 0x0c,

    0x1b, 0x09, 0x15,
    0x18, 0x08, 0x14,
    0x14, 0x07, 0x11,
    0x11, 0x06, 0x0f,

    0x14, 0x12, 0x0b,
    0x11, 0x0f, 0x0a,
    0x11, 0x06, 0x0f,
    0x0e, 0x0d, 0x08,

    0x15, 0x11, 0x1d,
    0x1f, 0x1b, 0x1f,
    0x1d, 0x13, 0x1f,
    0x03, 0x03, 0x03,
},
{
    // Darker purple sky
    0x1f, 0x11, 0x1a,
    0x1d, 0x0c, 0x14,
    0x1c, 0x09, 0x11,
    0x0c, 0x01, 0x0a,

    0x18, 0x14, 0x06,
    0x15, 0x11, 0x07,
    0x11, 0x0e, 0x06,
    0x0e, 0x0b, 0x05,

    0x0a, 0x11, 0x0b,
    0x09, 0x0e, 0x0a,
    0x0e, 0x0b, 0x05,
    0x07, 0x0c, 0x08,

    0x1c, 0x09, 0x11,
    0x1f, 0x11, 0x1a,
    0x1f, 0x0d, 0x15,
    0x03, 0x03, 0x03,
},
{
    // Dark blue sky night time
    0x0a, 0x00, 0x05,
    0x13, 0x07, 0x00,
    0x18, 0x0a, 0x00,
    0x1d, 0x18, 0x16,

    0x0d, 0x0d, 0x0d,
    0x09, 0x09, 0x09,
    0x06, 0x06, 0x06,
    0x02, 0x02, 0x02,

    0x09, 0x09, 0x09,
    0x05, 0x05, 0x05,
    0x06, 0x06, 0x06,
    0x02, 0x02, 0x02,

    0x18, 0x0a, 0x00,
    0x0a, 0x04, 0x00,
    0x13, 0x07, 0x00,
    0x03, 0x03, 0x03,
},
{
    // Morning dark red sunrise
     0x00, 0x09, 0x13,
    0x00, 0x04, 0x0a,
    0x00, 0x00, 0x00,
    0x16, 0x17, 0x18,

    0x05, 0x0d, 0x11,
    0x04, 0x0a, 0x0d,
    0x03, 0x07, 0x0a,
    0x01, 0x05, 0x08,

    0x05, 0x04, 0x0d,
    0x02, 0x00, 0x0c,
    0x01, 0x04, 0x07,
    0x01, 0x00, 0x09,

    0x00, 0x00, 0x00,
    0x00, 0x06, 0x0e,
    0x00, 0x03, 0x07,
    0x03, 0x03, 0x03,
},
{
    // Morning light yellow sky
    0x07, 0x15, 0x1c,
    0x0e, 0x1b, 0x1f,
    0x11, 0x1d, 0x1e,
    0x00, 0x08, 0x09,

    0x0a, 0x19, 0x0e,
    0x08, 0x13, 0x0a,
    0x04, 0x0c, 0x05,
    0x04, 0x07, 0x03,

    0x0d, 0x16, 0x19,
    0x0b, 0x12, 0x15,
    0x04, 0x07, 0x03,
    0x08, 0x0f, 0x12,

    0x11, 0x1d, 0x1e,
    0x1a, 0x1c, 0x1c,
    0x15, 0x1a, 0x1b,
    0x03, 0x03, 0x03,
},
{
    // Morning light purple sky
    0x1f, 0x08, 0x16,
    0x1f, 0x13, 0x18,
    0x1f, 0x1a, 0x1a,
    0x09, 0x00, 0x04,

    0x13, 0x19, 0x0a,
    0x0b, 0x13, 0x08,
    0x07, 0x0c, 0x04,
    0x06, 0x07, 0x03,

    0x0d, 0x18, 0x19,
    0x0a, 0x14, 0x14,
    0x04, 0x07, 0x03,
    0x07, 0x10, 0x11,

    0x1f, 0x1a, 0x1a,
    0x1f, 0x1e, 0x1e,
    0x1f, 0x1c, 0x1c,
    0x03, 0x03, 0x03,
    }
};