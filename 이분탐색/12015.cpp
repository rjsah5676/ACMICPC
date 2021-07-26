#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[1000010];
vector<int> res;

int searchFunc(int x,int end)
{
	int start=0;
	while(start<end) {
		int mid=(start+end)/2;
		if(res[mid]==x)
			start = end = mid;
		if(res[mid]<x)
			start = mid+1;
		else if(res[mid]>x)
			end = mid;
	}
	return start;
}

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	res.push_back(a[0]);
	for(i=1;i<n;i++){
		if(a[i]>res.back()) res.push_back(a[i]); 
		else res[searchFunc(a[i],res.size()-1)] = a[i];
	}
	cout<<res.size();
	return 0;
}
