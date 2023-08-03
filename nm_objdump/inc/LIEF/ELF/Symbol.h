#ifndef C_LIEF_ELF_SYMBOL_H_
#define C_LIEF_ELF_SYMBOL_H_

#include <stdint.h>

#include "LIEF/ELF/enums.h"
#include "LIEF/types.h"

struct Elf_Symbol_t
{
	const char           *name;
	enum LIEF_ELF_ELF_SYMBOL_TYPES type;
	enum LIEF_ELF_SYMBOL_BINDINGS  binding;
	uint8_t               information;
	uint8_t               other;
	uint16_t              shndx;
	uint64_t              value;
	uint64_t              size;
	bool                  is_exported;
	bool                  is_imported;
};

typedef struct Elf_Symbol_t Elf_Symbol_t;

#endif
