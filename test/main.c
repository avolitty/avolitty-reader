#include <stddef.h>
#include <stdio.h>
#include "../src/avolitty-reader.h"

int main(int a, char **b) {
	FILE *c;
	FILE **d = &c;
	unsigned long int e;
	unsigned long int f;
	unsigned long int g;
	unsigned long int h;
	unsigned long int i;
	unsigned long int j;
	unsigned long int *k;
	unsigned long int *l;
	unsigned char m[((unsigned long int) 65536UL)];
	unsigned char n;
	unsigned char o;
	unsigned char p;
	unsigned char q;
	unsigned char *r;
	unsigned char *s;
	e = ((unsigned long int) 65536UL);
	f = ((unsigned long int) 0UL);
	g = ((unsigned long int) 0UL);
	h = ((unsigned long int) 0UL);
	i = ((unsigned long int) 0UL);
	k = &e;
	l = &g;
	n = ((unsigned char) 1U);
	o = ((unsigned char) 0U);
	p = ((unsigned char) 0U);
	r = ((unsigned char *) b[1]);
	s = &p;

	if (a == ((int) 1)) {
		printf("Error reading file without required file name argument.", r);
		return a;
	}

	q = AvolittyReaderA(d, f, r);

	if (n == q) {
		printf("Error opening file \"%s\".", r);
		return a;
	}

	f = h;

	while (o == p) {
		q = AvolittyReaderB(c, k, l, m, s);

		if (o != q) {
			if (n == q) {
				printf("Error reading file \"%s\" at byte \"%lu\".", r, f);
			}

			return a;
		}

		j = h;

		while (e != j) {
			printf("%c", m[j++]);
		}

		f += (e + g);
		i += e;
	}

	return a;
}
