#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321;
using namespace std;
int n,m;
int a[10][10];

bool garo[10][10];
bool sero[10][10];
bool square[10][10];

void dfs(int idx){
	int x=idx/9;
	int y=idx%9;
	
	
	if(idx==81){
	
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
        }		
		exit(0);
	}
	
	if(a[x][y]==0){
		
		for(int i=1;i<=9;i++){
			if(garo[x][i]==false && sero[y][i]==false && square[(x/3)*3+(y/3)][i]==false){
				garo[x][i]=true;
				sero[y][i]=true;
				square[(x/3)*3+(y/3)][i]=true;
				a[x][y]=i;
				dfs(idx+1);
				a[x][y]=0;
				garo[x][i]=false;
				sero[y][i]=false;
				square[(x/3)*3+(y/3)][i]=false;
			}
		}
	}else dfs(idx+1);
}


int main(void){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0){
				garo[i][a[i][j]]=true;
				sero[j][a[i][j]]=true;
				square[(i/3)*3+(j/3)][a[i][j]]=true;
			}
		}
	}
	
	dfs(0);
return 0;
}