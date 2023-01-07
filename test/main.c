#include <stdio.h>
#include "../src/avolitty-reader.h"

int main() {
	FILE *a;
	FILE **b = &a;
	signed long int c = 0L;
	signed long int d = 0L;
	signed long int *e = &c;
	signed short int f = 32767;
	signed short int g;
	signed short int *h = &f;
	const char *i = "file";
	unsigned char j[32767];
	signed char k = 0;
	signed char *l = &k;
	AvolittyReaderA(b, i);

	while (k == 0) {
		AvolittyReaderB(a, e, h, j, l);
		g = 0;

		while (f != g) {
			printf("%c", j[g++]);
		}

		d += (signed long int) f;
	}

	return 0;
}
