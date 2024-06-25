#include<bits/stdc++.h>
 
using namespace std;
 
int sol, person[25], target, N;
 
void func(int now, int s){
    if(now >= N) {
        if(s >= target) sol = min(sol, s);
        return;
    }
 
    func(now + 1, s);
    func(now + 1, s + person[now]);
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
 
    for(int i = 1; i <= T; i++){
        int B;
        cin >> N >> B;
        target = B;
        sol = 999999999;
        for(int i = 0; i < N; i++) cin >> person[i];
 
        func(0, 0);
 
        cout << "#" << i << " " << sol - B <<"\n";
    }
 
    return 0;
}
