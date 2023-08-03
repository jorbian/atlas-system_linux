#ifndef C_LIEF_LOGGING_H_
#define C_LIEF_LOGGING_H_

#include <stdint.h>
#include "LIEF/visibility.h"

LIEF_API void lief_logging_disable(void);

LIEF_API void lief_logging_enable(void);

LIEF_API void lief_logging_set_level(uint32_t level);


/** @} */
#endif

