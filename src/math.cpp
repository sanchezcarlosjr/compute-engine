double dabs(double argument) {
	return argument > 0 ? argument : -argument;
}


double sqrt(double x) {
	double xn = x;
	double a = 0;
	do {
	  a = xn;
	  xn = (xn+x/xn)/2;
	} while (dabs(a-xn) > 0.0000000000000001);
	return xn;
}

double ln(double a) {
    double w = a, prod = 1;
    int n = 1;
    double acc = 0;
    double e2 = 2;
    do {
        w = sqrt(w);
        prod *= 1 + w;
        acc = (e2*(a-1))/prod;
	e2 *= 2;
        n++;
    } while(dabs(w-1) > 0.0000000000001);
    return acc;
}


double exp(double x) {
	double acc = 1;
	double fact = 1;
	double o = x;
	int n = 1;
	do {
		fact *= n;
		acc += x/fact;
		x = x * o;
		n++;
	} while (n<=7547);
	return acc;
}


// TODO: Gamma function
double factorial(double n) {
	if (n==0)
		n = 1;
	for(int i=n-1; i>0; i--)
		n = n*i;
	return n;
}

double mod(double n, double denominator) {
	return n - int(n/denominator)*denominator;
}


// https://en.wikipedia.org/wiki/Exponentiation_by_squaring
double ipow(double base, int exponent) {
	  double result = 1;
	  double sign = exponent > 0 ? 1 : -1;
	  exponent = sign*exponent;
	  while (exponent > 0) {
		if (exponent & 1)
			result *= base;
		base=base*base;
		exponent >>= 1;
	  }
	  if (sign<0) {
		  return (double)1/result;
	  }
	  return result;
}

double pow(double x, double y) {
	if (x == 0 && y != 0)
		return 0;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y == 2)
		return x*x;
	int ny = y;
	double fracc = dabs(ny-y);
	bool isInt = fracc == 0;
	double pow_int = ipow(x, ny);
	if (isInt)
		return pow_int;
	// how?
	if (fracc == 0.5)
		return pow_int*sqrt(x);
	return pow_int*exp(fracc*ln(x));
}

double cos(double argument) {
	return 1;
}

const double ratio = 1.618033988749895;
const double sqrt5 = 2.2360679775;
int fib(int n) {
	return int((pow(ratio,n)/sqrt5)+0.5);
}

double sin(double n) {
	return 1;
}

double log(double base, double argument) {
	return ln(argument)/ln(base);
}


double floor(double n) {
	if (n>=0)
		return int(n);
	int m=int(n);
	return n-m == 0 ? m : m-1;
}
