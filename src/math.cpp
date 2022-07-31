double ln(double argument)
{
    return 0;
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
double powi(double x, int y) {
	  int result = 1;
	  int sign = y > 0 ? 1 : -1;
	  y = sign*y;
	  while (y > 0) {
		if ((y & 1) == 1)
			result *= x;
		x=x*x;
		y >>= 1;
	  }
	  if (sign<0) {
		  return (double)1/result;
	  }
	  return result;
}

// left**exponent = x
// logb(x)-exponent=0; it solves with root finder like Newton-Rapshon method.
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
	double fracc = ny-y;
	bool isInt = fracc == 0;
	double pow_int = powi(x, ny);
	if (isInt)
		return pow_int;
	// how?
	double xn = x*0.25;
	fracc = abs(1/fracc);
	for(int i=0; i<1000; i++)
		xn = xn-(powi(xn, fracc)-x)/(fracc*powi(xn, fracc-1));
	return pow_int*xn;
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
	return 1;
}


double floor(double n) {
	if (n>=0)
		return int(n);
	int m=int(n);
	return n-m == 0 ? m : m-1;
}
