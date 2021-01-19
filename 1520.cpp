/*
1520번
다이나믹 프로그래밍
2021-01-18
*/
#include <iostream>

using namespace std;

int dp[501][501]{ 0, };
int M[501][501];

int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int n, m;

int f(int x, int y, int nx, int ny)
{
	if (x == nx && y == ny)
		return 1;
	if (dp[x][y] > -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < 0 || nextX >= n ||
			nextY < 0 || nextY >= m)
			continue;
		if (M[nextX][nextY] >= M[x][y])
			continue;
		dp[x][y] += f(nextX, nextY, nx, ny);
	}
	return dp[x][y];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			dp[i][j] = -1;
		}
	}
	cout << f(0, 0, n - 1, m - 1);
}