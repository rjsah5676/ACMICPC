#include<iostream>
#include<algorithm>
using namespace std;

int n,w;
int chora[2][10002];
int cs[3][10002];

void f()
{
	if(chora[0][0]+chora[1][0]<=w) {
			cs[0][0]=cs[1][0]=cs[2][0]=1;
	}
	else {
		cs[0][0]=2;
		cs[1][0]=cs[2][0]=1;
	}
	for(int i=1;i<n;i++) {
		cs[0][i] = cs[0][i-1]+2;
		cs[1][i] = cs[2][i] = cs[0][i-1]+1;
		if(chora[0][i]+chora[0][i-1]<=w) {
			cs[1][i]=min(cs[1][i], cs[2][i-1]+1);
		}
		if(chora[1][i]+chora[1][i-1]<=w){
			cs[2][i]=min(cs[2][i], cs[1][i-1]+1);
		}
		cs[0][i] = min(cs[0][i],cs[1][i]+1);
		cs[0][i] = min(cs[0][i],cs[2][i]+1);
		if(chora[0][i]+chora[1][i]<=w){
			cs[0][i]=min(cs[0][i],cs[0][i-1]+1);
		}
		if(chora[0][i]+chora[0][i-1]<=w && chora[1][i]+chora[1][i-1]<=w) {
			if(i>1) cs[0][i]=min(cs[0][i],cs[0][i-2]+2);
			else cs[0][i]=min(cs[0][i],2);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>w;
		for(int i=0;i<2;i++) for(int j=0;j<n;j++) cin>>chora[i][j];
		int res;
		f();
		res = cs[0][n-1];
		if(n>1) {
			if(chora[1][0]+chora[1][n-1]<=w) {
				int tmp1 = chora[1][0];
				int tmp2 = chora[1][n-1];
				chora[1][0]=chora[1][n-1]=w;
				f();
				res=min(res,cs[1][n-1]);
				chora[1][0]=tmp1;
				chora[1][n-1]=tmp2;
			}
			if(chora[0][0]+chora[0][n-1]<=w) {
				int tmp1 = chora[0][0];
				int tmp2 = chora[0][n-1];
				chora[0][0]=chora[0][n-1]=w;
				f();
				res=min(res,cs[2][n-1]);
				chora[0][0]=tmp1;
				chora[0][n-1]=tmp2;
			}
			if(chora[0][0]+chora[0][n-1]<=w&&chora[1][0]+chora[1][n-1]<=w) {
				int tmp1=chora[0][0];
				int tmp2=chora[0][n-1];
				int tmp3=chora[1][0];
				int tmp4=chora[1][n-1];
				chora[0][0]=chora[0][n-1]=w;
				chora[1][0]=chora[1][n-1]=w;
				f();
				res=min(res,cs[0][n-2]);
				chora[0][0]=tmp1;
				chora[0][n-1]=tmp2;
				chora[1][0]=tmp3;
				chora[1][n-1]=tmp4;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
