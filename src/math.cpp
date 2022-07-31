float __int_as_float (int32_t a) { float r; memcpy (&r, &a, sizeof r); return r;}
int32_t __float_as_int (float a) { int32_t r; memcpy (&r, &a, sizeof r); return r;}

float fmaf(float x,float y, float z) {
	return (x*y) + z;
}

float ln(double a)
{
    float m, r, s, t, i, f;
    int32_t e;

    e = (__float_as_int (a) - 0x3f2aaaab) & 0xff800000;
    m = __int_as_float (__float_as_int (a) - e);
    i = (float)e * 1.19209290e-7f; // 0x1.0p-23
    /* m in [2/3, 4/3] */
    f = m - 1.0f;
    s = f * f;
    /* Compute log1p(f) for f in [-1/3, 1/3] */
    r = fmaf (0.230836749f, f, -0.279208571f); // 0x1.d8c0f0p-3, -0x1.1de8dap-2
    t = fmaf (0.331826031f, f, -0.498910338f); // 0x1.53ca34p-2, -0x1.fee25ap-2
    r = fmaf (r, s, t);
    r = fmaf (r, s, f);
    r = fmaf (i, 0.693147182f, r); // 0x1.62e430p-1 // log(2) 
    return r;
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
double pow(double x, int y) {
	  int result = 1;
	  int sign = y > 0 ? 1 : -1;
	  y = sign*y;
	  while (y > 0) {
		if (y & 1 == 1)
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
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y == 2)
		return x*x;
	int ny = y;
	bool isInt = ny-y == 0;
	if (isInt)
		return pow(x, ny);
	// how?
	return 0.5;
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


double floor(double n) {
	if (n>=0)
		return int(n);
	int m=int(n);
	return n-m == 0 ? m : m-1;
}
