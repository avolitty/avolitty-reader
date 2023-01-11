#include <stdio.h>

signed char AvolittyReaderA(FILE **a, const char *b) {
	signed char c = 0;
	*a = fopen(b, "rb");

	if (*a == 0) {
		c = 1;
	}

	return c;
}

signed char AvolittyReaderB(FILE *a, signed long int *b, signed short int *c, unsigned char *d, signed char *e) {
	size_t f = (size_t) *c;
	size_t g = 1;
	size_t h;
	long i = (long) *b;
	signed long int j = 0L;
	int k = 0;
	int l = 0;
	signed short int m = 0;
	signed char n = 0;

	if (*b != 0L) {
		l = fseek(a, i, k);

		if (l == -1 && SEEK_SET != 0) {
			*e = 1;
			n = 1;
			fclose(a);
			return n;
		}
	}

	h = fread(d, g, f, a);
	j = (signed long int) h;
	*b = i + j;
	m = (signed short int) h;

	if (*c != m) {
		*c = m;
		*e = 1;
		fclose(a);
	}

	return n;
}
