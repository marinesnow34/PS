#include<bits/stdc++.h>

using namespace std;

vector<string> m;
int N, M, big = 0;

int m_x[4] = {1, -1, 0, 0};
int m_y[4] = {0, 0, 1, -1};

int bfs(int x, int y){
    int time = 0;
    vector<vector<int> > vis(N,vector<int>(M, 0));

    queue<pair<int, int> > q;

    q.push({x, y});
    vis[x][y] = 1;

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        time = max(time, vis[now.first][now.second]);

        for(int i = 0; i < 4; i++){
            int tmp_x = now.first + m_x[i], tmp_y = now.second + m_y[i];
            if(tmp_x >= N || tmp_x < 0 || tmp_y >= M || tmp_y < 0 || m[tmp_x][tmp_y] == 'W' || vis[tmp_x][tmp_y] > 0) continue;

            q.push({tmp_x, tmp_y});
            vis[tmp_x][tmp_y] = vis[now.first][now.second] + 1;
        }
    }

    return time - 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        m.push_back(tmp);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(m[i][j] == 'W') continue;
            int time = bfs(i, j);
            big = max(big, time);
        }
    }
    cout << big;
    return 0;
}
