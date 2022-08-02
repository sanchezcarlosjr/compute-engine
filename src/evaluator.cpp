#include "token_stream.cpp"
#include "math.cpp"

class Evaluator {
private:
    TokenStream *tokenStream = NULL;
public:
    Evaluator(const char *expression) {
        tokenStream = new TokenStream(expression);
    }

    double evaluate() {
        double left = precedence5();
        tokenStream->next();
        while (true) {
            switch (tokenStream->get()->kind) {
                case ';': {
                    double temporal = precedence5();
                    left = temporal == 0 ? left : temporal;
                    tokenStream->next();
                    break;
                }
                default:
                    return left;
            }
        }
    }

    double precedence5() {
        double left = precedence4();
        tokenStream->next();
        while (true) {
            switch (tokenStream->get()->kind) {
                case '+':
                    left += precedence4();
                    tokenStream->next();
                    break;
                case '-':
                    left -= precedence4();
                    tokenStream->next();
                    break;
                default:
                    tokenStream->putback();
                    return left;
            }
        }
    }

    double precedence4() {
        double left = precedence3();
        tokenStream->next();
        while (true) {
            switch (tokenStream->get()->kind) {
                case '*': {
                    double op = precedence3();
                    left *= op;
                    tokenStream->next();
                    break;
                }
                case '/': {
                    double d = precedence3();
                    if (d == 0) return 0;
                    left /= d;
                    tokenStream->next();
                    break;
                }
                case '%': {
                    double denominator = precedence3();
                    left = mod(left, denominator);
                    tokenStream->next();
                    break;
                }
                default:
                    tokenStream->putback();
                    return left;
            }
        }
    }

    double precedence3() {
        double left = precedence2();
        tokenStream->next();
        while (true) {
            switch (tokenStream->get()->kind) {
                case POW: {
                    double exponent = precedence2();
                    left = pow(left, exponent);
                    tokenStream->next();
                    break;
                }
                default:
                    tokenStream->putback();
                    return left;
            }
        }
    }

    double precedence2() {
        double left = precedence1();
        tokenStream->next();
        while (true) {
            switch (tokenStream->get()->kind) {
                case '!': {
                    left = factorial(left);
                    tokenStream->next();
                    break;
                }
                default:
                    tokenStream->putback();
                    return left;
            }
        }
    }


    double precedence1() {
        tokenStream->next();
        switch (tokenStream->get()->kind) {
            case '(': {
                double d = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return d;
            }
            case COS: {
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return cos(argument);
            }
            case FIB: {
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return fib(argument);
            }
            case SIN: {
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return sin(argument);
            }
            case LN: {
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return ln(argument);
            }
            case SQRT: {
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return sqrt(argument);
            }
            case LOG: {
                tokenStream->next();
                double base = tokenStream->get()->value;
                if (tokenStream->get()->kind != NUMBER)
                    base = 10;
                tokenStream->next();
                if (tokenStream->get()->kind != '(') return 0;
                double argument = precedence5();
                tokenStream->next();
                if (tokenStream->get()->kind != ')') return 0;
                return log(base, argument);
            }
            case NUMBER:
                return tokenStream->get()->value;
            case '-':
                return -precedence1();
            case '+':
                return precedence1();
            default:
                return 0;
        }
    }

};

