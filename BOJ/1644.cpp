#include <bits/stdc++.h>

using namespace std;

vector<int> pri(1, 0);
int vis[4000005];

void era(int n){
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            pri.push_back(i);
            long tmp = i;
            while(tmp * i <= n) {
                vis[tmp * i] = 1;
                tmp++;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, cnt = 0;
    cin >> N;

    era(N);
    int st = 0, en = 0, s = 0;
    while(st < pri.size() && en < pri.size() && pri[st] <= N){
        if(s == N){
            s -= pri[st];
            cnt++;
            st++;
            en++;
            s += pri[en];
        }
        else if(s < N){
            en++;
            s += pri[en];
        }
        else{
            s -= pri[st];
            st++;
        }
    }
    cout << cnt;
    return 0;
}
