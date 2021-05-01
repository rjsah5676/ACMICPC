#include<stdio.h>

int M[1002][1002]={0,};
int visit[1002]={0,};
int dvisit[1002]={0,};
int n,m;
typedef struct Queue{
	int v;
}Q;
Q q[100000];
int fr=0,la=0;

void push(Q a)
{
	q[la++] = a;
}
Q pop()
{
	return q[fr++];
}
int size()
{
	return la-fr;
}
void dfs(int v)
{
	printf("%d ", v);
	dvisit[v]=1;
	for(int i = 1; i <= n; i++) {
		if(!dvisit[i] && M[v][i])
			dfs(i);
	}
	
}
void bfs(int v)
{
	printf("%d ", v);
	Q fq;
	fq.v = v;
	visit[v]=1;
	push(fq);
	while(size()) {
		Q cur = pop();
		for(int i = 1; i <= n; i++) {
			if(M[cur.v][i] && !visit[i]) {
				printf("%d ",i);
				Q nq;
				nq.v = i;
				push(nq);
				visit[i] = 1;
			}
		}
	}
}
int main()
{
	int v;
	scanf("%d%d%d",&n,&m,&v);
	for(int i = 0; i < m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		M[x][y]=1;
		M[y][x]=1;
	}
	dfs(v);
	printf("\n");
	bfs(v);
}