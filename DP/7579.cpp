#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

int mem[101];
int cost[101];
int dp[10001];

int main()
{
	int i,j;
	int sc=0;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>mem[i];
	for(i=0;i<n;i++) {
		cin>>cost[i];
		sc+=cost[i];
	}
	for(i=0;i<n;i++) {
		for(j=sc;j>=cost[i];j--){
			dp[j]=max(dp[j],dp[j-cost[i]]+mem[i]);
		}
	}
	for(i=0;i<=10000;i++) {
		if(dp[i] >= m) {
			cout<<i;
			break;
		}
	}
	return 0;
}
