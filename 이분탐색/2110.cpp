#include<iostream>
#include<algorithm>
using namespace std;
int home[200001];

int main()
{
	int n,c,i;
	cin>>n>>c;
	for(i=0;i<n;i++)
		cin>>home[i];
	sort(home,home+n);
	int left=1;	//최소 거릿값 
	int right=home[n-1]-home[0];//최대 거릿값 
	int ans=right;
	while(left<=right){
		int mid=(left+right)/2;
		int start=home[0];
		int res=1;
		for(int i=1;i<n;i++) {
			if(home[i]-start>=mid){ //간격 비교 
				res++;
				start=home[i];
			}
		}
		if(res>=c){	//결과 공유기가 더 많다 -> 간격을 늘려도 된다 
			left=mid+1;
			ans=mid;
		}
		else { //부족하다-> 간격을 줄여야한다. 
			right=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
