#include <stdio.h>

void AvolittyReaderA(FILE **a, const char *b) {
	*a = fopen(b, "rb");
	return;
}

void AvolittyReaderB(FILE *a, signed long int *b, signed short int c, unsigned char *d, signed char *e) {
	size_t f = (size_t) c;
	size_t g = 1;
	size_t h;
	signed long int i = 0L;
	signed short int j = 0;
	h = fread(d, g, f, a);
	i = (signed long int) h;
	*b = *b + i;
	j = (signed short int) h;

	if (c != j) {
		*e = 1;
	}

	return;
}
