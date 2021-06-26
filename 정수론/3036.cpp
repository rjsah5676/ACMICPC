#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int n = N;
	int g = 1;
	int *a = (int*)malloc(4*N+4);
	N = -1;
	while (++N != n) cin >> a[N];
	N = 0;
	while (++N != n) {
		int x = a[N]+1;
		while (--x)
			if (a[0] % x == 0 && a[N] % x == 0) {
				g = x; break;
			}
		printf("%d/%d\n", a[0] / g, a[N] / g);
		g = 1;
	}
}