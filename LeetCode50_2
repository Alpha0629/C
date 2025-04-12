#include <stdio.h>

double myPow(double x, int n){
	long long N = n;
	if(n < 0){
		x = 1 / x;
		N = -N;
	}
	
	if(N == 0){
		return 1.0;
	}
	
	double y = myPow(x, N / 2);
	return (N % 2 == 0) ? y * y: y * y * x;
}

int main(){
	printf("%.5lf", myPow(2, 3));
	return 0;
}
