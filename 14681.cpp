//14681
//https://www.acmicpc.net/problem/14681

#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a*b>0){
		if(a>0) printf("1");
		else printf("3");
	}
	else{
		if(a>0) printf("4");
		else printf("2");
	}
	return 0;
}
