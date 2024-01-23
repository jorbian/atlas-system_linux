#ifndef ERRORS_H
#define ERRORS_H

/**
 * enum error_type_t - index of the error type on the other arrays
 * @#include "error_type.def";#undef ERROR_TYPE: asdf
*/
typedef enum error_type_t
{
	#define ERROR_TYPE(x, y, z) x,
		#include "error_type.def"
	#undef ERROR_TYPE
};

static char *template_strings[] = {
	#define ERROR_TYPE(x, y, z) y,
		#include "error_type.def"
	#undef ERROR_TYPE
};

static int num_fields[] = {
	#define ERROR_TYPE(x, y, z) z,
		#include "error_type.def"
	#undef ERROR_TYPE
};

#endif
