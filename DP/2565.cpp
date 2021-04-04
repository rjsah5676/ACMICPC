//2565
//https://www.acmicpc.net/problem/2565
//dp

#include<stdio.h>

int main()
{
	int n,a,b,i,j;
	int x[501]={0};
	int dp[501]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		x[a]=b;
	}
	int t=1;
	for(i=1;i<=500;i++){
		if(x[i] != 0) {
			dp[i]=1;
			t=i;
			break;
		}
	}
	int m;
	int r=1;
	for(i=t+1;i<=500;i++){
		m=0;
		if(x[i]!=0) {
			for(j=1;j<i;j++) {
				if(x[i]>x[j]) m=m>dp[j]?m:dp[j];
			}
			dp[i]=m+1;
			r=r>dp[i]?r:dp[i];
		}
	}
	printf("%d",n-r);
}
