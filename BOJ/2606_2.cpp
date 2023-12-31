#include <bits/stdc++.h>

using namespace std;

int N, M, cnt = 0, vis[105] = {0,};
deque<int> dq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    vector<vector<int> > a(N+1);
    for(int i = 0; i < M; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
    dq.push_back(1);
    vis[1] = 1;
    while(!dq.empty()){
        int tmp = dq.front();
        dq.pop_front();
        for(int i = 0; i < a[tmp].size(); i++){
            if(!vis[a[tmp][i]]){
                cnt++;
                dq.push_back(a[tmp][i]);
                vis[a[tmp][i]] = 1;
            }
        }
    }
    cout << cnt;
    return 0;
}
