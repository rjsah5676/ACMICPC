#include<iostream>
#include<queue>
using namespace std;


int main()
{
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	int n,i,x;
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(max_heap.empty())max_heap.push(x);
		else {
			if(min_heap.empty()){
				min_heap.push(x);
				if(max_heap.top()>min_heap.top()){
					int tmp_min=min_heap.top();
					int tmp_max=max_heap.top();
					min_heap.pop(); max_heap.pop();
					min_heap.push(tmp_max);
					max_heap.push(tmp_min);
				}
			}
			else {
				if(x<=min_heap.top()){
					if(min_heap.size() == max_heap.size()) max_heap.push(x);
					else {
						if(x>=max_heap.top()) min_heap.push(x);
						else {
							min_heap.push(x);
							int tmp_min=min_heap.top();
							int tmp_max=max_heap.top();
							min_heap.pop(); max_heap.pop();
							min_heap.push(tmp_max);
							max_heap.push(tmp_min);
						}
					}
				}
				else {
					if(max_heap.size() == min_heap.size()+1) min_heap.push(x);
					else {
						max_heap.push(x);
						int tmp_min=min_heap.top();
						int tmp_max=max_heap.top();
						min_heap.pop(); max_heap.pop();
						min_heap.push(tmp_max);
						max_heap.push(tmp_min);
					}
				}
			}
		}
		printf("%d\n", max_heap.top());
	}
	
	return 0;
}
