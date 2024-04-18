#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, large = 0;
int paper[501][501], vis[501][501];

int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

void bfs(int x, int y){
    int size = 1;
    vis[x][y] = 1;
    queue<pair<int, int> > q;
    q.push({x, y});

    while(!q.empty()){
        auto now_x = q.front().first, now_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int tmp_x = now_x + move_x[i], tmp_y = now_y + move_y[i];
            if(tmp_x < 0 || tmp_x >= n || tmp_y < 0 || tmp_y > m || vis[tmp_x][tmp_y] || !paper[tmp_x][tmp_y]) continue;
            vis[tmp_x][tmp_y] = 1;
            size++;
            q.push({tmp_x, tmp_y});
        }
    }

    large = max(large, size);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> paper[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || !paper[i][j]) continue;
            bfs(i, j);
            cnt++;
        }
    }
    cout << cnt << "\n" << large;
    return 0;
}
