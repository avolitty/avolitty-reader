#include <stdio.h>
#include "../src/avolitty-reader.h"

int main(int a, char *b[]) {
	FILE *c;
	FILE **d = &c;
	unsigned long int e = 0UL;
	unsigned long int f = 0UL;
	unsigned long int g = 0UL;
	unsigned long int *h = &f;
	unsigned long int i = 65536UL;
	unsigned long int j;
	unsigned long int *k = &i;
	unsigned char l[65536UL];
	unsigned char m = 0U;
	unsigned char n;
	unsigned char *o = (unsigned char *) b[1];
	unsigned char *p = &m;

	if (a == 1) {
		printf("Error reading file without required file name argument.", o);
		return a;
	}

	n = AvolittyReaderA(d, e, o);

	if (n == 1U) {
		printf("Error opening file \"%s\".", o);
		return a;
	}

	e = 0UL;

	while (m == 0U) {
		n = AvolittyReaderB(c, h, k, l, p);

		if (n != 0U) {
			if (n == 1U) {
				printf("Error reading file \"%s\" at byte \"%lu\".", o, e);
			}

			return a;
		}

		j = 0UL;

		while (i != j) {
			printf("%c", l[j++]);
		}

		e += f + i;
		g += i;
	}

	return a;
}
