#include <stdint.h>
#include "LIEF/visibility.h"

#ifndef C_LIEF_LOGGING_H_
#define C_LIEF_LOGGING_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Disable the logging module */
LIEF_API void lief_logging_disable(void);

/** @brief Enable the logging module globally*/
LIEF_API void lief_logging_enable(void);

/** @brief Update logging level */
LIEF_API void lief_logging_set_level(uint32_t level);

#ifdef __cplusplus
}
#endif

/** @} */
#endif

