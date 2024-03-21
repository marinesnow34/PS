#include <bits/stdc++.h>

using namespace std;

int SIZE_LOTTO = 6;

int lotto[18], vis[18] = {0, }, N;

void back(int n, int now){
    if(n == SIZE_LOTTO){
        for(int i = 0; i < SIZE_LOTTO; i++) cout << lotto[vis[i]] << " ";
        cout << "\n";
    }
    for(int i = now; i < N; i++){
        vis[n] = i;
        back(n+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(1){
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++) cin >> lotto[i];
        back(0,0);
        cout << "\n";
    }
    return 0;
}
