DEPS = 
OBJ = src/calculator.o
NANOLIBC_OBJ = $(patsubst %.cpp,%.o,$(wildcard src/nanolibc/*.cpp))
OUTPUT = public/calculator.wasm

COMPILE_FLAGS = -Wall \
		--target=wasm32 \
		-Os \
		-nostdlib \
		-fvisibility=hidden \
		-std=c++20 \
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


%.o: %.cpp $(DEPS) Makefile src/nanolibc/libc.h src/nanolibc/libc_extra.h
	clang++ \
		-c \
		$(COMPILE_FLAGS) \
		-o $@ \
		$<

start:
	firebase serve --only hosting

live_test:
	when-changed -1 calculator_test.cc -r src -c "make test"

test:
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT)
