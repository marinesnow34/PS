#include <bits/stdc++.h>

using namespace std;

int vis[100005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int> > tree(N+1);
    for(int i = 0; i < N - 1; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }
    queue<int> q;
    vis[1] = 1;
    q.push(1);


    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i = 0; i < tree[p].size(); i++){
            int now = tree[p][i];
            if(vis[now]) continue;
            vis[now] = p;
            q.push(now);
        }
    }
    for(int i = 2; i <= N; i++) cout << vis[i] << "\n";
}
