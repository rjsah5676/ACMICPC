//12865
//https://www.acmicpc.net/problem/12865
//dp,knapsack

#include<stdio.h>

struct knap {
	int value;
	int weight;
};

int main()
{
	int n,k,i,j;
	int max=-1;
	knap x[101];
	int dp[101][100001];
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i].weight,&x[i].value);
	}
	for(i=0;i<=n;i++)dp[i][0]=0;
	for(i=0;i<=k;i++)dp[0][i]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++){
			if(j>=x[i].weight){
				dp[i][j] = dp[i-1][j] > (dp[i-1][j-x[i].weight]+x[i].value) ? dp[i-1][j] : (dp[i-1][j-x[i].weight]+x[i].value);
			}
			else dp[i][j]=dp[i-1][j];
		}
	for(i=0;i<=n;i++) 
		for(j=0;j<=k;j++)
			max=max>dp[i][j]?max:dp[i][j];
	printf("%d",max);
}
