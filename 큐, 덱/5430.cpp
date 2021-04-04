//5430
//deque

#include<iostream>
#include<deque>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,t,i,j;
	scanf("%d",&t);
	while(t--) {
		char p[100001];
		char arr[500001];
		int flag = 0; //0:front, 1:back
		deque<int> deq;
		int err = 0;
		scanf("%s",p);
		scanf("%d",&n);
		scanf("%s", arr);
		int l = strlen(arr);
		int cnt = 0;
		for(i=1;i<l;i++){
			int sum = 0;
			int go = 0;
			if(arr[i] == ',' || arr[i] == ']') {
				for(j=i-cnt;j<i;j++) {
					go = 1;
					sum += (arr[j] - 48)*pow(10,i-j-1);
				}
				cnt = 0;
				if(go) deq.push_back(sum);
			}
			else
				cnt++;
		}
		for(i=0;i<strlen(p);i++) {
			if(p[i] == 'R') flag = !flag;
			else {
				if(deq.empty()) err = 1;
				else if(flag)
					deq.pop_back();
				else deq.pop_front();
			}
		}
		if(!err) {
			int init_size=deq.size();
			printf("[");
			for(i=0;i<init_size;i++) {
				if(i==init_size-1) printf("%d]",deq.front());
				else if(flag) {
					printf("%d,",deq.back());
					deq.pop_back();
				}
				else {
					printf("%d,",deq.front());
					deq.pop_front();
				}
			}
			if(init_size == 0) printf("]");
			printf("\n");
		}
		else printf("error\n");
	}
}
