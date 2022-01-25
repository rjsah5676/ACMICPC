#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,l,k;
int arr[101][101];
int snake[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char direction[10002];

int main()
{
	fill(&arr[0][0], &arr[100][100], 0);
	fill(&snake[0][0], &snake[100][100], 0);
	snake[0][0]=1;
	cin>>n>>k;
	int i;
	for(i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		arr[b-1][a-1]=1;
	}
	int di=0;
	cin>>l;
	for(i=0;i<l;i++) {
		int a;
		char b;
		cin>>a>>b;
		direction[a+1]=b;
	}
	int flag=1;
	int time=0;
	int cur_x=0;
	int cur_y=0;
	queue<pair<int, int> > tail;
	int head_x=0;
	int head_y=0;
	while(flag) {
		tail.push(make_pair(cur_x,cur_y));
		time++;
		if(direction[time]=='D') di=(di+1)%4;
		if(direction[time]=='L') {
			if(di==0)di=3;
			else di-=1;
		}
		head_x=dx[di]+cur_x;
		head_y=dy[di]+cur_y;
		if(head_x<0||head_x>=n||head_y<0||head_y>=n||snake[head_x][head_y]) break;
		snake[head_x][head_y]=1;
		if(arr[head_x][head_y]) {
			arr[head_x][head_y]=0;
		}
		else {
			int tx=tail.front().first;
			int ty=tail.front().second;
			snake[tx][ty]=0;
			tail.pop();
		}
		cur_x=head_x;
		cur_y=head_y;
	}
	cout<<time;
	return 0;
}