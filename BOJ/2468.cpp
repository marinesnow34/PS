#include <bits/stdc++.h>

using namespace std;

int N, m[105][105], vis[105][105] = {0, }, max_safe = 1, min_height = 101, max_height = 0;

int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};

void bfs(int x, int y, int rain){
    queue<pair<int, int> > q;
    q.push({x,y});
    vis[x][y] = rain;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int new_x = now.first + mx[i], new_y = now.second + my[i];
            if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N || vis[new_x][new_y] == rain) continue;
            vis[new_x][new_y] = rain;
            q.push({new_x, new_y});
        }
    }
}

void findSafe(int rain){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int safe = 0;
    //비온거 채우기
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] <= rain) vis[i][j] = rain;
        }
    }
    //안전 지대 파악
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            if(vis[i][j] != rain) {
                bfs(i,j, rain);
                safe++;
            }
        }
    }
    max_safe = max(max_safe, safe);
}

int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
            max_height = max(max_height, m[i][j]);
            min_height = min(min_height, m[i][j]);
        }
    }

    for(int i = min_height; i < max_height; i++){
        findSafe(i);
    }

    cout << max_safe;
}
