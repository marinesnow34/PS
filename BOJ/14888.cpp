#include <bits/stdc++.h>

using namespace std;

// 완전 탐색
// 최대, 최소 +- 10억


int a[12], N;
int cal[4], sol_min = 1100000000, sol_max = -1100000000;

void func(int n, int s){
    if(N == n + 1){
        sol_min = min(sol_min, s);
        sol_max = max(sol_max, s);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(cal[i] == 0) continue;
        cal[i] -= 1;
        if(i == 0) func(n+1, s + a[n+1]);
        if(i == 1) func(n+1, s - a[n+1]);
        if(i == 2) func(n+1, s * a[n+1]);
        if(i == 3) func(n+1, s / a[n+1]);
        cal[i] += 1;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> cal[i];
    func(0, a[0]);
    cout << sol_max << "\n" << sol_min;
}
