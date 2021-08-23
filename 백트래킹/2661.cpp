#include<stdio.h>

int selected[81] = {0,}; 
int arr[81];
int n = 0;
int N;
int x=0;
bool promising(int i)
{
	int k = i-1;
	int a = i-k;
	int c = 0;
	bool s = true;
	while(k > 0 && s) {
		for(int j = 0; j < a; j++) {
			if(selected[i-j] == selected[k-j])
				c++;
		}
		if(c == a)
			s=false;
		k--;
		c=0;
		a=i-k;
	}
	return s;
}

void nP(int i)
{
	int j;
	if(!x) {
	if(promising(i))
		if(i == n) {
			if(!x)
				for(int k = 1; k <= n; k++)
					printf("%d",selected[k]);
			x++;
		}
	else
		for(j = 1; j <= 3; j++) {
			selected[i+1] = j;
			nP(i + 1);
		}
	}
			
}

int main()
{
	scanf("%d",&n);
	nP(0);
	return 0;
}