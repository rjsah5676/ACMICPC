#include<stdio.h>

int cache[101][101][101]={0};

int w(int a, int b, int c){
	if(a<=0||b<=0||c<=0) return 1;
	if(a>20||b>20||c>20) return 1048576;
	if(cache[a+50][b+50][c+50]!=0)return cache[a+50][b+50][c+50];
	if(a<b&&b<c) return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main()
{
	int a,b,c;
	for(int i=0; i<101; i++)
		for(int j=0; j<101; j++)
			for(int k=0; k<101; k++)
				cache[i][j][k]=w(i-50,j-50,k-50);
	while(1){
		scanf("%d%d%d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)break;
		else
			printf("w(%d, %d, %d) = %d\n",a,b,c,cache[a+50][b+50][c+50]);
	}
	return 0;
}
