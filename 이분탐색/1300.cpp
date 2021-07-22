#include<iostream>
using namespace std;

int main()
{
	int n,k,i;
	cin>>n>>k;
	int s=1;
	int e=1000000002;
	int res=0;
	while(s<=e){
		int mid=(s+e)/2;
		int c=0;
		for(i=1;i<=n;i++){
			c+=min(mid/i,n);
		}
		if(c<k){
			s=mid+1;
		}
		else {
			res=mid;
			e=mid-1;
		}
	}
	cout<<res;
	return 0;
}
