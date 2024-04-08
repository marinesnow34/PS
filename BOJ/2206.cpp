#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, sol = 10000000;

int m[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(){
    vector<vector<vector<int> > > vis(N, vector<vector<int> >(M, vector<int>(2, 0)));
    queue<pair<int, pair<int, int> > > q;
    q.push({0,{0, 0}});
    vis[0][0][0] = 0; // 벽뚫은 갯수
    vis[0][0][1] = 1; // 방문

    while(!q.empty()){
        auto now_wall = q.front().first,
        now_x = q.front().second.first, now_y = q.front().second.second;
        q.pop();
        if(now_x == N - 1 && now_y == M - 1){
            sol = min(sol, vis[N-1][M-1][1]);
            return;
        }
        for(int i = 0; i < 4; i++){
            int x = now_x + dx[i], y = now_y + dy[i];
            if(x < 0 || x >= N || y < 0 || y >= M) continue;
            if(now_wall && m[x][y]) continue;
            else if(!now_wall && !m[x][y]){ // 0번 뚫은 상태
                if(!vis[x][y][0]){
                    if(vis[x][y][1]) continue;
                }
                vis[x][y][0] = 0;
                vis[x][y][1] = vis[now_x][now_y][1] + 1;
                q.push({0, {x, y}});
            }
            else {
                if(vis[x][y][1]) continue;
                vis[x][y][0] = 1;
                vis[x][y][1] = vis[now_x][now_y][1] + 1;
                q.push({1, {x, y}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            m[i][j] = tmp - '0';
        }
    }

    bfs();

    if(sol == 10000000) cout << -1;
    else cout << sol;

    return 0;
}
