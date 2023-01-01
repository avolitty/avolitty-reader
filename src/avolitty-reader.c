#include <stdio.h>

#ifndef off_t
#define off_t signed long int
#endif

void AvolittyReaderA(FILE **a, const char *b) {
	*a = fopen(b, "rb");
	return;
}

void AvolittyReaderB(FILE *a, signed long int *b, signed short int c, unsigned char *d, signed char *e) {
	off_t g = (off_t) *b;
	size_t h = (size_t) c;
	size_t i = 1;
	size_t j;
	int k = 0;
	signed long int l = 0L;
	signed short int m = 0;
	fseeko(a, g, k);
	j = fread(d, i, h, a);
	l = (signed long int) j;
	*b = *b + l;
	m = (signed short int) j;

	if (c != m) {
		*e = 1;
	}

	return;
}
