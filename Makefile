all:
	 bison --o alpha/parser.c -t -v -d alpha/parser.y
	 flex --o alpha/lexer.c alpha/lexer.l
	 emcc -lembind alpha/alpha.cpp -o static/alpha.js

clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT) library.wat
