#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[16][1<<16];
int mat[16][16] = {0,};
int n,start=0;
int res=2100000000;
int DFS(int cur, int visited)
{
	if(visited == (1<<n)-1){
		if(mat[cur][start] == 0) return 2100000000;
		else return mat[cur][start];
	}
	if(dp[cur][visited] != -1) return dp[cur][visited];
	dp[cur][visited]=2100000000;
	for(int i=0;i<n;i++){
		if(visited & (1<<i)) continue;
		if(mat[cur][i] == 0) continue;
		dp[cur][visited] = min(dp[cur][visited], mat[cur][i]+DFS(i, visited | 1<<i));
	}
	return dp[cur][visited];
}

int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>mat[i][j];
	memset(dp, -1, sizeof(dp));
	cout<<DFS(0,1)<<"\n";
	return 0;
}
