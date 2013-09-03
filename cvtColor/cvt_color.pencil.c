// -*- c -*-
// UjoImro, 2013
// Experimental Code for the CARP Project

#include <stdint.h>

#include "cvt_color.pencil.h"

// this function cannot be called from OpenCV
static 
void 
RGB2Gray(
    int rows,
    int cols,
    int src_step,
    int dst_step,
    int channels,
    int bidx,
    const DATA_TYPE src[static const restrict rows][src_step][channels],
    DATA_TYPE dst[static const restrict rows][dst_step] )
{
#   pragma independent
    for ( int q = 0; q < rows; q++ )
#       pragma independent
	for( int w = 0; w < cols; w++ )
	    dst[q][w] = CV_DESCALE( (src[q][w][bidx] * B2Y + src[q][w][1] * G2Y + src[q][w][(bidx^2)] * R2Y ), yuv_shift );
    return;
} // pencil_RGB2Gray_caller


void 
pencil_RGB2Gray( 
    int rows, 
    int cols, 
    int src_step,
    int dst_step, 
    int channels,
    int bidx, 
    const DATA_TYPE src[], 
    DATA_TYPE dst[] )
{
    RGB2Gray( rows, cols, src_step, dst_step, channels, bidx, src, dst );

    return;
} // pencil_RGB2Gray



// LuM end of file