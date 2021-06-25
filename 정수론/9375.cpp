#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(void){
    int n, t; 
	cin >> t;
    for(int i = 0; i < t; i++){
        unordered_map<string, int> data;
		cin >> n;
        for(int i = 0; i < n; i++){
            string name; 
			string kind;
            cin >> name >> kind;
            if(data.find(kind) == data.end()){
                data.insert({kind,1});
            }
            else{
                data[kind]++;
            }

        }
        int result = 1;
        for(auto kind : data ){
            result *= (kind.second + 1);
        }
        result -= 1;
        cout << result << endl;
    }
    return 0;
}