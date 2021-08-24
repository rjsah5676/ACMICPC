#include<iostream>
#include<vector>
#include<map>
using namespace std;

int parent[52];
int raank[52];
int n,m;
int res=0;
map<int, int> trp;
vector<int> vt[52];
int find(int v)
{
	if(parent[v]==v) return v;
	return parent[v]=find(parent[v]);
}

void uniion(int x, int y)
{
	int v1=find(x);
	int v2=find(y);
	if(v1==v2) return;
	if(raank[v1]>raank[v2]){
		swap(v1,v2);
	}
	parent[v1]=v2;
	if(raank[v1]==raank[v2]) raank[v1]++;
}

int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		parent[i]=i;
		raank[i]=1;
	}
	int trpn;
	cin>>trpn;
	for(i=0;i<trpn;i++){
		int x;
		cin>>x;
		raank[x]=100;
		trp[x]=1;
	}
	for(i=0;i<m;i++){
		int p;
		cin>>p;
		int tmp=-1;
		for(int j=0;j<p;j++) {
			int x;
			cin>>x;
			vt[i].push_back(x);
			if(tmp==-1){
				tmp=x;
			}
			else{
				uniion(x,tmp);
			}
		}
	}
	for(i=0;i<m;i++){
		int flag=1;
		for(int j=0;j<vt[i].size();j++){
			if(trp.count(find(vt[i][j]))!=0) {
				flag=0;
			}
		}
		if(flag) res++;
	}
	cout<<res;

	return 0;
}
