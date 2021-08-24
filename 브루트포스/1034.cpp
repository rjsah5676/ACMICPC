#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

string lamp[51];
int n,m,k;
int res;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>lamp[i];
	cin>>k;
	for(int i=0;i<n;i++) {
		int zcnt=0;
		for(int j=0;j<m;j++) if(lamp[i][j]=='0') zcnt++;
		if(zcnt>k || (zcnt-k)%2) continue;
		int cnt=0;
		for(int j=0;j<n;j++) {
			if(lamp[i]==lamp[j]) cnt++;
		}
		res=max(res, cnt);
	}
	cout<<res;
	return 0;
}
