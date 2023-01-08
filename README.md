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
- Fast reading speed with optimization level 3
- Large file support on 64-bit systems
- Memory-safe with well-defined behavior
- Minified code
- Primitive data types with automatic casting
- Returns chunked file data in an array of 32767 bytes
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

The following example uses code from [test/main.c](https://github.com/avolitty/avolitty-reader/blob/main/test/main.c) to read a file with `AvolittyReaderA()` and `AvolittyReaderB()` functions from [src/avolitty-reader.c](https://github.com/avolitty/avolitty-reader/blob/main/src/avolitty-reader.c).

``` c
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
```

`AvolittyReaderA()` opens a file stream from a file path for reading.

The first argument variable `b` is a pointer to the `FILE` pointer of the variable `a`.

The second argument variable `i` is a `const char *` string.

The value should be a full path name to a file.

`AvolittyReaderB()` reads the file and returns chunked data.

The first argument variable `a` is a `FILE *` pointer.

The value is the open file stream result from `AvolittyReaderA()`.

The second argument variable `e` is a pointer to modify the value of the variable `c`.

The variable `c` is a `signed long int` defined as the byte offset position to start file reading from.

The default value should be `0L` to start at the beginning of the file unless a specific offset is required for partial file reading.

`L` is the defined suffix for `signed long int` literals.

The third argument variable `h` is a pointer to modify the value of the variable `f`.

The variable `f` is a `signed short int` defined as the byte size of each chunked file data result from `AvolittyReaderB()`.

The default value should be `32767` unless a smaller memory buffer is required and `AvolittyReaderB()` defines it as the size of the chunked file data result.

The fourth argument variable `j` is a pointer to modify an `unsigned char` array to store the chunked file data result.

The default value should be an empty array and `AvolittyReaderB()` defines it as the bytes from the chunked file data result.

The array length should match the value of `f` with a default value of `32767`.

The fifth argument variable `l` is a pointer to modify the value of the variable `k`.

The variable `k` is a `signed char` defined as the file reading status.

The default value should be `0` and `AvolittyReaderB()` defines it as `1` when the end of the file is reached.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-reader -std=c89 src/avolitty-reader.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

It outputs an executable binary file named `avolitty-reader` in the current directory.

The output from executing `./avolitty-reader` is the full contents of the file located at the full path defined in the variable `g`.

``` console
echo "123456789" > file
./avolitty-reader
# 123456789
```

The exact size of bytes traversed is defined in the variable `c` while including skipped bytes.

The exact size of bytes read is defined in the variable `d` while omitting any skipped bytes.
