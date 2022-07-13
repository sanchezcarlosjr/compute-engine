#include "nanolibc/libc.h"
#include "nanolibc/libc_extra.h"

#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"
 
WASM_EXPORT int calculate() {
	return 0;
}

