#include "nanolibc/libc.h"
#include "nanolibc/libc_extra.h"
#include "evaluator.cpp"

#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"

WASM_EXPORT char* allocateMemoryForString(int size) {
	return new char[size];
}

WASM_EXPORT void freeMemoryForString(char* str) {
	delete[] str;
}

WASM_EXPORT double calculate(const char* expression) {
	Evaluator evaluator(expression);
	return evaluator.evaluate();
}
