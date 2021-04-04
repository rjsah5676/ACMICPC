//2630
//divide and conquer

#include<iostream>
using namespace std;
int a[129][129];
int cnt = 0;
int cut = 0;

void divcon(int s_x, int s_y, int e_x, int e_y)
{
	int ok=1;
	int white=1;
	for(int i=s_x;i<e_x;i++)
		for(int j=s_y;j<e_y;j++)
			if(!a[i][j]) {
				ok=0;
			}
	for(int i=s_x;i<e_x;i++)
		for(int j=s_y;j<e_y;j++)
			if(a[i][j]) {
				white=0;
			}
	if(white) {
		cut++;
		return;
	}
	if(e_x - s_x == 1){
		if(a[s_x][s_y]) cnt++;
		return;
	}
	else if(!ok) {
		int dif_x=e_x-s_x;
		int dif_y=e_y-s_y;
		divcon(s_x,s_y,s_x+(dif_x/2),s_y+(dif_y/2));
		divcon(e_x-(dif_x/2),s_y,e_x,e_y-(dif_y/2));
		divcon(s_x,e_y-(dif_y/2),e_x-(dif_x/2),e_y);
		divcon(e_x-(dif_x/2),e_y-(dif_y/2),e_x,e_y);
	}
	else {
		cnt++;
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	divcon(0,0,n,n);
	cout<<cut<<'\n'<<cnt<<'\n';
}
