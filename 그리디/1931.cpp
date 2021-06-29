#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Meeting{
	int start, end;
} Meeting;

int N;
Meeting arr[100000];

bool compare(Meeting a, Meeting b){
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else return a.end < b.end;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].start, &arr[i].end);
	
	sort(arr, arr+N, compare);

	int now = 0, ans = 0;
	for (int i = 0; i < N; i++){
		if (now <= arr[i].start){
			now = arr[i].end;
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}