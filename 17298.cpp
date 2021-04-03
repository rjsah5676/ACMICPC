//17298
//stack

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n, i;
	int a[1000001];
	int result[1000001] = { 0 };
	stack<int> s;
	cin >> n;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) {
		if(s.empty()) s.push(i);
		else if(a[s.top()] >= a[i]) s.push(i);
		else {
			while(!s.empty()) {
				if(a[s.top()] >= a[i]) break;
				result[s.top()] = a[i]; s.pop();
			}
			s.push(i);
		}
	}
	for(i=0;i<n;i++) {
		if(result[i] == 0) printf("-1 ");
		else printf("%d ", result[i]);
	}
	
	return 0;
}
