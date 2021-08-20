#include<iostream>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

int res=-1;
int n;
struct strt{
	int bitF;
	int start;
	int end;
	int cost;
};

int cost[17][17];
int visit[17][(1<<17)+1][10]={0,};

queue<strt> que;

void bfs()
{
	strt t;
	t.bitF = 1;
	t.start = 1;
	t.cost = 0;
	t.end = 1;
	que.push(t);
	while(!que.empty()) {
		strt cur = que.front();
		que.pop();
		for(int i=1;i<=n;i++) {
			if(cur.cost > cost[cur.start][i] || cur.bitF & 1<<(i-1) || visit[i][cur.bitF][cur.cost]) {
				res = res > cur.end ? res : cur.end;
				continue;
			}
			strt p;
			p.end = cur.end + 1;
			p.bitF = cur.bitF | 1<<(i-1);
			p.start = i;
			p.cost = cost[cur.start][i];
			que.push(p);
			visit[i][cur.bitF][p.cost] = 1;
		}
	}
}

int main()
{
	cin>>n;
	char x[17];
	for(int i=1;i<=n;i++) {
		cin>>x;
		for(int j=1;j<=n;j++) cost[i][j]=x[j-1]-'0';
	}
	bfs();
	cout<<res;
	return 0;
}
