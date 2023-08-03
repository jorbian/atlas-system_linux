#ifndef C_LIEF_ELF_SECTION_H_
#define C_LIEF_ELF_SECTION_H_

#include <stdint.h>

#include "LIEF/ELF/enums.h"

struct Elf_Section_t
{
  const char*            name;
  uint32_t               flags;
  enum LIEF_ELF_ELF_SECTION_TYPES type;
  uint64_t               virtual_address;
  uint64_t               offset;
  uint64_t               original_size;
  uint32_t               link;
  uint32_t               info;
  uint64_t               alignment;
  uint64_t               entry_size;
  uint64_t               size;
  uint8_t*               content;
  double                 entropy;
};

typedef struct Elf_Section_t Elf_Section_t;

#ifdef __cplusplus
}
#endif

/** @} */
#endif
