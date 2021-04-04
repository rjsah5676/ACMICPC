//2004
//https://www.acmicpc.net/problem/2004
//math

#include<stdio.h>

long long divide(long long n, long long div)
{
	long long cnt = 0;
	for(long long i=div; i<=n; i*=div)
		cnt += n / i;
	return cnt;
}

int main()
{
	long long n, m;
	scanf("%lld %lld",&n,&m);
	long long num_2 = divide(n, 2) - divide(m, 2) - divide(n-m,2);
	long long num_5 = divide(n, 5) - divide(m, 5) - divide(n-m,5);
	num_2 < num_5 ? printf("%lld",num_2):printf("%lld",num_5);
}
