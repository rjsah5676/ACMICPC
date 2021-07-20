#include<iostream>
#include<algorithm>
using namespace std;
long long k,n;

int main()
{
	long long i;
	long long s=0;
	long long p,q;
	long long m=0;
	long long l[10001];
	cin>>k>>n;
	for(i=0;i<k;i++)cin>>l[i];
	sort(l,l+k);
	long long e=2200000000;
	for(;;){
		if(s>e)break;
		p=(s+e)/2;
		q=0;
		for(i=0;i<k;i++) q+=l[i]/p;
		if(q>=n){
			s=p+1;
			if(p>m)m=p;
		}
		else e=p-1;	
	}
	printf("%lld\n",m);
	return 0;
}
