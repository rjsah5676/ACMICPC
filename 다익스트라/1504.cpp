#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int> > dijk[802];
int n,e;
int v1,v2;

int dijkstra(int x, int y)
{
	int mindist[802];
	for(int i=1;i<=n;i++) mindist[i]=1e9;
	mindist[x]=0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(x,0));
	while(!pq.empty()) {
		int cur=pq.top().first;
		int cur_dist=-pq.top().second;
		pq.pop();
		if(mindist[cur]<cur_dist) continue;
		for(int i=0;i<dijk[cur].size();i++) {
			int next=dijk[cur][i].first;
			int next_dist=dijk[cur][i].second+cur_dist;
			if(next_dist < mindist[next]) {
				mindist[next] = next_dist;
				pq.push(make_pair(next, -next_dist));
			}
		}
	}
	if(mindist[y] == 1e9) return -1;
	return mindist[y];
}

int main()
{
	cin>>n>>e;
	for(int i=0;i<e;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		dijk[a].push_back(make_pair(b,c));
		dijk[b].push_back(make_pair(a,c));
	}
	cin>>v1>>v2;
	int res[6];
	res[0]=dijkstra(1,v1);
	res[1]=dijkstra(v1,v2);
	res[2]=dijkstra(v2,n);
	res[3]=dijkstra(1,v2);
	res[4]=dijkstra(v2,v1);
	res[5]=dijkstra(v1,n);
	int flag1=0;
	int flag2=0;
	for(int i=0;i<6;i++) {
		if(i<3) {
			if(res[i]==-1) flag1=1;
		}
		else {
			if(res[i]==-1) flag2=1;
		}
	}
	if(flag1 && flag2) cout<<-1;
	else if(flag1 && !flag2) {
		cout<<res[3]+res[4]+res[5];
	}
	else if(!flag1 && flag2) {
		cout<<res[0]+res[1]+res[2];
	}
	else {
		cout<<min(res[0]+res[1]+res[2], res[3]+res[4]+res[5]);
	}
	return 0;
}
