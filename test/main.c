#include <stdio.h>
#include "../src/avolitty-reader.h"

int main(int a, char *b[]) {
	FILE *c;
	FILE **d = &c;
	unsigned long int e = 0L;
	unsigned long int f = 0L;
	unsigned long int *g = &e;
	unsigned short int h = 65535;
	unsigned short int i;
	unsigned short int *j = &h;
	unsigned char k[65535];
	unsigned char l = 0;
	unsigned char m;
	unsigned char *n = (unsigned char *) b[1];
	unsigned char *o = &l;

	if (a == 1) {
		printf("Error reading file without required file name argument.", n);
		return a;
	}

	m = AvolittyReaderA(d, n);

	if (m == 1) {
		printf("Error opening file \"%s\".", n);
		return a;
	}

	while (l == 0) {
		m = AvolittyReaderB(c, g, j, k, o);

		if (m == 1) {
			printf("Error reading file \"%s\" because SEEK_SET is defined as a non-zero value.", n);
			return a;
		}

		i = 0;

		while (h != i) {
			printf("%c", k[i++]);
		}

		f += (unsigned long int) h;
	}

	return a;
}
