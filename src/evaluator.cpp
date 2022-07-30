#include "token_stream.cpp"


class Evaluator {
private:
	TokenStream* tokenStream = NULL;
public:
	Evaluator(const char* expression) {
		tokenStream = new TokenStream(expression);
	}	

	double evaluate() {
		return expression();
	}

	double expression() {
		double left = term();
		tokenStream->next();
		while(true) {

			switch (tokenStream->get()->kind) {
				case '+':
					left += term();
					tokenStream->next();
					break;
				case '-':
					left -= term();
					tokenStream->next();
					break;
				default:
					tokenStream->putback();
					return left;
			}
		}
	}

	double term() {
		double left = primary();
		tokenStream->next();
		while(true) {
			switch(tokenStream->get()->kind) {
				case '*': 
				{
					double op = primary();
					left *= op;
					tokenStream->next();
					break;
				}
				case '/': 
				{
					double d = primary();
					if (d==0) return 0;
					left /= d;
					tokenStream->next();
					break;
				}
				case '%':
				{
					double denominator = primary();
					left = left - int(left/denominator)*denominator;
					tokenStream->next();
					break;
				}
				case '!':
				{
					if (left == 0)
						left = 1;
					for(int i=left-1; i>0; i--)
						left *= i;
					tokenStream->next();
					break;
				}
				default:
				        tokenStream->putback();
					return left;
			}
		}
	}

	double primary() {
		tokenStream->next();
		switch(tokenStream->get()->kind) {
			case '(':
			{
				double d = expression();
				tokenStream->next();
				if (tokenStream->get()->kind != ')') return 0;
				return d;
			}
			case '8':
				return tokenStream->get()->value;
			case '-': 
			{
				return -primary();
			}
			case '+':
			        return primary();
			default:
				return 0;
		}
	}
	
};

