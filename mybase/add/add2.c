#include<stdio.h>

double add(double a,double b)
{
	return a+b;
}

double main()
{
	double a;
	double b;
	a=1.2;
	b=2.3;
	printf("%lf\n",add(a,b));
}
