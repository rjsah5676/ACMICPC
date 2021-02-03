/*
2644
bfs
2021-02-03
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

int q[2000000];
int fr = 0, la = 0;
int N;
char X[102][102];
int cost[102];
void push(int a)
{
	q[la++] = a;
}

int pop()
{
	return q[fr++];
}

int size()
{
	return la - fr;
}
void bfs(int v)
{
	push(v);
	cost[v] = 1;
	while (size())
	{
		int cur = pop();
		for (int i = 1; i <= N; i++) {
			if (!X[cur][i] || cost[i]) continue;
			push(i);
			cost[i] = cost[cur] + 1;
		}
	}
}

int main()
{
	scanf("%d", &N);
	int x, y, T, a, b;
	scanf("%d%d", &x, &y);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &a, &b);
		X[a][b] = 1;
		X[b][a] = 1;
	}
	bfs(x);
	printf("%d", cost[y] - 1);
}