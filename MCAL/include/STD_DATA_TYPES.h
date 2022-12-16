/*
 * STD_DATA_TYPES.h
 *
 *  Created on: May 3, 2019
 *  Author: Islam Ahmed
 */
#ifndef STD_DATA_TYPES_H_
#define STD_DATA_TYPES_H_

/* Boolean Data Type */
typedef unsigned char  bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#ifndef HIGH
#define HIGH        (1u)
#endif

#ifndef LOW
#define LOW         (0u)
#endif


typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           int8;           /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          int16;          /*      -32768 .. +32767          */
typedef unsigned int          uint32;         /*           0 .. 4294967295      */
typedef signed int            int32;          /* -2147483648 .. +2147483647     */
typedef unsigned long         uint64;         /*       0..18446744073709551615  */
typedef signed long           int64;
typedef float                 float32;
typedef double                float64;



#endif /* STD_DATA_TYPES_H_ */
