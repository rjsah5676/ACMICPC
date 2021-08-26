#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int v[102][102];

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		v[a-1][b-1]=1;
		v[b-1][a-1]=-1;
	}
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i][k]==v[k][j] && v[i][k]!=0)
					v[i][j]=v[i][k];
			}
		}
	}
	for(int i=0;i<n;i++){
		int cnt=n-1;
		for(int j=0;j<n;j++) if(v[i][j]!=0)cnt--;
		cout<<cnt<<endl;
	}
	return 0;
}
