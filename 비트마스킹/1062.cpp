#include<iostream>
#include<algorithm>
#include<string.h>
#include <bitset>
using namespace std;

int n,k;
char ant[51][27];
int res=-1;
void dfs(int depth, int start, int bit)
{
	if(depth == k-5){
		int cnt=0;
		for(int j=0;j<n;j++) {
			int flag = 1;
			for(int i=0;i<strlen(ant[j]);i++) {
				if((1<<(ant[j][i]-97)) & bit);
				else {
					flag=0;
					break;
				}
			}
			if(flag) {
				cnt++;
			}
		}
		res = max(res, cnt);
		return;
	}
	for(int i=start+1;i<=26;i++){
		if(i=='a'-96 || i=='n'-96 || i=='t'-96 || i=='i'-96|| i=='c'-96) continue;
		dfs(depth+1, i, bit|1<<(i-1));
	}
}

int main()
{
	int bit=1<<26;
	int i;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>ant[i];
	}
	bit |= 1<<'a'-'a';
	bit |= 1<<'c'-'a';
	bit |= 1<<'t'-'a';
	bit |= 1<<'i'-'a';
	bit |= 1<<'n'-'a';
	if(k>5) {
		dfs(0,0,bit);
		cout<<res;
	}
	else if(k==5){
		int cnt=0;
		for(i=0;i<n;i++) {
			int flag=1;
			for(int j=0;j<strlen(ant[i]); j++) {
				if(ant[i][j]!='a'&&ant[i][j]!='t'&&ant[i][j]!='n'&&ant[i][j]!='i'&&ant[i][j]!='c')
					flag=0;
			}
			if(flag) cnt++;
		}
		cout<<cnt;
	}
	else {
		cout<<0;
	}
	return 0;
}
