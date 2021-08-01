#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int> > city[1002];
int mindist[1002];

int main()
{
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int start,end,cost;
		cin>>start>>end>>cost;
		city[start].push_back(make_pair(end,cost));
	}
	int s,e;
	cin>>s>>e;
	for(i=1;i<=n;i++)
		mindist[i]=2111111111;
	mindist[s]=0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(s, 0));
	while(!pq.empty()){
		int cur = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();
		if(dist > mindist[cur]) continue;
		for(i=0;i<city[cur].size();i++){
			int next_city=city[cur][i].first;
			int next_dist= dist + city[cur][i].second;
			if(next_dist<mindist[next_city]){
				mindist[next_city]=next_dist;
				pq.push(make_pair(next_city, -next_dist));
			}
		}
	}
	cout<<mindist[e];
	return 0;
}
