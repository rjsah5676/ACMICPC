#include<stdio.h>
int main()
{
	int N;scanf("%d",&N);
	int a[1000000];int t;
	for(int i=0;i<N;i++){
		a[i]=i+1;
	}
	for(int i=0;i<=2*N-3;i++){
		if(i%2!=0)
			a[N+(i/2)]=a[i];
	}
	if(N==1)printf("1");
	else
		printf("%d",a[N+((2*N-3)/2)]);
}