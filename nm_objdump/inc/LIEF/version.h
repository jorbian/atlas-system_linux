#ifndef LIEF_VERSION_H
#define LIEF_VERSION_H

#if defined(NDEBUG)
  #define LIEF_NAME "LIEF"
#else
  #define LIEF_NAME "LIEF (Debug)"
#endif

#define LIEF_VERSION "0.13.2-2d9855fc"
#define LIEF_TAGGED 1
#define LIEF_TAG    "0.13.2"
#define LIEF_COMMIT "2d9855fc"

#define HUMAN_VERSION " v" LIEF_VERSION
#define HUMAN_NAME NAME HUMAN_VERSION

#endif
