#include <bits/stdc++.h>

using namespace std;

int N, M, dis[105], open[15], vis[15], ch_size, home_size, m = 250 * 13;
vector<pair<int, int> > home, ch;

void find_max(){
    for(int j = 0; j < home_size; j++) dis[j] = 250;
    for(int i = 0; i < M; i++){
        int tmp = 0;
        for(int j = 0; j < home_size; j++) {
            dis[j] = min(dis[j], abs(home[j].first - ch[open[i]].first) + abs(home[j].second - ch[open[i]].second));
            tmp += dis[j];
        }
        m = min(m, tmp);
    }
}

void func(int n, int k){
    if(n==M){
        find_max();
        return;
    }
    for(int i = k; i < ch_size; i++){
        if(vis[i]) continue;
        open[n] = i;
        vis[i] = 1;
        func(n+1, i+1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tmp;
    for(int i = 0; i < 13; i++) open[i] = -1;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == 1) home.push_back({i,j});
            if(tmp == 2) ch.push_back({i,j});
        }
    }
    ch_size = ch.size();
    home_size = home.size();
    func(0 , 0);
    cout << m;
    return 0;
}
