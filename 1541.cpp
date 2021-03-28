//1541
//https://www.acmicpc.net/problem/1541
//greedy

#include<stdio.h>
#include<string.h>

int pow(int a,int b){
	int x=1;
	if(b==0) return 1;
	for(int i=0;i<b;i++)
		x*=a;
	return x;
}

int f(char x[], int l)
{
	int i,j;
	int cnt=0;
	int a[5];
	int result=0;
	int sum=0;
	int t=0;
	for(i=0;i<l;i++){
		if(x[i]!='+' && x[i]!='-'){
			a[cnt++]=x[i]-48;
		}
		if(x[i]=='+'){
			for(j=cnt-1;j>=0;j--) {
				sum+=a[j]*pow(10,cnt-1-j);
			}
			cnt=0;
		}
		if(t==0) {
			if(x[i]=='-') {
				for(j=cnt-1;j>=0;j--) {
					sum+=a[j]*pow(10,cnt-1-j);
				}
				cnt=0;
				t=1;
				result+=sum;
				sum=0;
			}
		}
		else if(t==1){
			if(x[i]=='-') {
				for(j=cnt-1;j>=0;j--) {
					sum+=a[j]*pow(10,cnt-1-j);
				}
				cnt=0;
				t=1;
				result-=sum;
				sum=0;
			}
		}
		if(i==l-1) {
			for(j=cnt-1;j>=0;j--) {
				sum+=a[j]*pow(10,cnt-1-j);
			}
		}
	}
	if(t==0) return result+sum;
	else return result-sum;
}

int main(){
	char x[51];
	scanf("%s",x);
	printf("%d",f(x,strlen(x)));
}
