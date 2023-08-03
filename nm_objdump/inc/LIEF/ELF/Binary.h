#ifndef C_LIEF_ELF_BINARY_H_
#define C_LIEF_ELF_BINARY_H_

#include <stddef.h>

#include "LIEF/visibility.h"

#include "LIEF/ELF/enums.h"

#include "LIEF/ELF/Section.h"
#include "LIEF/ELF/Segment.h"
#include "LIEF/ELF/Header.h"
#include "LIEF/ELF/DynamicEntry.h"
#include "LIEF/ELF/Symbol.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief LIEF::ELF::Binary C Handler */
struct Elf_Binary_t {
  void*              handler;
  const char*        name;
  const char*        interpreter;
  enum LIEF_ELF_ELF_CLASS     type;
  Elf_Header_t       header;
  Elf_Section_t      **sections;
  Elf_Segment_t      **segments;
  Elf_DynamicEntry_t **dynamic_entries;
  Elf_Symbol_t       **dynamic_symbols;
  Elf_Symbol_t       **static_symbols;
};

typedef struct Elf_Binary_t Elf_Binary_t;

/** @brief Wrapper for LIEF::ELF::Parser::parse */
LIEF_API Elf_Binary_t* elf_parse(const char *file);

LIEF_API void elf_binary_destroy(Elf_Binary_t* binary);

/* ELF::Binary methods
 * ==================
 */

/** @brief Update LIEF::ELF::Header object */
LIEF_API int elf_binary_save_header(Elf_Binary_t* binary);



#ifdef __cplusplus
}
#endif


/** @} */
#endif
