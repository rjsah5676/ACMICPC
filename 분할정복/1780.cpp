/*
1780
Divide and conquer
2021-02-02
*/
#include<iostream>
using namespace std;
int N;
int X[2189][2189];
int r[3] = { 0,0,0 };
void f(int size, int start, int end)
{
	int fx = X[start][end];
	int ok = 1;
	for (int i = start; i < start + size; i++) {
		for (int j = end; j < end + size; j++) {
			if (fx != X[i][j]) {
				ok = 0;
				break;
			}
		}
		if (!ok)break;
	}
	if (ok) {
		r[fx + 1]++;
		return;
	}
	int z = size / 3;
	f(z, start, end);
	f(z, start + z, end);
	f(z, start, end + z);
	f(z, start, end + 2 * z);
	f(z, start + z, end + z);
	f(z, start + 2 * z, end);
	f(z, start + z, end + 2 * z);
	f(z, start + 2 * z, end + z);
	f(z, start + 2 * z, end + 2 * z);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> X[i][j];
	f(N, 0, 0);
	cout << r[0] << "\n";
	cout << r[1] << "\n";
	cout << r[2] << "\n";
}