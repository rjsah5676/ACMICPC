//18870
//sort

#include<iostream>
#include<algorithm>
using namespace std;

struct S{
	int value;
	int index;
};

bool cmp(const S &s1, const S &s2){
	if(s1.value < s2.value) return true;
	else if(s1.value == s2.value) return s1.index < s2.index;
	return false;
}

int main()
{
	int n,i;
	S arr[1000001];
	int result[1000001];
	cin>>n;
	for(i=0;i<n;i++){
		arr[i].index = i;
		cin>>arr[i].value;
	}
	sort(arr, arr+n, cmp);
	int cnt=0;
	for(i=0;i<n;i++) {
		if(!i)
			result[arr[i].index] = cnt;
		else if(arr[i].value > arr[i-1].value) result[arr[i].index] = ++cnt;
		else result[arr[i].index] = cnt;
	}
	for(i=0;i<n;i++) cout<<result[i]<<' ';
}
