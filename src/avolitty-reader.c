#include <stdio.h>

unsigned char AvolittyReaderA(FILE **a, unsigned long int b, unsigned char *c) {
	unsigned char d = 0U;
	*a = fopen((const char *) c, "rb");

	if (*a == 0) {
		d = 1U;
		return d;
	}

	if (b != 0UL) {
		fseek(*a, (long) b, SEEK_SET);
	}

	return d;
}

unsigned char AvolittyReaderB(FILE *a, unsigned long int *b, unsigned long int *c, unsigned char *d, unsigned char *e) {
	size_t f = (size_t) *c;
	size_t g = 1;
	size_t h;
	long i = (long) *b;
	unsigned long int j = 0UL;
	unsigned char k = 0U;

	if (*b != 0UL) {
		fseek(a, (long) *b, SEEK_CUR);
	}

	h = fread(d, g, f, a);
	j = (unsigned long int) h;

	if (*c != j) {
		if (feof(a) == 0) {
			k = 1U;
		}

		*c = j;
		*e = 1U;
		fclose(a);
	}

	return k;
}
