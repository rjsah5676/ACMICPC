#include<iostream>
#include<algorithm>
using namespace std;

int sum[100002];

int main()
{
	int start=0;
	int end=0;
	int n,s,i;
	cin>>n>>s;
	sum[0]=0;
	int a;
	for(i=1;i<=n;i++) {
		cin>>a;
		sum[i]=sum[i-1]+a;
	}
	int res=2e9;
	while(end<=n){
		int m=sum[end]-sum[start];
		if(start==end && m>=s) end++;
		else if(m<s) {
			end++;
		}
		else {
			start++;
			res=min(res, end-start+1);
		}
	}
	if(res==2e9) cout<<0;
	else cout<<res;
	return 0;
}
