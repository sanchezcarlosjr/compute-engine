class Token {
public:
	char kind;
	double value;
	Token(char kind, double value=0): kind(kind), value(value) {} 
};


class TokenStream {
private:
	int finiteControl = 0;
	const char* string;
	bool full = false;
	Token* buffer = NULL;
public:
	TokenStream(const char* expression): string(expression) {}

	void putback() {
		full = true;
	}

	void next() {
		if (full) {
			full = false;
			return;
		}
		while(string[finiteControl] == ' ')
			finiteControl++;
		switch(string[finiteControl]) {
			case '!':
			case '-': 
			case '(': 
			case ')': 
			case '+': 
			case '*': 
			case '/': 
			case '%':
				buffer = new Token(string[finiteControl++]);
				break;
			case '.':case '0':case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				buffer = new Token('8', number());
				break;
			case 'e':
				finiteControl++;
				buffer = new Token('8',  2.718281828459045);
				break;
			default:
				buffer = new Token('\0');
				break;
		}
	}

	double number() {
		short int state = 1;
		double acc = 0;
		int carry = 1;
		while(true) {
			state = transite_number_automaton(state);
			switch(state) {
				case 2:
					break;
				case 3:
				case 4:
					acc = 10*acc + (string[finiteControl]-'0');
					break;
				case 5:
					return 0;
				case 6:
					return acc/carry;
				case 7:
					acc = 10*acc + (string[finiteControl]-'0');
					carry *= 10;
					break;
			}
			finiteControl++;
		}
	}

	short int transite_number_automaton(short int state) {
		switch(state) {
			case 1:
				if (string[finiteControl] == '.')
					return 2;
				if ('0' <= string[finiteControl] && string[finiteControl] <= '9')
					return 3;
				return 5;
			case 2:
				if ('0' <= string[finiteControl] && string[finiteControl]  <= '9')
					return 7;
				return 6;
			case 3:
				if ('0' <= string[finiteControl]  && string[finiteControl]  <= '9')
					return 3; 
				if (string[finiteControl] == '.')
					return 2;
				return 6;
			case 4:
				if ('0' <= string[finiteControl] && string[finiteControl] <= '9')
					return 4;
				return 6;
			case 7:
				if ('0' <= string[finiteControl] && string[finiteControl] <= '9')
					return 7;
				return 6;
			default:
				return 5;
		}
	}

	Token* get() {
		return buffer;
	}
};

