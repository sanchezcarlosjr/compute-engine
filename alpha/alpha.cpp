#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"

WASM_EXPORT int calculate() {
    return 0;
}


