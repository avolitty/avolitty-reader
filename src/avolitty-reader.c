#include <stdio.h>

unsigned char AvolittyReaderA(FILE * * a, unsigned long int b, unsigned char * c) {
	unsigned long int d;
	d = ((unsigned long int) 0UL);
	*a = fopen((const char *) c, (const char *) "rb");

	if (*a == ((void *) d)) {
		d++;
	} else {
		if (b != d) {
			fseek(*a, (long) b, (int) SEEK_SET);
		}
	}

	return (unsigned char) d;
}

unsigned char AvolittyReaderB(FILE * a, unsigned long int * b, unsigned long int * c, unsigned char * d, unsigned char * e) {
	size_t f;
	long g;
	unsigned long int h;
	unsigned char i;
	unsigned char j;
	g = ((long) *c);
	h = ((unsigned long int) 0UL);
	i = ((unsigned char) 1U);
	j = ((unsigned char) 0U);

	if (*c != h) {
		fseek(a, (long) *c, (int) SEEK_CUR);
	}

	f = fread(d, (size_t) i, (size_t) *b, a);
	h = ((unsigned long int) f);

	if (*b != h) {
		if (feof(a) == ((int) h)) {
			j = i;
		}

		*b = h;
		*e = i;
		fclose(a);
	}

	return j;
}
