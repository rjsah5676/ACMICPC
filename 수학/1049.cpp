#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,n,m;
	int a,b;
	int res=0;
	int min_a=2111111111;
	int min_b=2111111111;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		min_a=min(min_a,a);
		min_b=min(min_b,b);
	}
	while(n-6>=0 && min_a<=6*min_b){
		res+=min_a;
		n-=6;
	}
	if(n>=6){
		res+=n*min_b;
	}
	else if(n!=0) res+= n*min_b>min_a?min_a:n*min_b;
	cout<<res;
	return 0;
}
