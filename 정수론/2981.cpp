//2981
//https://www.acmicpc.net/problem/2981
//math

#include<stdio.h>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	int n,i;
	int arr[101];
	int result[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int max_m = arr[1] - arr[0];
	for(i=2; i<n; i++)
		max_m = gcd(max_m, arr[i] - arr[i-1]);
	int cnt=0;
	for(i=1; i*i<=max_m; i++) {
		if(max_m%i==0) {
			result[cnt++] = i;
			if(i != max_m/i)
				result[cnt++] = max_m/i;
		}
	}
	sort(result, result+cnt);
	for(i=0; i<cnt; i++) if(result[i]!=1) printf("%d ", result[i]);
}
