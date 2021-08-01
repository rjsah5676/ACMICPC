#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > dijk[5002];
int n,m;
int min_dist[5002];
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dijk[a].push_back(make_pair(b,c));
		dijk[b].push_back(make_pair(a,c));
	}
	for(j=1;j<=n;j++)min_dist[j]=2111111111;
	int s,t;
	cin>>s>>t;
	min_dist[s]=0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(s, min_dist[s]));
	while(!pq.empty()){
		int cur=pq.top().first;
		int dist=-pq.top().second;
		pq.pop();
		if(dist>min_dist[cur]) continue;
		for(i=0;i<dijk[cur].size();i++){
			int next=dijk[cur][i].first;
			int next_dist=dijk[cur][i].second+dist;
			if(next_dist<min_dist[next]){
				min_dist[next]=next_dist;
				pq.push(make_pair(next, -next_dist));
			}
		}
	}
	cout<<min_dist[t];
	return 0;
}
