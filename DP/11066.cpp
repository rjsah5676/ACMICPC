#include<iostream>
#include<algorithm>
using namespace std;

int dp[502][502];
int sum[502];
int nv[502];
int main()
{
	int t,k,i,j;
	cin>>t;

	while(t--){
		cin>>k;
		for(i=1;i<=k;i++){
			cin>>nv[i];
			sum[i]=sum[i-1]+nv[i];
		}
		for(i=1;i<k;i++){
			for(int tx=1;tx+i<=k;tx++){
				int ty = tx+i;
				dp[tx][ty]=2100000000;
				for(int mid=tx;mid<ty;mid++){
					dp[tx][ty]= min(dp[tx][ty], dp[tx][mid]+dp[mid+1][ty]+sum[ty]-sum[tx-1]);
				}
			}
		}
		cout<<dp[1][k]<<"\n";
	}
	return 0;
}
