#include<stdio.h>
#include<algorithm>
using namespace std;
int c[302];
int dp[302];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&c[i]);
	dp[0] = c[0];
	dp[1] = c[0]+c[1];
	dp[2] = max(c[0]+c[2], c[1]+c[2]);
	for(int i = 3; i <= n; i++)
			dp[i] = max(dp[i-2]+c[i], dp[i-3]+c[i-1]+c[i]);
	printf("%d",dp[n]);
}