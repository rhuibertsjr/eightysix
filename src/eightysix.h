#ifndef EIGHTYSIX_H
#define EIGHTYSIX_H

/// Eightysix is a partial 8086 assembler / simulator. The 8086 was a 16-bit
/// microprocessor designed by Intel and gave rise to the well known x86
/// architecture.
//
/// Author: René Huiberts 
/// Date: 21 - 11 - 2023
//

//= rhjr: context cracking

#if !defined(EIGHTYSIX_WINDOWS) || !defined(EIGHTYSIX_GNU_LINUX) 
#  ifdef _WIN32
#    define EIGHTYSIX_WINDOWS 1
#    define EIGHTYSIX_GNU_LINUX 0 
#  endif // _WIN32
#  ifdef __gnu_linux__
#    define EIGHTYSIX_GNU_LINUX 1
#    define EIGHTYSIX_WINDOWS 0 
#  endif // __gnu_linux__
#endif // !defined(EIGHTYSIX_WINDOWS) && !defined(EIGHTYSIX_GNU_LINUX)

//= rhjr: helpers

#define internal static

#define STATEMENT(x) do { x } while(0)

//= rhjr: logging, abort & assertion

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum monitor_type monitor_type;
enum monitor_type
{
  ERROR         = 0x00, 
  WARNING,
  INFO
};

typedef enum monitor_tag monitor_tag;
enum monitor_tag
{
  TAG_NONE      = 0x00,
  TAG_ASSERT,
  TAG_PLATFORM
};

const char *_monitor_type_table[] =
  {
    [ERROR]   = "ERROR",
    [WARNING] = "WARNING",
    [INFO]    = "INFO"
  };

const char *_monitor_tag_table[] =
  {
    [TAG_NONE]     = "DEBUG",
    [TAG_ASSERT]   = "ASSERTION",
    [TAG_PLATFORM] = "Platform"
  };

internal void
_monitor_stdout_log(
  monitor_tag tag, monitor_type type, const char* format, ...);

#if EIGHTYSIX_LOGGING
#  define LOG(tag, type, message, ...)                                         \
      STATEMENT(_monitor_stdout_log(tag, type, message, ##__VA_ARGS__);)
#  define DEBUG(message, ...)                                                  \
      STATEMENT(_monitor_stdout_log(                                           \
        TAG_NONE, WARNING, message, ##__VA_ARGS__);)
#else
#  define LOG(tag, type, message, ...)
#  define DEBUG(tag, type, message, ...)
#endif

internal _Noreturn uintptr_t
_monitor_assert (
  const char* condition, const char* file, const char* func,
  uint32_t line, const char *msg, ...);

#if EIGHTYSIX_ASSERT
#  define ASSERT(condition, msg, ...)                                          \
     STATEMENT( if(!(condition)) {                                             \
       _monitor_assert(                                                        \
         #condition, __FILE__, __FUNCTION__, __LINE__, msg, ##__VA_ARGS__);})
#else
#  define ASSERT(condition, msg, ...)
#endif

#endif // EIGHTYSIX_H
// eightysix.h ends here
