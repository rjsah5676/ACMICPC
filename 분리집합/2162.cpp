#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct line{
	int x1,x2;
	int y1,y2;
};
line l[3002];
int set[3002];
int parent[3002];
int raank[3002];
int res[3002];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int flag = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
	if(flag>0) return 1;
	if(flag==0) return 0;
	return -1;
}

int isInter(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int case_1=ccw(x1,y1,x2,y2,x3,y3) * ccw(x1,y1,x2,y2,x4,y4);
	int case_2=ccw(x3,y3,x4,y4,x1,y1) * ccw(x3,y3,x4,y4,x2,y2);
	if(case_1<=0 && case_2<=0){
		if((x1>x3&&x1>x4&&x2>x3&&x2>x4)||(x3>x1 && x3>x2&&x4>x1&&x4>x2)) return false;
		if((y1>y3 && y1>y4&&y2>y3&&y2>y4)||(y3>y1&&y3>y2&&y4>y1&&y4>y2)) return false;
		return true;
	}
	return false;
}

int find(int x){
	if(x == parent[x]) return x;
	return parent[x]=find(parent[x]);
}

void uniion(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(raank[x]>raank[y]){
		int tmp=x;
		x=y;
		y=tmp;
	}
	parent[x]=y;
	if(raank[x]==raank[y]) raank[x]++;
}

int main()
{
	int i,j;
	memset(raank,1,sizeof(raank));
	memset(res,0,sizeof(res));
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>l[i].x1>>l[i].y1>>l[i].x2>>l[i].y2;
		set[i]=i;
		parent[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++){
			if(isInter(l[i].x1,l[i].y1,l[i].x2,l[i].y2,l[j].x1,l[j].y1,l[j].x2,l[j].y2)){
				uniion(i,j);
			}
		}
	}
	int cnt=0;
	int fin=0;
	for(i=0;i<n;i++) {
		res[find(i)]++;
	}
	for(i=0;i<n;i++){
		if(res[i]) {
			cnt++;
			fin=max(fin,res[i]);
		}
	}
	printf("%d\n%d",cnt,fin);
	return 0;
}
