#include<iostream>
#include<vector>
using namespace std;
vector<int> res;
char dp[1000001] ={0,};
int main()
{
	int a;
	int i;
	cin>>a;
	i = 0;
	while(i++ <=a)
	{
		if(i+1<=1000000)
			if((!dp[i+1]) || (dp[i+1] > dp[i] + 1))
				dp[i+1] = dp[i] + 1;
		if(i*2<=1000000)
			if((!dp[i*2])||(dp[i*2] > dp[i] + 1))
				dp[i*2] = dp[i] + 1;
		if(i*3<=1000000)
			if((!dp[i*3]) || (dp[i*3] > dp[i] + 1))
				dp[i*3] = dp[i] + 1;
	}
	int k=a;
	res.push_back(k);
	int m=dp[a];
	while(k!=1){
		if(k%3==0){
			if(dp[k/3]==m-1) {
				k/=3;
				res.push_back(k);
				m--;
				continue;
			}
		}
		if(k%2==0){
			if(dp[k/2]==m-1) {
				k/=2;
				res.push_back(k);
				m--;
				continue;
			}
		}
		if(k-1>=0){
			if(dp[k-1]=m-1) {
				k-=1;
				res.push_back(k);
				m--;
				continue;
			}
		}
	}
	printf("%d\n", dp[a]);
	for(i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	return 0;
}

