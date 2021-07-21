#include<iostream>
#include<algorithm>
using namespace std;
int home[200001];

int main()
{
	int n,c,i;
	cin>>n>>c;
	for(i=0;i<n;i++)
		cin>>home[i];
	sort(home,home+n);
	int left=1;	//�ּ� �Ÿ��� 
	int right=home[n-1]-home[0];//�ִ� �Ÿ��� 
	int ans=right;
	while(left<=right){
		int mid=(left+right)/2;
		int start=home[0];
		int res=1;
		for(int i=1;i<n;i++) {
			if(home[i]-start>=mid){ //���� �� 
				res++;
				start=home[i];
			}
		}
		if(res>=c){	//��� �����Ⱑ �� ���� -> ������ �÷��� �ȴ� 
			left=mid+1;
			ans=mid;
		}
		else { //�����ϴ�-> ������ �ٿ����Ѵ�. 
			right=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
