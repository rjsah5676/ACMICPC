//13305
//https://www.acmicpc.net/problem/13305
//greedy

#include<stdio.h>

int main()
{
	int n,i,j,k;
	long long x[100001];
	long long y[100000];
	long long result=0;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)scanf("%lld",&y[i]);
	for(i=0;i<n;i++)scanf("%lld",&x[i]);
	i=0;
	int cnt;
	while(i<n-1){
		cnt=0;
		for(j=i+1;j<n;j++) {
			if(j==n-1){
				if(cnt>=1) {
					for(k=i;k<i+cnt+1;k++){
						result+=x[i]*y[k];
					}
					i+=cnt+1;
					break;
				}
				else {
					result+=x[i]*y[i];
					i++;
					break;
				}
			}
			else if(x[j]>x[i]) {
				cnt++;
			}
			else {
				if(cnt>=1) {
					for(k=i;k<i+cnt+1;k++){
						result+=x[i]*y[k];
					}
					i+=cnt+1;
					break;
				}
				else {
					result+=x[i]*y[i];
					i++;
					break;
				}
			}
		}
	}
	printf("%lld",result);
}
