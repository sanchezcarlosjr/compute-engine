class Token {
public:
	char kind;
	double value;
	Token(char kind, double value=0): kind(kind), value(value) {} 
};


class Evaluator {
private:
	int finiteControl = 0;
	const char* string;
	Token* ctoken = NULL;
public:
	Evaluator(const char* expression): string(expression) {}	

        Token parseToken() {
		if(ctoken != NULL && ctoken->kind == '\0') {
			return *ctoken;
		}
		switch(string[finiteControl]) {
			case '!':
			case '-': 
			case '(': 
			case ')': 
			case '+': 
			case '*': 
			case '/': 
			case '%':
			case '\0':
				ctoken = new Token(string[finiteControl]);
				return *ctoken;
			case '.':case '0':case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				ctoken = new Token('8', number());
				return *ctoken;
			case 'e':
				finiteControl++;
				ctoken = new Token('8',  2.718281828459045);
				return *ctoken;
			default:
				return 0;
		}
	}


	double evaluate() {
		return expression();
	}

	double expression() {
		double left = term();
		Token token = parseToken();
		while(true) {
			switch (token.kind) {
				case '+':
					finiteControl++;
					left += term();
					token = parseToken();
					break;
				case '-':
					finiteControl++;
					left -= term();
					token = parseToken();
					break;
				default:
					return left;
			}
		}
	}

	double term() {
		double left = primary();
		Token token = parseToken();
		while(true) {
			switch(token.kind) {
				case '*': 
				{
					finiteControl++;
					double op = primary();
					token = parseToken();
					left *= op;
					break;
				}
				case '/': 
				{
					finiteControl++;
					double d = primary();
					if (d==0) return 0;
					left /= d;
					token = parseToken();
					break;
				}
				case '%':
				{
				        finiteControl++;
					double denominator = primary();
					left = left - int(left/denominator)*denominator;
					token = parseToken();
					break;
				}
				case '!':
				{
					finiteControl++;
					if (left == 0)
						left = 1;
					for(int i=left-1; i>0; i--)
						left *= i;
					token = parseToken();
					break;
				}
				default:
					return left;
			}
		}
	}

	double primary() {
		Token token = parseToken();
		switch(token.kind) {
			case '(':
			{
				finiteControl++;
				double d = expression();
				token = parseToken();
				finiteControl++;
				if (token.kind != ')') return 0;
				return d;
			}
			case '8':
				return token.value;
			case '-': 
			{
				finiteControl++;
				return -primary();
			}
			default:
				return 0;
		}
	}
	
	double number() {
		short int state = 1;
		double acc = 0;
		short int sign = 1;
		int carry = 1;
		while(true) {
			state = transite_number_automaton(state);
			switch(state) {
				case 1:
					sign = -sign;
					break;
				case 2:
					break;
				case 3:
				case 4:
					acc = 10*acc + (string[finiteControl]-'0');
					break;
				case 5:
					return 0;
				case 6:
					return sign*acc/carry;
				case 7:
					acc = 10*acc + (string[finiteControl]-'0');
					carry *= 10;
					break;
			}
			finiteControl++;
		}
	};
	short int transite_number_automaton(short int state) {
		switch(state) {
			case 1:
				if (string[finiteControl] == '-')
					return 1;
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
};

