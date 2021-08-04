#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > ju;
vector<ll> c;
ll n,k;
priority_queue<ll> pq;
int main()
{
	cin>>n>>k;
	ll m,v;
	int i;
	for(i=0;i<n;i++){	
		scanf("%lld %lld",&m,&v);
		ju.push_back(make_pair(m,v));
	}
	for(i=0;i<k;i++) {
		scanf("%lld", &m);
		c.push_back(m);
	}
	sort(ju.begin(),ju.end());
	sort(c.begin(),c.end());
	ll res=0;
	int tmp=0;
	for(i=0;i<k;i++){
		for(int j=tmp;j<n;j++){
			if(ju[j].first<=c[i]) {
				pq.push(ju[j].second);
				tmp++;
			}
			else break;
		}
		if(!pq.empty()) {
			res+=pq.top();
			pq.pop();
		}
	}
	cout<<res;
	return 0;
}
