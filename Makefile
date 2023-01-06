EPS = 
OBJ = alpha/alpha.o
NANOLIBC_OBJ = $(patsubst %.cpp,%.o,$(wildcard clang-wasm/nanolibc/*.cpp))
OUTPUT = static/app.wasm

COMPILE_FLAGS = -Wall \
		--target=wasm32 \
		-Os \
		-nostdlib \
		-fvisibility=hidden \
		-std=c++17 \
		-ffunction-sections \
		-fdata-sections \
		-DPRINTF_DISABLE_SUPPORT_FLOAT=1 \
		-DPRINTF_DISABLE_SUPPORT_LONG_LONG=1 \
		-DPRINTF_DISABLE_SUPPORT_PTRDIFF_T=1

$(OUTPUT): $(OBJ) $(NANOLIBC_OBJ) Makefile
	wasm-ld \
		-o $(OUTPUT) \
		--no-entry \
		--strip-all \
		--export-dynamic \
		--allow-undefined \
		--initial-memory=131072 \
		-error-limit=0 \
		--lto-O3 \
		-O3 \
		--gc-sections \
		$(OBJ) \
		$(LIBCXX_OBJ) \
		$(NANOLIBC_OBJ)


%.o: %.cpp $(DEPS) Makefile clang-wasm/nanolibc/libc.h clang-wasm/nanolibc/libc_extra.h
	clang++ \
		-c \
		$(COMPILE_FLAGS) \
		-o $@ \
		$<

library.wat: $(OUTPUT) Makefile
	~/build/wabt/wasm2wat -o library.wat $(OUTPUT)

wat: library.wat

clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT) library.wat
