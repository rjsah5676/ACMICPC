#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int mat[10][10];
int res=-1;
int n,m;

bool isSquare(unsigned int num) {
  unsigned int temp;
  switch (num & 0x0f) {
  case 0:
  case 1:
  case 4:
  case 9:
    temp = (unsigned int)(sqrt((double)num)+0.5);
    return temp*temp == num;
    
  default:
    return false;
  }
}

void dfs(int rowT, int colT, int r, int c, int depth, int sum)
{
	if(r>=n || c>=m || r<0 || c<0) return;
	sum+=mat[r][c]*pow(10,depth);
	if(isSquare(sum)) res=max(res, sum);
	if(rowT==0&&colT==0) return;
	dfs(rowT, colT,r+rowT,c+colT,depth+1,sum);
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
		char x[10];
		cin>>x;
		for(j=0;j<m;j++){
			mat[i][j] = x[j]-48;
		}
	}
	for(i=-n;i<n;i++) {
		for(j=-m;j<m;j++){
			for(int p=0;p<n;p++){
				for(int q=0;q<m;q++){
					dfs(i,j,p,q,0,0);
				}
			}
		}
	}
	cout<<res;
	return 0;
}
