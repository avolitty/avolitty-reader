## Avolitty Reader

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create byte arrays from file streams using C89 with a fast and unique file reading algorithm.

- Allocates memory with stack instead of heap
- C89 compilation option -std=c89 supported up to c2x
- Closes open file stream at EOF
- Compiles with Clang or GCC
- Conforms to strict ISO C with -pedantic-errors enabled
- Error handling for file opening and reading
- Fast reading speed with optimization level 3
- Large file support on 64-bit systems
- Memory-safe with well-defined behavior
- Minified code
- Primitive data types with automatic casting
- Reads files from command line input file paths
- Reads from standard files, FIFOs, pipes and sockets
- Returns chunked file data in an array
- Returns the current file byte offset position
- Sets a file byte offset position
- Sets a number of bytes to skip for each file data chunk

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
	unsigned char *o = ((unsigned char *) b[1]);
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

		e += (f + i);
		g += i;
	}

	return a;
}
```

`AvolittyReaderA()` opens a file stream from a file path for reading.

The return value variable `n` is an `unsigned char` defined as the following error statuses.

- `0U` Success.
- `1U` Error opening file "{file}".

The first argument variable `d` is a pointer to modify the value of the variable `c`.

The variable `c` is a `FILE *` pointer.

The second argument variable `e` is an `unsigned long int` defined as the number of bytes to skip from the beginning of the file.

The third argument variable `o` is an `unsigned char *` string defined from the first command line argument value as a full path name to a file.

`AvolittyReaderB()` reads the file and returns chunked data.

The return value variable `n` is an `unsigned char` defined as the following error statuses.

- `0U` Success.
- `1U` Error reading file "{file}" at byte {position}.

The first argument variable `c` is a `FILE *` pointer.

The value is the open file stream result from `AvolittyReaderA()`.

The second argument variable `h` is a pointer to modify the value of the variable `f`.

The variable `f` is an `unsigned long int` defined as the byte offset position to start file reading from.

The default value is `0UL` to start at the beginning of the file unless a specific offset is required for partial file reading.

`UL` is the defined suffix for `unsigned long int` type literals.

The third argument variable `k` is a pointer to modify the value of the variable `i`.

The variable `i` is an `unsigned long int` defined as the byte size of each chunked file data result from `AvolittyReaderB()`.

The default value is `65536UL` unless a smaller memory buffer is required and `AvolittyReaderB()` defines it as the size of the chunked file data result.

The fourth argument variable `l` is a pointer to modify an `unsigned char` array to store the chunked file data result.

The default value is an empty array and `AvolittyReaderB()` defines it as the bytes from the chunked file data result.

The array length should match the value of `i` with a default value of `65536UL`.

The fifth argument variable `p` is a pointer to modify the value of the variable `m`.

The variable `m` is an `unsigned char` defined as the file reading status.

The default value is `0U` and `AvolittyReaderB()` defines it as `1U` when the end of the file is reached.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-reader -std=c89 src/avolitty-reader.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

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

The exact size of bytes traversed from the offset is defined in the variable `e` while including skipped bytes.

The exact size of bytes read from the offset is defined in the variable `g` while omitting any skipped bytes.
