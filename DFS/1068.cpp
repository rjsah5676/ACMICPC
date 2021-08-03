#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> tree[51];
int cnt=0;
int visit[51]={0,};

void dfs(int cur)
{
	if(visit[cur]) return;
	visit[cur]=1;
	int flag=1;
	for(int i=0;i<tree[cur].size();i++){
		dfs(tree[cur][i]);
		flag=0;
	}
	if(flag) cnt++;
}

int main()
{
	cin>>n;
	int root;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x!=-1) tree[x].push_back(i);
		else root=i;
	}
	int v;
	cin>>v;
	visit[v]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<tree[i].size();j++){
			if(tree[i][j]==v) {
				vector<int> new_tr;
				for(int k=0;k<tree[i].size();k++){
					if(tree[i][k]!=v)new_tr.push_back(tree[i][k]);
				}
				tree[i]=new_tr;
				break;
			}
		}
	}
	dfs(root);
	cout<<cnt;
	return 0;
}
