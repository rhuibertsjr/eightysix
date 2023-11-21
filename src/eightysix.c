#include "eightysix.h"

internal void
_monitor_stdout_log(
  monitor_tag tag, monitor_type type, const char* format, ...)
{
  const uint8_t message_size = 128;
  char message[message_size];
  va_list args_list;

  va_start(args_list, format);
  vsnprintf(message, message_size, format, args_list);
  va_end(args_list);

  fprintf(stdout, "[DEBUG][%s] (%s) %s\n",
    _monitor_type_table[type], _monitor_tag_table[tag], message);
}

//= rhjr: abort & assertion

internal _Noreturn uintptr_t
_monitor_assert (
  const char* condition, const char* file, const char* func, 
  uint32_t line, const char *format, ...)
{
  const uint8_t message_size = 128;
  char message[message_size];
  va_list args_list;

  va_start(args_list, format);
  vsnprintf(message, message_size, format, args_list);
  va_end(args_list);

  fprintf(stderr, "[DEBUG][%s] (%s) \"%s\" at %s::%s() at %d: %s.\n",
    _monitor_type_table[ERROR], _monitor_tag_table[TAG_ASSERT],
    condition, file, func, line, message);

  fflush(stdout);
  abort();
}

int main(void)
{
  LOG(TAG_PLATFORM, INFO, "Platform layer ready");
  ASSERT(1 < 0, "Should be false");

  return 0;
}
