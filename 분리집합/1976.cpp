#include<iostream>
#include<cstring>
using namespace std;

int set[202];
int parent[202];
int raank[202];
int find(int x){
	if(x == parent[x]) return x;
	return parent[x]=find(parent[x]);
}

void uniion(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(raank[x]>raank[y]){
		int tmp=x;
		x=y;
		y=tmp;
	}
	
	parent[x]=y;
	if(raank[x]==raank[y]) raank[x]++;
}

int main()
{
	int i,j;
	memset(raank,1,sizeof(raank));
	int n,m;
	cin>>n>>m;
	for(i=0;i<=n;i++){
		set[i]=i;
		parent[i]=i;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int t;
			cin>>t;
			if(t) uniion(i,j);
		}
	}
	int tmp,x;
	int flag=1;
	if(m==1){
		cout<<"YES";
	}
	else {
		for(i=0;i<m;i++){
			cin>>x;
			if(i!=0){
				if(find(tmp-1)!=find(x-1)){
					flag=0;
				}
			}
			tmp=x;
		}
		if(flag) cout<<"YES";
		else cout<<"NO";
	}
	return 0;
}
