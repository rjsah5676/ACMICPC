//2108
//https://www.acmicpc.net/problem/2108
//sort

#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n,i,x;
	double sum=0;
	int max=-4001, min=4001;
	int a[8002]={0};
	vector<int> v;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		sum+=x;
		max=max>x?max:x;
		min=min<x?min:x;
		a[x+4000]++;
		v.push_back(x);
	}
	int max2=0;
	int fmax=0;
	for(i=0;i<8001;i++)
		max2=max2>a[i]?max2:a[i];
	int cnt=0;
	for(i=0;i<8001;i++)
		if(a[i]==max2) {
			cnt++;
			fmax=i-4000;
		}
	sort(v.begin(),v.end());
	printf("%.0f\n",round(sum/n));
	printf("%d\n",v[n/2]);
	if(cnt==1){
		printf("%d\n",fmax);
	}
	else{
		int c=0;
		for(i=0;i<8001;i++){
			if(a[i]==max2) c++;
			if(c==2) {
				printf("%d\n",i-4000);
				break;
			}
		}
	}
	printf("%d\n",max-min);
	
	return 0;
}
