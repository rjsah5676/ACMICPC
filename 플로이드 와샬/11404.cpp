#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int v[102][102];

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			v[i][j]=1e9;
		}
	}
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		if(v[a-1][b-1]>c) v[a-1][b-1]=c;
	}
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i][k]!=1e9 && v[k][j]!=1e9)
					v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			if(i==j) printf("0 ");
			else if(v[i][j]==1e9)printf("0 ");
			else printf("%d ",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
