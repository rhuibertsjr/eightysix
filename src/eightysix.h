#ifndef EIGHTYSIX_H
#define EIGHTYSIX_H

/// Eightysix is a partial 8086 assembler / simulator. The 8086 was a 16-bit
/// microprocessor designed by Intel and gave rise to the well known x86
/// architecture.
///
/// Author: Rene Huiberts 
/// Date: 07 - 02 - 2023
//

//= rhjr: basic types

#include <stdint.h>

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float    r32;
typedef double   r64;

//= rhjr: codebase keywords

#define internal static
#define global   static
#define local    static

#endif
