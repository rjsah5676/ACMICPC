#include<stdio.h>

int main()
{
	int n;
	int a[1001];
	int dp[1001]={0,};
	int m,r=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		int dpm=0;
		for(int j=0;j<i;j++) {
			if(a[j]<a[i]&&dp[j]>=dpm)
				dpm=dp[j];
		}
		dp[i]=dpm+1;
		if(dp[i]>r)
			r=dp[i];
	}
	printf("%d",r);
}