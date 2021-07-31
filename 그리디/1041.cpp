#define MIN(A, B) (A < B ? A : B)
#include<iostream>
#include<algorithm>
using namespace std;

long long dice[6];
long long min_1=2111111111;
long long min_2=2111111111;
long long min_3=2111111111;
int main()
{

	long long n,i;
	long long sum=0;
	cin>>n;
	for(i=0;i<6;i++)cin>>dice[i];
	if(n==1){
		long long max_1=-1;
		for(i=0;i<6;i++) {
			sum+=dice[i];
			max_1=max(max_1, dice[i]);
		}
		sum-=max_1;
	}
	else {
		dice[0] = MIN(dice[0], dice[5]);
	    dice[1] = MIN(dice[1], dice[4]);
	    dice[2] = MIN(dice[2], dice[3]);
	    sort(dice, dice + 3);
	    min_3 = dice[0] + dice[1] + dice[2];
	    min_2 = dice[0] + dice[1];
	    min_1 = dice[0];
		sum+=min_3*4;
		sum+=4*(n-1)*min_2+4*(n-2)*min_2;
		sum+=4*(n-1)*(n-2)*min_1+(n-2)*(n-2)*min_1;
	}
	cout<<sum;
	return 0;
}
