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


// left**exponent = x
// logb(x)-exponent=0; it solves with root finder like Newton-Rapshon method.
double pow(double base, double exponent) {
	return 4;
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

