#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
int p[1000002];
vector<int> pr;
int main()
{
	int x;
	int i,j;
	memset(p,1,sizeof(p));
	for(i=2;i<=1000000;i++) {
		if(p[i]==0) continue;
		for(j=2*i;j<=1000000;j+=i) {
			p[j]=0;
		}
	}
	for(i=2;i<=1000000;i++) if(p[i]) pr.push_back(i);
	for(;;){
		int flag=0;
		int no=1;
		scanf("%d",&x);
		if(x==0) break;
		for(i=0;i<pr.size();i++) {
			if(pr[i]>x) break;
			for(j=i;j<pr.size();j++) {
				if(x==pr[i]+pr[j]) {
					flag=1;
					no=0;
					printf("%d = %d + %d\n",x,pr[i],pr[j]);
					break;
				}
				if(x<pr[i]+pr[j]) {
					break;
				}
			}
			if(flag) break;
		}
		if(no) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
