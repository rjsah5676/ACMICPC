#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};
int n;
int shark[21][21];
int visit[21][21];
int time=0;
int eat=0;
int sz=2;
queue<pair<pair<int, int>, int> > q;
vector<pair<pair<int, int>, int> > vt;
void bfs(int x, int y)
{
	q.push(make_pair(make_pair(x,y), 0));
	visit[y][x] = 1;
	while(!q.empty()){
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cur_time = q.front().second;
		q.pop();
		if(shark[cur_y][cur_x] != 0 && shark[cur_y][cur_x] != 9 && shark[cur_y][cur_x]<sz) {
			vt.push_back(make_pair(make_pair(cur_x,cur_y), cur_time));
		}
		for(int i=0;i<4;i++) {
			int nx=cur_x+dx[i];
			int ny=cur_y+dy[i];
			int nt=cur_time+1;
			if(nx<0||nx>=n||ny<0||ny>=n||visit[ny][nx]||shark[ny][nx]>sz) continue;
			q.push(make_pair(make_pair(nx,ny), nt));
			visit[ny][nx]=1;
		}
	}
}

int main()
{
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			int inp;
			cin>>inp;
			if(inp==9) {
				x=j;
				y=i;
				shark[i][j]=0;
			}
			else
				shark[i][j]=inp;
		}
	bfs(x,y);
	while(vt.size()) {
		int minv=2e9;
		for(int i=0;i<vt.size();i++) {
			minv=min(minv,vt[i].second);
		}
		int sx=2e9;
		int sy=2e9;
		for(int i=0;i<vt.size();i++) {
			if(vt[i].second == minv) {
				if(vt[i].first.second<sy) {
					sy=vt[i].first.second;
				}
			}
		}
		for(int i=0;i<vt.size();i++) {
			if(vt[i].second == minv) {
				if(vt[i].first.second == sy) {
					if(vt[i].first.first < sx) {
						sx=vt[i].first.first;
					}
				}
			}
		}
		time+=minv;
		eat+=1;
		if(eat==sz) {
			eat=0;
			sz+=1;
		}
		memset(visit,0,sizeof(visit));
		shark[sy][sx]=0;
		vt.clear();
		bfs(sx,sy);
	}
	cout<<time;
	return 0;
}
