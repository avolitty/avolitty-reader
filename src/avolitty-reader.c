#include <stdio.h>

unsigned char AvolittyReaderA(FILE **a, unsigned char *b) {
	unsigned char c = 0;
	*a = fopen((const char *) b, "rb");

	if (*a == 0) {
		c = 1;
	}

	return c;
}

unsigned char AvolittyReaderB(FILE *a, unsigned long int *b, unsigned short int *c, unsigned char *d, unsigned char *e) {
	size_t f = (size_t) *c;
	size_t g = 1;
	size_t h;
	long i = (long) *b;
	int j = 0;
	int k;
	unsigned long int l = 0L;
	unsigned short int m = 0;
	unsigned char n = 0;

	if (*b != 0L) {
		k = fseek(a, i, j);

		if (k == -1 && SEEK_SET != 0) {
			n = 1;
			*e = 1;
			fclose(a);
			return n;
		}
	}

	h = fread(d, g, f, a);
	l = (unsigned long int) h;
	*b = i + l;
	m = (unsigned short int) h;

	if (*c != m) {
		*c = m;
		*e = 1;
		fclose(a);
	}

	return n;
}
