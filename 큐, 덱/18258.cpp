//18258
//queue

#include<iostream>
#include<deque>
#include<string>
 
using namespace std;
 
int N;
string a;
deque<int> x;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    int t;
    for (int i = 0;i < N;i++) {
        cin >> a;
        if (a == "push") {
            cin >> t;
            x.push_back(t);
        }
        else if (a == "pop") {
            if (!x.empty()) {
                cout << x.front() << "\n";
                x.pop_front();
            }
            else
                cout << -1 << "\n";
        }
        else if (a == "size") {
            cout << x.size() << "\n";
 
        }
        else if (a == "empty") {
            if (x.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (a == "front") {
            if (x.empty())
                cout << -1 << "\n";
            else
                cout << x.front() << "\n";
        }
        else if (a == "back") {
            if (x.empty())
                cout << -1 << "\n";
            else
                cout << x.back() << "\n";
        }
    }
}

