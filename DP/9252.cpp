#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[1002][1002]={0,};
char a[1002];
char b[1002];

void p(int i,int j){
    if(dp[i][j]==0)return;
    if(a[i-1]==b[j-1]){
        p(i-1, j-1);
        cout<<a[i-1];
    }else dp[i-1][j]>dp[i][j-1]?p(i-1,j):p(i,j-1);
}

int main()
{
	cin>>a>>b;
	int al=strlen(a);
	int bl=strlen(b);
	for(int i=1;i<=al;i++){
		for(int j=1;j<=bl;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[al][bl]<<endl;
	p(al,bl);
	return 0;
}
