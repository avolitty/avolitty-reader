#include <stdio.h>
#include "../src/avolitty-reader.h"

int main(void) {
	FILE *a;
	FILE **b = &a;
	signed long int c = 0L;
	signed long int d = 0L;
	signed long int *e = &c;
	int f = 0;
	signed short int g = 32767;
	signed short int h;
	signed short int *i = &g;
	const char *j = "file";
	unsigned char k[32767];
	signed char l = 0;
	signed char m = 0;
	signed char *n = &l;
	m = AvolittyReaderA(b, j);

	if (m == 1) {
		printf("Error opening file \"%s\".", j);
		return f;
	}

	while (l == 0) {
		m = AvolittyReaderB(a, e, i, k, n);

		if (m == 1) {
			printf("Error reading file \"%s\" because SEEK_SET is defined as a non-zero value.", j);
			return f;
		}

		h = 0;

		while (g != h) {
			printf("%c", k[h++]);
		}

		d += (signed long int) g;
	}

	return f;
}
