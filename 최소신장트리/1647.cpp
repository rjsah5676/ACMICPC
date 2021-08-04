#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > e;
int parent[100002];
int raank[100002];
int n,m;
vector<int> res;

int find(int x)
{
	if(parent[x]==x) return x;
	
	return parent[x]=find(parent[x]);
}

void uniion(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(raank[x]>raank[y]) swap(x,y);
	parent[x]=y;
	if(raank[x]==raank[y]) raank[x]++;	
}

int main()
{
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e.push_back(make_pair(c,make_pair(a,b)));
	}
	for(int i=1;i<=n;i++){
		parent[i]=i;
		raank[i]=1;
	}
	sort(e.begin(), e.end());
	for(int i=0;i<e.size();i++){
		int u=e[i].second.first;
		int v=e[i].second.second;
		if(find(u) != find(v)){
			res.push_back(e[i].first);
			uniion(u,v);
		}
	}
	sort(res.begin(), res.end());
	int sum=0;
	for(int i=0;i<res.size()-1;i++) sum+=res[i];
	cout<<sum;
	return 0;
}
