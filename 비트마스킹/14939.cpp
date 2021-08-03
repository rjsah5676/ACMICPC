#define MAX 10
#include<iostream>
#include<algorithm>
using namespace std;

int n=1<<30;
int bit[4]={n,n,n,n};
int tx[4]={0,0,1,-1};
int ty[4]={1,-1,0,0};
int arr[11][11];
int tmp[11][11];
int res=1e9;

void click(int x, int y){
	for(int i=0;i<4;i++){
		int dx=x+tx[i];
		int dy=y+ty[i];
		if(dx<0||dx>=MAX||dy<0||dy>=MAX) continue;
		tmp[dx][dy] = !tmp[dx][dy];
	}
	tmp[x][y] = !tmp[x][y];
}

int off(){
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(tmp[i][j]) return 0;
	return 1;
}

int main()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++){
			char c;
			cin>>c;
			if(c=='O')arr[i][j]=1;
		}
	for(int bit=0; bit<(1<<MAX);bit++){
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				tmp[i][j]=arr[i][j];
		int cnt=0;
		for(int i=0;i<MAX;i++){
			if(bit&(1<<i)){
				cnt++;
				click(0,i);
			}
		}
		for(int i=1;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if(tmp[i-1][j]){
					cnt++;
					click(i,j);
				}
			}
		}
		if(off()) res=min(res,cnt);
	}
	if(res==1e9) cout<<-1;
	else cout<<res;
	return 0;
}
