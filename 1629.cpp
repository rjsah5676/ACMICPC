//1629
//divide and conquer

#include<stdio.h>

long long c;

long long pow(long long a, long long b)
{
	if(!b) return 1;
	if(b==1) return a;
	if(b%2 == 1) return a*pow(a,b-1);
	long long h = pow(a, b/2);
	h %= c;
	return (h*h)%c;
}

int main()
{
	long long a,b;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld",pow(a,b)%c);
}
