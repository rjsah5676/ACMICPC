#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;

int button[10];


int main()
{
	memset(button,1,sizeof(button));
	string input;
	cin>>input;
	int res=abs(atoi(input.c_str())-100);
	int lens=input.length();
	int m;
	cin>>m;
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		button[x]=0;
	}
	for(int i=1;i<=6;i++) {
		int flag=0;
		int pus=0;
		int comp=2e9;
		int ps=pow(10,i-1);
		int pe=pow(10,i);
		if(i==1)ps=0;
		if(i==6)pe=1000000;
		for(int p=ps;p<=pe-1; p++) {
			int num=p;
			int ff=1;
			do {
				if(!button[num%10]) {
					ff=0;
					break;
				}	
				num/=10;
			} while(num!=0);
			if(ff) {
				if(comp>abs(atoi(input.c_str())-p)) {
					comp=abs(atoi(input.c_str())-p);
					pus=p;
				}
			}
		}
		if(comp!=2e9) flag=1;
		if(flag) res=min(res,i+abs(pus-atoi(input.c_str())));
	}
	cout<<res;
	return 0;
}
