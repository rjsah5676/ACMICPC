#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int x_cnt=0;
    int y_cnt=0;
    
    vector<int> m;
    vector<int> n;
    int memo[1000001] = { 0, };
    int memo2[1000001] = { 0, };
    m.push_back(++x_cnt);
    n.push_back(++y_cnt);
    memo[topping[0]]++;
    memo2[topping[topping.size()-1]]++;
    for(int i=1;i<topping.size()-1;i++) {
        if(memo[topping[i]] == 0) {
            memo[topping[i]]++;
            m.push_back(++x_cnt);
        }
        else {
            m.push_back(x_cnt);
        }
    }
    for(int i=topping.size()-2;i>0;i--) {
        if(memo2[topping[i]] == 0) {
            memo2[topping[i]]++;
            n.push_back(++y_cnt);
        }
        else {
            n.push_back(y_cnt);
        }
    }
    for(int i=0;i<m.size();i++){
        if(m[i] == n[m.size()-i-1]) answer++;
    }
    cout<<answer;
    return answer;
}