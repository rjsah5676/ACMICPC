#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if(abs(a)>abs(b)) return true;
		else if(abs(a)==abs(b)){
			if(a>b) return true;
			else return false;
		}
		else return false;
	}
};

int main()
{
	int n,i,x;
	priority_queue<int, vector<int>, cmp> pq;
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x==0){
			if(pq.empty()) printf("0\n");
			else {
				printf("%d\n",pq.top());
				pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}
