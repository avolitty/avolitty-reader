#include <stdio.h>

void AvolittyReaderA(FILE **a, const char *b) {
	*a = fopen(b, "rb");
	return;
}

void AvolittyReaderB(FILE *a, signed long int *b, signed short int *c, unsigned char *d, signed char *e) {
	size_t f = (size_t) *c;
	size_t g = 1;
	size_t h;
	long i = (long) *b;
	signed long int j = 0L;
	int k = 0;
	signed short int l = 0;
	fseek(a, i, k);
	h = fread(d, g, f, a);
	j = (signed long int) h;
	*b = i + j;
	l = (signed short int) h;

	if (*c != l) {
		*c = l;
		*e = 1;
		fclose(a);
	}

	return;
}
