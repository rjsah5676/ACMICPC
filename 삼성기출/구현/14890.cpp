#include<iostream>
#include<vector>
using namespace std;

int N,L;
int sl[101][101];
int res=0;
int checkVec(vector<int> v, int len, int where, int state)
{
	if(where==N-1){
		if(state==1 && len!=L) return 0;
		res++;
		return 1;
	}
	if(v[where]-v[where+1] > 1 || v[where]-v[where+1]<-1) return 0;
	if(state==0) {
		if(v[where]==v[where+1]) checkVec(v, len+1, where+1, 0);
		else if(v[where]>v[where+1]){
			checkVec(v,1,where+1,1);
		}
		else {
			if(len+1>=L) checkVec(v,0,where+1,0);
			else return 0;
		}
	}
	else if(state==1){
		if(len==L) {
			if(v[where+1] > v[where]) {
				return 0;
			}
			else if(v[where]==v[where+1]) checkVec(v,0,where+1,0);
			else {
				checkVec(v,1,where+1,1);
			}
		}
		else {
			if(v[where]!=v[where+1]) return 0;
			checkVec(v,len+1,where+1,1);
		}
	}
	return 0;
}

int main()
{
	vector<int> vt;
	cin>>N>>L;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) cin>>sl[i][j];
	for(int i=0;i<N;i++) {
		vector<int> vv;
		for(int j=0;j<N;j++) vv.push_back(sl[i][j]);
		checkVec(vv,0,0,0);
	}
	for(int i=0;i<N;i++) {
		vector<int> vv;
		for(int j=0;j<N;j++) vv.push_back(sl[j][i]);
		checkVec(vv,0,0,0);
	}
	cout<<res<<endl;
	return 0;
}