#include <stdio.h>
#include "../src/avolitty-reader.h"

int main() {
	FILE *a;
	FILE **b = &a;
	signed long int c = 0L;
	signed long int *d = &c;
	signed short int e = 32767;
	const char *f = "file";
	unsigned char g[32767];
	signed char h = 0;
	signed char *i = &h;
	AvolittyReaderA(b, f);

	while (h == 0) {
		AvolittyReaderB(a, d, e, g, i);
	}

	return 0;
}
