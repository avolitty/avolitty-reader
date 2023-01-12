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
- Reads from standard files, FIFOs, pipes and sockets
- Reads files from command line input file paths
- Returns chunked file data in an array
- Returns the current file byte offset position
- Sets a specific file byte offset position

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
```

`AvolittyReaderA()` opens a file stream from a file path for reading.

The return value variable `m` is an `unsigned char` defined as the following error statuses.

- `0` Success.
- `1` Error opening file "{file}".

The first argument variable `d` is a pointer to the `FILE` pointer of the variable `c`.

The second argument variable `n` is an `unsigned char *` string defined from the first command line argument value as a full path name to a file.

`AvolittyReaderB()` reads the file and returns chunked data.

The return value variable `m` is an `unsigned char` defined as the following error statuses.

- `0` Success.
- `1` Error reading file "{file}" because SEEK_SET is defined as a non-zero value.

The first argument variable `c` is a `FILE *` pointer.

The value is the open file stream result from `AvolittyReaderA()`.

The second argument variable `g` is a pointer to modify the value of the variable `e`.

The variable `e` is an `unsigned long int` defined as the byte offset position to start file reading from.

The default value is `0L` to start at the beginning of the file unless a specific offset is required for partial file reading.

`L` is the defined suffix for all `int` type literals with the `long` modifier.

The third argument variable `j` is a pointer to modify the value of the variable `h`.

The variable `h` is an `unsigned short int` defined as the byte size of each chunked file data result from `AvolittyReaderB()`.

The default value is `65535` unless a smaller memory buffer is required and `AvolittyReaderB()` defines it as the size of the chunked file data result.

The fourth argument variable `k` is a pointer to modify an `unsigned char` array to store the chunked file data result.

The default value is an empty array and `AvolittyReaderB()` defines it as the bytes from the chunked file data result.

The array length should match the value of `h` with a default value of `65535`.

The fifth argument variable `o` is a pointer to modify the value of the variable `l`.

The variable `l` is an `unsigned char` defined as the file reading status.

The default value is `0` and `AvolittyReaderB()` defines it as `1` when the end of the file is reached.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-reader -std=c89 src/avolitty-reader.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

It outputs an executable binary file named `avolitty-reader` in the current directory.

The output from executing `./avolitty-reader file` is the full contents of `file` located at the relative path.

``` console
echo "123456789" > file

./avolitty-reader file
# 123456789

./avolitty-reader
# Error reading file without required file name argument.

./avolitty-reader non-existent
# Error opening file "non-existent".
```

The exact size of bytes traversed is defined in the variable `e` while including skipped bytes.

The exact size of bytes read is defined in the variable `f` while omitting any skipped bytes.
