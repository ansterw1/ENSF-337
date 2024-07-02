#include <stdio.h>
#include <math.h>
int main()
{
	double z = 0;
	double x = 2.5;
	double y = -1.5;
	int m = 18;
	int n = 4;
	
	z = x + n * y - (x + n) * y;
	printf("%f\n", z);
	
	z = m / n + m % n;
	printf("%f\n", z);
	
	z = n / m + n % m;
	printf("%f\n", z);
	
	z = 5 * x - n / 5;
	printf("%f\n", z);
	
	z = 1 - ( 1 - ( 1 - ( 1 - ( 1 - n ) ) ) );
	printf("%f\n", z);
	
	z = sqrt(sqrt((double)n));
	printf("%f\n", z);
	
	return 0;
}