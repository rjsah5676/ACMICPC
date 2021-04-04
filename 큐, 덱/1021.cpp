//1021
//deque

#include<iostream>
#include<deque>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int i,j, n, m;
	int result = 0;
	deque<int> deq;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		deq.push_back(i);
	for(i=0;i<m;i++){
		int x;
		cin >> x;
		int right = 0;
		int left = 0;
		for(j=0; j<deq.size();j++) {
			if(deq.front() == x) break;
			deq.push_front(deq.back());
			deq.pop_back();
			right++;
		}
		for(j=0; j<deq.size()-right; j++) {
			deq.push_front(deq.back());
			deq.pop_back();
		}
		for(j=0; j<deq.size();j++) {
			if(deq.front() == x) break;
			deq.push_back(deq.front());
			deq.pop_front();
			left++;
		}
		deq.pop_front();
		result += left > right ? right : left;
	}
	cout << result;
}
