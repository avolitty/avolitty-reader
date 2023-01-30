#include <limits.h>
#include <stdio.h>
#include "../src/avolitty-reader.h"

int main(int a, char * * b) {
	FILE * c;
	FILE * * d = &c;
	unsigned long int e;
	unsigned long int f;
	unsigned long int g;
	unsigned long int h;
	unsigned long int i;
	unsigned long int j;
	unsigned long int * k;
	unsigned long int * l;
	unsigned char m[((unsigned long int) 65536UL)];
	unsigned char n;
	unsigned char o;
	unsigned char p;
	unsigned char q;
	unsigned char r;
	unsigned char s;
	unsigned char * t;
	unsigned char * u;
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
	q = ((unsigned char) 0U);
	r = ((unsigned char) 0U);
	t = ((unsigned char *) b[n]);
	u = &p;

	if (a == ((int) f)) {
		printf("Error reading file without required file name argument.", t);
		return a;
	}

	s = AvolittyReaderA(d, f, t);

	if (n == s) {
		printf("Error opening file \"%s\".", t);
		return a;
	}

	f = h;

	while (o == p) {
		s = AvolittyReaderB(c, k, l, m, u);

		if (o != s) {
			if (n == s) {
				printf("Error reading file \"%s\" at byte \"%lu\".", t, f);
			}

			return a;
		}

		j = h;

		while (e != j) {
			printf("%c", m[j]);
			j++;
		}

		if (f < ((ULONG_MAX - (e + g)) + n)) {
			f += (e + g);
		} else {
			f = ULONG_MAX;
			q = ((unsigned char) 1U);
		}

		if (i < ((ULONG_MAX - e) + n)) {
			i += e;
		} else {
			i = ULONG_MAX;
			r = ((unsigned char) 1U);
		}
	}

	return a;
}
