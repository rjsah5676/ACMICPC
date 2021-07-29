#include<iostream>
using namespace std;

int num[2002];
int dp[2002][2002];

int main()
{
	int i,j,s,e,n,m;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i];
		dp[i][i]=1;
	}
	for(i=1;i<n;i++){
		for(j=1;j<=n-i;j++){
			if(num[j]==num[j+i]){
				if(i>=2) {
					if(dp[j+1][j+i-1]==1)
						dp[j][j+i]=1;
				}
				else
					dp[j][j+i]=1;
			}
			else {
				dp[j][j+i]=0;
			}
		}
	}
	cin>>m;
	for(i=0;i<m;i++){
		scanf("%d %d",&s,&e);
		printf("%d\n", dp[s][e]);
	}
	return 0;
}
