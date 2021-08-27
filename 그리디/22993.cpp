#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<long long> v;

int main()
{
	long long n;
	cin>>n;
	long long x;
	cin>>x;
	for(long long i=0;i<n-1;i++) {
		long long a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int cnt=n-1;
	for(long long i=0;i<n-1;i++) {
		if(v[i]>x) {
			break;
		}
		if(v[i]<x) {
			cnt--;
			x+=v[i];
		}
	}
	if(!cnt) cout<<"Yes";
	else cout<<"No";
	return 0;
}
