#include "../function.h"

int factorialX (int arg){
	return (arg < 2) ? 1 : arg * factorialX (arg - 1);
}

double lineLength(double x1, double x2, double y1, double y2){
	return sqrt((pow((x2-x1),2)+(pow((y2-y1),2))));
}

double sinX(double x){
	int i = 0;
	double sum = 0;
	while (1){
		double summand = (pow((-1), i) * pow(x,((2*i)+1)))/factorialX(2*i+1);
		sum += summand;	
		i++;
		if (abs(summand) < e) break;	
	}
	return sum;
}


double cosX(double x){
	int i = 0;
	double sum = 0;
	while (1){
		double summand = (pow((-1), i) * pow(x,(2*i)))/ factorialX(2*i);
		sum += summand;
		i++;
		if (abs(summand) < e) break;	
	}
	return sum;
}

double curveLength(double a, double b, int n){
	double length = 0, partLength, x0, x1, y0, y1;
	int i;	

	partLength = (b - a)/n;	
	x0 = a;
	x1 = a + partLength;
	y0 = yCoordinate(x0);
	y1 = yCoordinate(x1);
	for (i = 0; i < n; i++){
		x1 = x0 + partLength;
		y1 = yCoordinate(x1);
		double partialResult = lineLength(x0, x1, y0, y1);
		length += partialResult;
		x0 = x1;
		y0 = y1;
	}	
	return length;
}

double yCoordinate(double x){
	double y;
	y = pow(sinX(x),2)/(1 + pow(cosX(x),3));
	return y;
}