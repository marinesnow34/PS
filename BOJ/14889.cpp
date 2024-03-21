#include <bits/stdc++.h>

using namespace std;

int N, t[25][25], vis[25] = {0, }, m = 100000000;

int calcTeamDiff(){
    int t1 = 0, t2 = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            if(vis[i] != vis[j]) continue;
            if(vis[i]) t1 += t[i][j];
            else t2 += t[i][j];
        }
    return abs(t1-t2);
}

void back(int n, int start){
    if(n == N / 2){
        m = min(m, calcTeamDiff());
        return;
    }
    for(int i = start; i <= N; i++){
        vis[i] = 1;
        back(n + 1, i + 1);
        vis[i] = 0;
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) cin >> t[i][j];
    back(0, 1);
    cout << m;
}
