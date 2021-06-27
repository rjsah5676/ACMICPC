#include<stdio.h>
int M,N,c=0;
int B[51][51]={0,};
int visit[51][51]={0,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
typedef struct Queue{
	int x;
	int y;	
}Q;
Q q[100000];
int fr=0,la=0;

Q pop()
{
	return q[fr++];
}

void push(Q a)
{
	q[la++] = a;
}
int size()
{
	return la-fr;
}

void bfs(int x, int y)
{
	if(B[y][x] == 0 || visit[y][x])
		return;
	c++;
	visit[y][x] = 1;
	Q fq;
	fq.x = x;
	fq.y = y;
	push(fq);
	while(size())
	{
		Q cur = pop();
		for(int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if(nx < 0 || ny < 0|| nx>=M || ny >=N || visit[ny][nx] || B[ny][nx] == 0)
				continue;
			Q nq;
			nq.x = nx;
			nq.y = ny;
			push(nq);
			visit[ny][nx] = 1;			
		}
	}
}

int main()
{
	int T;
	int n;
	scanf("%d",&T);
	for(int i = 0; i < T; i++) {
		scanf("%d%d%d",&M,&N,&n);
		for(int j=0; j < n; j++) {
			int m,p;
			scanf("%d%d",&m,&p);
			B[p][m]=1;
		}
		for(int v = 0; v < N; v++)
			for(int w = 0; w < M; w++)
				bfs(w,v);
		printf("%d\n",c);
		for(int v = 0; v < 51; v++)
			for(int w = 0; w < 51; w++) {
				B[v][w] = 0;
				visit[v][w] = 0;
				c=0;
			}
	}
}