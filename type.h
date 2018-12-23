/**
 ****************************************************************************************
 *
 * @file type.h
 *
 * @brief generic type
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: 1.0$
 *
 * Change History:
 * 12/21/18: Initial release, working on capturing BLE data, see captured data in file: 2018.12.21-14.52.34.txt
 *
 ****************************************************************************************
 */

#ifndef _TYPE_H
#define _TYPE_H

// ifdef for GNU added to avoid potential clash with stdint.h
#if defined   (  __GNUC__  )
#include <stdint.h>
#else

/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

/* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

#endif // __GNUC__ 

#endif // _TYPE_H
