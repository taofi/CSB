#include "Call.h"

int _cdecl Call::cde�l(int x, int y, int z) {
	return x + y + z;
}
int _stdcall Call::cstd(int& x, int y, int z) {
	return x * y * z;
}

int _fastcall Call::cfst(int a, int b, int c, int d) {
	return a + b + c + d;
}