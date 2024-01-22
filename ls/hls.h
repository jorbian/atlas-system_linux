#ifndef HLS_H
#define HLS_H

#define FLAGS \
	X(ALMOST_ALL, 'A') \
	X(ALL, 'a') \
	X(ONE, '1') \
	X(LONG, 'l')

#define X(a, b) a,
enum flags_t
{
	FLAGS
	NUM_FLAGS
};
#undef X

#define X(a, b) b,
const char flag_glyphs[] = { FLAGS '\0' };
#undef X

#define SET_FLAG(bit, token) ((1 << bit) | token)

#endif
