#ifndef C_LIEF_ELF_HEADER_H_
#define C_LIEF_ELF_HEADER_H_
#include <inttypes.h>

#include "LIEF/ELF/enums.h"
/**  @defgroup elf_header_c_api Header
 *  @ingroup elf_c_api
 *  @addtogroup elf_header_c_api
 *  @brief Header C API
 *
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Elf_Header_t {
  uint8_t      identity[LIEF_ELF_EI_NIDENT];
  enum LIEF_ELF_E_TYPE  file_type;
  enum LIEF_ELF_ARCH    machine_type;
  enum LIEF_ELF_VERSION object_file_version;
  uint64_t     entrypoint;
  uint64_t     program_headers_offset;
  uint64_t     section_headers_offset;
  uint32_t     processor_flags;
  uint32_t     header_size;
  uint32_t     program_header_size;
  uint32_t     numberof_segments;
  uint32_t     section_header_size;
  uint32_t     numberof_sections;
  uint32_t     name_string_table_idx;
};

typedef struct Elf_Header_t Elf_Header_t;


#ifdef __cplusplus
}
#endif

/** @} */
#endif
