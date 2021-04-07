//1016
//math

#include<stdio.h>
#include<math.h>
int x[1000001]={0};
int main(){
	long long a,b,c=0;
	long long z,j,i,r;
	scanf("%lld %lld",&a,&b);
	long long t=sqrt(b);
	for(i=2;i<=t;i++){
		z=i*i;
		j=ceil((double)a/z)*z;
		for(;j<=b;j+=z)x[j-a]=1;
	}
	for(i=a;i<=b;i++)if(x[i-a])c++;
	printf("%lld",b-a+1-c);
}
