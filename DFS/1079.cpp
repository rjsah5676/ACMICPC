#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;
 
int n;
int score[17];
int chk[17];
int maf[17][17];
int en;
 
int ans = 0;
 
int fk() {
    int maxx = 0;
    int id;
    for (int i = 0; i < n; i++) {
        if (score[i] > maxx && chk[i]==0) {
            maxx = score[i];
            id = i;
        }
    }
    return id;
}
 
void dfs(int man, int day) {
    if (chk[en] == 1 || man == 1) {
        if (day > ans) ans = day;
        return;
    }
    if (man%2==0) {
        for (int i = 0; i < n; i++) {
            if (i == en || chk[i] == 1) continue;
            chk[i] = 1;
            for (int j = 0; j < n; j++) {
                if(chk[j]==0) score[j] += maf[i][j];
            }
            dfs(man - 1, day + 1);
            for (int j = 0; j < n; j++) {
                if (chk[j] == 0) score[j] -= maf[i][j];
            }
            chk[i] = 0;       
        }
    }
    else {
        int ki = fk();
        if (ki == en) {
            if (day > ans) ans = day;
            return;
        }
        chk[ki] = 1;
        dfs(man - 1, day);
        chk[ki] = 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>score[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>maf[i][j];
        }
    }
    cin>>en;
    dfs(n, 0);
    cout<<ans;
    return 0;
}
