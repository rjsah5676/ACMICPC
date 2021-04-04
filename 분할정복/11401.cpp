//11401
//divide and conquer

#include<iostream>
using namespace std;

const long long p=1000000007;

long long pow(long long a, long long b)
{
	if(!b) return 1;
	if(b==1) return a;
	if(b%2==1) return (a*pow(a,b-1))%p;
	long long h = pow(a,b/2)%p;
	return (h * h)%p;
}

long long factorial(long long a)
{
	long long result = 1;
	for(long long i=a;i>0;i--)
		result= (result*i)%p;
	return result;
}
int main()
{
	long long n,k;
	cin>>n>>k;
	cout << ((factorial(n)%p)*(pow(factorial(n-k)%p*factorial(k)%p,p-2)%p))%p;
}
