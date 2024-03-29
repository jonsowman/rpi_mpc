/* Copyright 2013 The MathWorks, Inc. */

#ifndef _BWDISTEDTFT_
#define _BWDISTEDTFT_


#ifndef LIBMWBWDISTEDTFT_API
#    define LIBMWBWDISTEDTFT_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>

/* uint32_T */
EXTERN_C LIBMWBWDISTEDTFT_API
void bwdistEDTFT32_boolean(const boolean_T* bw,        /** Pointer to bw image */
                           const uint32_T* idx,        /** Pointer to initial indices */
                           const real64_T* input_size, /** Pointer to bw image size */
                           const real64_T num_dims,    /** Number of dimensions in image */
                           real32_T* d,                /** Output - distance to nearest non-zero pixel */
                           uint32_T* labels);          /** Output - label, feature transform (linear index to nearest non-zero pixel). Pass NULL to skip this computation. */

#endif
