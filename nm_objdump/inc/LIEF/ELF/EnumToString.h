#ifndef C_LIEF_ELF_ENUM_TO_STRING_H_
#define C_LIEF_ELF_ENUM_TO_STRING_H_

#include "LIEF/visibility.h"

#include "LIEF/ELF/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

LIEF_API const char* SYMBOL_BINDINGS_to_string(enum LIEF_ELF_SYMBOL_BINDINGS e);
LIEF_API const char* E_TYPE_to_string(enum LIEF_ELF_E_TYPE e);
LIEF_API const char* VERSION_to_string(enum LIEF_ELF_VERSION e);
LIEF_API const char* ARCH_to_string(enum LIEF_ELF_ARCH e);
LIEF_API const char* SEGMENT_TYPES_to_string(enum LIEF_ELF_SEGMENT_TYPES e);
LIEF_API const char* DYNAMIC_TAGS_to_string(enum LIEF_ELF_DYNAMIC_TAGS e);
LIEF_API const char* ELF_SECTION_TYPES_to_string(enum LIEF_ELF_ELF_SECTION_TYPES e);
LIEF_API const char* ELF_SECTION_FLAGS_to_string(enum LIEF_ELF_ELF_SECTION_FLAGS e);
LIEF_API const char* ELF_SYMBOL_TYPES_to_string(enum LIEF_ELF_ELF_SYMBOL_TYPES e);
LIEF_API const char* ELF_CLASS_to_string(enum LIEF_ELF_ELF_CLASS e);
LIEF_API const char* ELF_DATA_to_string(enum LIEF_ELF_ELF_DATA e);
LIEF_API const char* OS_ABI_to_string(enum LIEF_ELF_OS_ABI e);
LIEF_API const char* DYNAMIC_FLAGS_to_string(enum LIEF_ELF_DYNAMIC_FLAGS e);
LIEF_API const char* DYNAMIC_FLAGS_1_to_string(enum LIEF_ELF_DYNAMIC_FLAGS_1 e);

#ifdef __cplusplus
}
#endif


#endif
