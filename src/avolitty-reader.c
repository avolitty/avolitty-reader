#include <stddef.h>
#include <stdio.h>

unsigned char AvolittyReaderA(FILE **a, unsigned long int b, unsigned char *c) {
	unsigned char d;
	d = ((unsigned char) 0U);
	*a = fopen((const char *) c, (const char *) "rb");

	if (*a == ((int) 0)) {
		d++;
		return d;
	}

	if (b != ((unsigned long int) 0UL)) {
		fseek(*a, (long) b, (int) SEEK_SET);
	}

	return d;
}

unsigned char AvolittyReaderB(FILE *a, unsigned long int *b, unsigned long int *c, unsigned char *d, unsigned char *e) {
	size_t f;
	size_t g;
	size_t h;
	long i;
	unsigned long int j;
	unsigned char k;
	f = ((size_t) *b);
	g = ((size_t) 1);
	i = ((long) *c);
	j = ((unsigned long int) 0UL);
	k = ((unsigned char) 0U);

	if (*c != ((unsigned long int) 0UL)) {
		fseek(a, (long) *c, (int) SEEK_CUR);
	}

	h = fread(d, g, f, a);
	j = ((unsigned long int) h);

	if (*b != j) {
		if (feof(a) == ((int) 0)) {
			k = ((unsigned char) 1U);
		}

		*b = j;
		*e = ((unsigned char) 1U);
		fclose(a);
	}

	return k;
}
