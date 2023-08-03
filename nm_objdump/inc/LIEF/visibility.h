#ifndef LIEF_SYMBOL_VISIBILITY_H
#define LIEF_SYMBOL_VISIBILITY_H

#define LIEF_HELPER_IMPORT __attribute__((visibility("default")))
#define LIEF_HELPER_EXPORT __attribute__((visibility("default")))
#define LIEF_HELPER_LOCAL  __attribute__((visibility("hidden")))

#if defined(LIEF_STATIC)
  #define LIEF_API
  #define LIEF_LOCAL
#elif defined(LIEF_EXPORTS)
  #define LIEF_API   LIEF_HELPER_EXPORT
  #define LIEF_LOCAL LIEF_HELPER_LOCAL
#elif defined(LIEF_IMPORT)
  #define LIEF_API   LIEF_HELPER_IMPORT
  #define LIEF_LOCAL LIEF_HELPER_LOCAL
#else
  #define LIEF_API
  #define LIEF_LOCAL LIEF_HELPER_LOCAL
#endif

#endif
