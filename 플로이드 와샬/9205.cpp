#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int mindist[101][101];
int n;
pair<int, int> start;
pair<int, int> end;
vector<pair<int, int> > city;

int dist(int x, int y, int u, int v)
{
	return abs(x-u)+abs(y-v);
}

void floyd()
{
	for(int i=0;i<n+2;i++) {
		for(int j=0;j<n+2;j++) {
			if(i==j) continue;
			int distance = dist(city[i].first,city[i].second,city[j].first,city[j].second);
			if(distance <= 1000) mindist[i][j]=1;
		}
	}
	for(int k=0;k<n+2;k++) {
		for(int i=0;i<n+2;i++) {
			for(int j=0;j<n+2;j++) {
				if(mindist[i][j]==1 || i==j) continue;
				if(mindist[i][k] && mindist[k][j])
					mindist[i][j]=1;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(mindist,0,sizeof(mindist));
		int a,b;
		cin>>n;
		cin>>a>>b;
		start = make_pair(a,b);
		city.push_back(start);
		for(int i=0;i<n;i++) {
			cin>>a>>b;
			city.push_back(make_pair(a,b));
		}
		cin>>a>>b;
		end = make_pair(a,b);
		city.push_back(end);
		floyd();
		city.clear();
		if(mindist[0][n+1]==1) cout<<"happy\n";
		else cout<<"sad\n";
	}
	return 0;
}

