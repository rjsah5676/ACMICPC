#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int dp[2][1001]={0,};
	int a[1001];
	int ans=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	dp[0][1]=1;
	dp[1][n]=1;
	for(i=2;i<=n;i++) {
		dp[0][i]=1;
		for(j=1;j<i;j++)
			if(a[i]>a[j])
				dp[0][i]=max(dp[0][j]+1,dp[0][i]);
	}
	for(i=n-1;i>0;i--) {
		dp[1][i]=1;
		for(j=i+1;j<=n;j++)
			if(a[i]>a[j])
				dp[1][i]=max(dp[1][j]+1,dp[1][i]);
	}
	for(i=1;i<=n;i++)
		ans=max(ans,dp[0][i]+dp[1][i]);
	cout<<ans-1;
}