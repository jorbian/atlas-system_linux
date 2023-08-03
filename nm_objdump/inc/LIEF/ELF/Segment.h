#ifndef C_LIEF_ELF_SEGMENT_H_
#define C_LIEF_ELF_SEGMENT_H_

#include <stdint.h>
#include "LIEF/ELF/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Elf_Segment_t {
  enum LIEF_ELF_SEGMENT_TYPES type;
  uint32_t           flags;
  uint64_t           virtual_address;
  uint64_t           virtual_size;
  uint64_t           offset;
  uint64_t           alignment;
  uint64_t           size;
  uint8_t*           content;
};

typedef struct Elf_Segment_t Elf_Segment_t;

#ifdef __cplusplus
}
#endif

/** @} */
#endif
