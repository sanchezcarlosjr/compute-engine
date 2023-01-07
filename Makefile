all:
	 flex --o alpha/lexer.c alpha/lexer.l
	 emcc -lembind alpha/alpha.cpp -o static/alpha.js

clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT) library.wat
