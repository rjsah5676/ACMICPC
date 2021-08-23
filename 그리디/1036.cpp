#include<iostream>
using namespace std;

char input[51][51];
int n,k;

int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>input[i];
	}
	cin>>k;
	if(input[0][10]==NULL)
	cout<<"!";
	return 0;
}
