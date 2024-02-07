#include "eightysix.h"

int
main(int argc, char *argv[])
{
  if (argc < 3)
  {
    printf("(EightyOne) Usage: '%s [DEST FILE] [SOURCE FILE]'\n", argv[0]);
    printf("  - Make sure you have provided a destination and source file.\n");
    printf("  - Please enter a valid file name.\n");
    return -1;
  }

  return 0;
}
