#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > dijk[1002];
int n,m;
int min_dist[1002];
int nb[1002];
vector<short> res;
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dijk[a].push_back(make_pair(b,c));
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
				nb[next]=cur;
				min_dist[next]=next_dist;
				pq.push(make_pair(next, -next_dist));
			}
		}
	}
	int xx=t;
	while(xx){
		res.push_back(xx);
		xx=nb[xx];
	}
	cout<<min_dist[t]<<"\n";
	cout<<res.size()<<"\n";
	for(i=res.size()-1;i>=0;i--)
		cout<<res[i]<<" ";
	return 0;
}
