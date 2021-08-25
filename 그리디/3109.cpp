#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

char info[10001][501];
int visit[10001][501];

int dx[3]={1,1,1};
int dy[3]={-1,0,1};

int r, c;
int res=0;

int dfs(int sv, int row)
{
	visit[sv][row] = 1;
	if(row==c-1) {
		return 1;
	}
	for(int i=0;i<3;i++) {
		int nx = row + dx[i];
		int ny = sv + dy[i];
		if(nx>=0 && nx<c && ny>=0 && ny<r) {
			if(!visit[ny][nx] && info[ny][nx] == '.') {
				int flag = dfs(ny, nx);
				if(flag) return flag;
			}
		}
	}
	return 0;
}

int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++) {
		cin>>info[i];
	}
	for(int i=0;i<r;i++) {
		res += dfs(i,0);
	}
	cout<<res;
	return 0;
}
