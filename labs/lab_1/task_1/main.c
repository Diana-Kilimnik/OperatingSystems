#include <stdio.h>
#include "function.h"

double curveLength(double a, double b, int n);

int main(void){
	int n;
	double a, b, length;
	float af, bf;
	
	e = 0.05;

	printf("Enter a (first point) = ");
	scanf("%f", &af);
	a = (double) af;
	printf("Enter b (last point) = ");
	scanf("%f", &bf);
	b = (double) bf;
	printf("Enter n = ");
	scanf("%d", &n);
	
	length = curveLength(a, b, n);	
	printf("Curve length = %.2f\n", length);
	
	return(EXIT_SUCCESS);	
}
