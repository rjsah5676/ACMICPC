#include<iostream>
#include<cstring>
using namespace std;

int set[1000001];
int parent[1000001];
int raank[1000001];
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
	int i;
	memset(raank,1,sizeof(raank));
	int n,m;
	cin>>n>>m;
	for(i=0;i<=n;i++){
		set[i]=i;
		parent[i]=i;
	}
	for(i=0;i<m;i++){
		int f,a,b;
		scanf("%d %d %d",&f,&a,&b);
		if(f){
			if(find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else{
			uniion(a,b);
		}
	}
	return 0;
}
