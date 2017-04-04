/* Copyright 2013 The MathWorks, inc. */
#ifndef _LIBMWIPPMEDIANFILTER_HPP_
#define _LIBMWIPPMEDIANFILTER_HPP_

#ifndef LIBMWIPPMEDIANFILTER_API
#    define LIBMWIPPMEDIANFILTER_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>


EXTERN_C LIBMWIPPMEDIANFILTER_API
void ippMedianFilter_uint8(
        const  uint8_T     *   srcImg,
        const  real64_T    *   srcSize,
        const  real64_T    *   maskSz,        
               uint8_T     *   dstImg,
        const  boolean_T       singleThreadedMode);

EXTERN_C LIBMWIPPMEDIANFILTER_API
void ippMedianFilter_uint16(
        const  uint16_T    *   srcImg,
        const  real64_T    *   srcSize,
        const  real64_T    *   maskSz,        
               uint16_T    *   dstImg,
        const  boolean_T       singleThreadedMode);

EXTERN_C LIBMWIPPMEDIANFILTER_API
void ippMedianFilter_int16(
        const  int16_T     *   srcImg,
        const  real64_T    *   srcSize,
        const  real64_T    *   maskSz,        
               int16_T     *   dstImg,
        const  boolean_T       singleThreadedMode);

EXTERN_C LIBMWIPPMEDIANFILTER_API
void ippMedianFilter_real32(
        const  real32_T    *   srcImg,
        const  real64_T    *   srcSize,
        const  real64_T    *   maskSz,        
               real32_T    *   dstImg,
        const  boolean_T       singleThreadedMode);
#endif
