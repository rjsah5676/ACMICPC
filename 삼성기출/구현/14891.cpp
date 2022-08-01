#include<iostream>
using namespace std;

int topni[4][9];
int K;
int d[3]={0,0,0};


void left(int a,int b[][9]){
	int f=b[a][0];
	for(int i=0;i<7;i++){
		b[a][i]=b[a][i+1];
	}
	b[a][7]=f;
}
void right(int a,int b[][9]){
	int f=b[a][7];
	for(int i=7;i>0;i--){
		b[a][i]=b[a][i-1];
	}
	b[a][0]=f;
}

void func(int target,int clock,int how) {
	if(target<0 || target>3) return;
	if(how==0) {
		if(clock) right(target,topni);
		else left(target,topni);
		func(target+1, !clock,1);
		func(target-1, !clock,-1);
	}
	if(how==1) {
		if(d[target-1]) {
			if(clock) right(target,topni);
			else left(target,topni);
			func(target+1, !clock,1);
		}
	}
	if(how==-1) {
		if(d[target]) {
			if(clock) right(target,topni);
			else left(target,topni);
			func(target-1, !clock,-1);
		}
	}
}
void rotate(int a,int b)
{
	a--;
	if(b==-1) b=0;
	if(topni[0][2]!=topni[1][6]) d[0]=1;
	if(topni[1][2]!=topni[2][6]) d[1]=1;	
	if(topni[2][2]!=topni[3][6]) d[2]=1;
	func(a,b,0);
	
}

int main()
{
	int res=0;
	for(int i=0;i<4;i++) {
		char x[9];
		cin>>x;
		for(int j=0;j<8;j++) topni[i][j]=x[j]-48;
	}
	cin>>K;
	for(int i=0;i<K;i++) {
		int a,b;
		cin>>a>>b;
		d[0]=0;d[1]=0;d[2]=0;
		rotate(a,b);
	}
	if(topni[0][0]==1) res+=1;
	if(topni[1][0]==1) res+=2;
	if(topni[2][0]==1) res+=4;
	if(topni[3][0]==1) res+=8;
	cout<<res;
	return 0;
}