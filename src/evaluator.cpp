class Token {
public:
	char kind;
	double value;
	Token(char kind, double value=0): kind(kind), value(value) {} 
};


class Evaluator {
private:
	int finiteControl = 0;
	int c = 0;
	const char* string;
	Token* token = NULL;
public:
	Evaluator(const char* expression): string(expression) {}	

        void parseToken() {
		switch(string[finiteControl]) {
			case '!':
			case '-': 
			case '(': 
			case ')': 
			case '+': 
			case '*': 
			case '/': 
			case '%':
				token = new Token(string[finiteControl]);
				break;
			case '.':case '0':case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				token = new Token('8', number());
				break;
			case 'e':
				finiteControl++;
				token = new Token('8',  2.718281828459045);
				break;
			default:
				token = new Token('\0');
				break;
		}
	}

	~Evaluator() {
		delete token;
	}


	double evaluate() {
		return expression();
	}

	double expression() {
		double left = term();
		parseToken();
		while(true) {
			switch (token->kind) {
				case '+':
					finiteControl++;
					left += term();
					parseToken();
					break;
				case '-':
					finiteControl++;
					left -= term();
					parseToken();
					break;
				default:
					return left;
			}
		}
	}

	double term() {
		double left = primary();
		parseToken();
		while(true) {
			switch(token->kind) {
				case '*': 
				{
					finiteControl++;
					double op = primary();
					parseToken();
					left *= op;
					break;
				}
				case '/': 
				{
					finiteControl++;
					double d = primary();
					if (d==0) return 0;
					left /= d;
					parseToken();
					break;
				}
				case '%':
				{
				        finiteControl++;
					double denominator = primary();
					left = left - int(left/denominator)*denominator;
					parseToken();
					break;
				}
				case '!':
				{
					finiteControl++;
					if (left == 0)
						left = 1;
					for(int i=left-1; i>0; i--)
						left *= i;
					parseToken();
					break;
				}
				default:
					return left;
			}
		}
	}

	double primary() {
		parseToken();
		switch(token->kind) {
			case '(':
			{
				finiteControl++;
				double d = expression();
				parseToken();
				finiteControl++;
				if (token->kind != ')') return 0;
				return d;
			}
			case '8':
				return token->value;
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
};

