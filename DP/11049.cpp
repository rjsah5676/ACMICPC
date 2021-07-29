#include<iostream>
#include<algorithm>
using namespace std;

struct mat{
	int row,col,res;
};

mat dp[501][501];
int main()
{
	int n,i,j,k,a,b;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		dp[i][i].row=a;
		dp[i][i].col=b;
		dp[i][i].res=0;
	}
	for(i=1;i<n;i++){
		for(j=1;j<=n-i;j++){
			int p=j;
			int q=j+i;
			dp[p][q].res=2147483647;
			for(k=p;k<q;k++){
				dp[p][q].res=min(dp[p][k].res+dp[k+1][q].res+(dp[p][k].row*dp[p][k].col*dp[k+1][q].col),dp[p][q].res);
				dp[p][q].row=dp[p][k].row;
				dp[p][q].col=dp[k+1][q].col;
			}
		}
	}
	cout<<dp[1][n].res;
	return 0;
}
