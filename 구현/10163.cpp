#include<iostream>
#include<string.h>
using namespace std;

int x[1002][1002];
int res[101];
int main()
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++) {
		++cnt;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int p=a;p<c+a;p++)
			for(int q=b;q<d+b;q++)
				x[1001-p][1001-q]=cnt;
	}
	for(int i=0;i<=1001;i++)
		for(int j=0;j<=1001;j++)
			res[x[i][j]]++;
	for(int i=1;i<=n;i++) cout<<res[i]<<endl;
	return 0;
}
