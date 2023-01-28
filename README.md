## Avolitty Reader

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create byte arrays from file streams using C89 with a fast and unique file reading algorithm.

- Allocates static memory with stack instead of heap
- Calculates the exact size of bytes read and traversed from the initial offset
- Closes open file stream at EOF
- Compiles with Clang or GCC
- Compiles with forward-compatible C89 option -std=c89 and C++ option -stdc++98
- Conforms to strict ISO C with -pedantic-errors enabled
- Error handling for file opening and reading
- Fast reading speed without compiler optimization
- Large file support on 64-bit systems
- Memory-safe with well-defined behavior
- Minified code
- Reads files from command line input file paths
- Reads from standard files, FIFOs, pipes and sockets
- Returns chunked file data in an array
- Returns the current file byte offset position
- Sets a byte offset position from the beginning of a file
- Sets a byte offset position from the beginning of each file data chunk

#### Funding
[Avolitty](https://avolitty.com/donate/)

#### License
[MIT](https://github.com/avolitty/avolitty-reader/blob/main/LICENSE)

#### Usage
Clone the repository in the current directory with `git`.

``` console
git clone https://github.com/avolitty/avolitty-reader.git
```

Navigate to the cloned repository's root directory with `cd`.

``` console
cd avolitty-reader
```

The following example uses code from [test/main.c](https://github.com/avolitty/avolitty-reader/blob/main/test/main.c) to read a file with the `AvolittyReaderA()` and `AvolittyReaderB()` functions from [src/avolitty-reader.c](https://github.com/avolitty/avolitty-reader/blob/main/src/avolitty-reader.c).

``` c
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
```

`AvolittyReaderA()` opens a file stream from a file path for reading.

The return value variable `q` is an `unsigned char` defined as the following error statuses.

- `0U` Success.
- `1U` Error opening file "{file}".

The first argument variable `d` is a pointer to modify the value of the variable `c`.

The variable `c` is a `FILE *` pointer.

The second argument variable `f` is an `unsigned long int` defined as the number of bytes to skip from the beginning of the file.

The third argument variable `r` is an `unsigned char *` string defined from the first command line argument value as a full path name to a file.

`AvolittyReaderB()` reads the file and returns chunked data.

The return value variable `q` is an `unsigned char` defined as the following error statuses.

- `0U` Success.
- `1U` Error reading file "{file}" at byte {position}.

The first argument variable `c` is a `FILE *` pointer.

The value is the open file stream result from `AvolittyReaderA()`.

The second argument variable `k` is a pointer to modify the value of the variable `h`.

The variable `h` is an `unsigned long int` defined as the byte size of each chunked file data result from `AvolittyReaderB()`.

The default value is `65536UL` and `AvolittyReaderB()` defines it as the size of the chunked file data result.

The third argument variable `l` is a pointer to modify the value of the variable `g`.

The variable `g` is an `unsigned long int` defined as the byte offset position to start file reading from.

The default value is `0UL` to start at the beginning of the open file pointer offset position defined in the variable `f`.

The fourth argument variable `m` is a pointer to modify an `unsigned char` array to store the chunked file data result.

The default value is an empty array and `AvolittyReaderB()` defines it as the bytes from the chunked file data result.

The array length should match the value of `e` with a default value of `65536UL`.

The fifth argument variable `s` is a pointer to modify the value of the variable `p`.

The variable `p` is an `unsigned char` defined as the file reading status.

The default value is `0U` and `AvolittyReaderB()` defines it as `1U` when the end of the file is reached.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -o avolitty-reader -pedantic-errors -std=c89 src/avolitty-reader.c test/main.c
```

`-pedantic-errors` compiles with strict ISO C standards and `-std=c89` compiles with forward-compatible C89 standards.

It outputs an executable binary file named `avolitty-reader` in the current directory.

The output from executing `./avolitty-reader file` is the contents of a file.

``` console
echo "123456789" > file

./avolitty-reader file
# 123456789

./avolitty-reader
# Error reading file without required file name argument.

./avolitty-reader non-existent
# Error opening file "non-existent".
```

The first command line argument value `file` is the file name to read.

The exact size of bytes traversed including skipped bytes from the initial offset is defined in the variable `f`.

The exact size of bytes read excluding skipped bytes from the initial offset is defined in the variable `i`.
