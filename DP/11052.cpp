#include<stdio.h>

/*
11052번
다이나믹 프로그래밍
2021-01-18
*/

int main()
{
	int n;
	int p[10001];
	int q[10001];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	q[0] = p[0];
	for (i = 1; i < n; i++) {
		int max = -1;
		for (int j = 0; j < (i / 2) + 1; j++) {
			max = max > q[j] + q[i - j - 1] ? max : q[j] + q[i - j - 1];
		}
		q[i] = p[i] > max ? p[i] : max;
	}
	printf("%d", q[n - 1]);
	return 0;
}