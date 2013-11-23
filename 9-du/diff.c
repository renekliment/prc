#include <stdio.h>
#include <math.h>

#define f(x) exp(-2*x*x)
#define DOUBLE_PRECISION 0.0000000001

enum {
	ST_OK = 0,
	ST_WRONG_PARAM_N = 1,
	ST_WRONG_PARAMS = 2,
	ST_FOPEN_ERROR = 3
};

int main(int argc, char **argv)
{
	if (argc != 4) return ST_WRONG_PARAM_N;

	double a, b, h;

	sscanf(argv[1], "%lf", &a);
	sscanf(argv[2], "%lf", &b);
	sscanf(argv[3], "%lf", &h);

	// not so secure
	if (h <= 0) return ST_WRONG_PARAMS;
	// not so secure either
	if (a > b || fabs(a - b) < DOUBLE_PRECISION) return ST_WRONG_PARAMS;

	FILE *out;
	out = fopen("vystup", "w");

	if (out == NULL) return ST_FOPEN_ERROR;

	double x;
	double fx;
	double fx_prev = f(a);
	double fx_next = f((a+h));
	double d, d2;

	// a, f(a), f'(a+h), f''(a+h)
	fprintf(out, "%.10lf %.10lf %.10lf %.10lf\n",
		a,
		fx_prev,
		( f((a+2*h)) - fx_prev )/( 2*h ),
		( f((a+2*h)) - 2*fx_next + fx_prev )/( h*h )
	);

	for (x = a + h; x < b; x += h) {
		fx = fx_next;
		fx_next = f((x+h));
		d = ( fx_next - fx_prev )/( 2*h );
		d2 = ( fx_next - 2*fx + fx_prev )/( h*h );

		fx_prev = fx;

		fprintf(out, "%.10lf %.10lf %.10lf %.10lf\n", x, fx, d, d2);
	}

	// b, f(b), f'(b+h), f''(b+h)
	//fprintf(out, "%.10lf %.10lf %.10lf %.10lf", b, f(b), d, d2);

	fclose(out);

	return ST_OK;
}