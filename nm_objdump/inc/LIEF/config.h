#ifndef LIEF_CONFIG_H
#define LIEF_CONFIG_H

#define LIEF_PE_SUPPORT       1
#define LIEF_ELF_SUPPORT      1
#define LIEF_MACHO_SUPPORT    1

#define LIEF_OAT_SUPPORT      1
#define LIEF_DEX_SUPPORT      1
#define LIEF_VDEX_SUPPORT     1
#define LIEF_ART_SUPPORT      1

#define LIEF_JSON_SUPPORT     1
#define LIEF_LOGGING_SUPPORT  1
#define LIEF_LOGGING_DEBUG    1
#define LIEF_FROZEN_ENABLED   1
/* #undef LIEF_EXTERNAL_LEAF */
/* #undef LIEF_EXTERNAL_UTF8CPP */
/* #undef LIEF_EXTERNAL_MBEDTLS */
/* #undef LIEF_EXTERNAL_FROZEN */
/* #undef LIEF_EXTERNAL_SPAN */

/* #undef LIEF_NLOHMANN_JSON_EXTERNAL */

#ifdef __cplusplus

static constexpr bool lief_pe_support      = 1;
static constexpr bool lief_elf_support     = 1;
static constexpr bool lief_macho_support   = 1;

static constexpr bool lief_oat_support     = 1;
static constexpr bool lief_dex_support     = 1;
static constexpr bool lief_vdex_support    = 1;
static constexpr bool lief_art_support     = 1;

static constexpr bool lief_json_support    = 1;
static constexpr bool lief_logging_support = 1;
static constexpr bool lief_logging_debug   = 1;
static constexpr bool lief_frozen_enabled  = 1;


#endif
#endif
