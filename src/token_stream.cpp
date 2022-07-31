class Token {
public:
	char kind;
	double value;
	Token(char kind, double value=0): kind(kind), value(value) {} 
};


const char NUMBER = '0';
const char POW = '1';
const char PI = '2';
const char COS = '3';
const char FIB = '4';
const char DEG_TO_RAD = '5';
const char SIN = '6';
const char LN = '7';
const char LOG = '8';

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
		if (string[finiteControl] == 'c' && string[finiteControl+1] == 'o' && string[finiteControl+2] == 's') {
			finiteControl += 3;
			buffer = new Token(COS);
			return;
		}
		if (string[finiteControl] == 'f' && string[finiteControl+1] == 'i' && string[finiteControl+2] == 'b') {
			finiteControl += 3;
			buffer = new Token(FIB);
			return;
		}
		if (string[finiteControl] == 'p' && string[finiteControl+1] == 'i') {
			finiteControl += 2;
			buffer = new Token(NUMBER, 3.14159265358979);
			return;
		}
		if (string[finiteControl] == 'l' && string[finiteControl+1] == 'o' && string[finiteControl+2] == 'g') {
			finiteControl += 3;
			buffer = new Token(LOG);
			return;
		} 
		if (string[finiteControl] == 's' && string[finiteControl+1] == 'i' && string[finiteControl+2] == 'n') {
			finiteControl += 3;
			buffer = new Token(SIN);
			return;
		}
		if (string[finiteControl] == 'l' && string[finiteControl+1] == 'n') {
			finiteControl += 2;
			buffer = new Token(LN);
			return;
		}
		switch(string[finiteControl]) {
			case '*':
				if (string[finiteControl+1] == '*') {
					finiteControl += 2;
					buffer = new Token(POW);
					break;
				}
			case '!':
			case '-': 
			case '(': 
			case ')': 
			case '+': 
			case '/': 
			case '%':
				buffer = new Token(string[finiteControl++]);
				break;
			case '.':case '0':case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				buffer = new Token(NUMBER, number());
				break;
			case 'e':
				finiteControl++;
				buffer = new Token(NUMBER,  2.718281828459045);
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

