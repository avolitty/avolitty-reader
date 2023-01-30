#include <stdio.h>

unsigned char AvolittyReaderA(FILE * * a, unsigned long int b, unsigned char * c) {
	*a = fopen((const char *) c, (const char *) "rb");

	if (*a == ((void *) 0)) {
		return ((unsigned char) 1U);
	}

	if (b != ((unsigned long int) 0UL)) {
		fseek(*a, (long) b, (int) SEEK_SET);
	}

	return ((unsigned char) 0U);
}

unsigned char AvolittyReaderB(FILE * a, unsigned long int * b, unsigned long int * c, unsigned char * d, unsigned char * e) {
	size_t f;
	size_t g;
	size_t h;
	long i;
	unsigned long int j;
	unsigned char k;
	unsigned char l;
	f = ((size_t) *b);
	g = ((size_t) 1);
	i = ((long) *c);
	j = ((unsigned long int) 0UL);
	k = ((unsigned char) 1U);
	l = ((unsigned char) 0U);

	if (*c != j) {
		fseek(a, (long) *c, (int) SEEK_CUR);
	}

	h = fread(d, g, f, a);
	j = ((unsigned long int) h);

	if (*b != j) {
		if (feof(a) == ((int) j)) {
			l = k;
		}

		*b = j;
		*e = k;
		fclose(a);
	}

	return l;
}
