#include<bits/stdc++.h>

using namespace std;

int N, M, m = 0;
int room[9][9], virus[9][9];

int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x,y});
    while(!q.empty()){
        auto now = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int tmp_x = now.first + move_x[i];
            int tmp_y = now.second + move_y[i];
            if(tmp_x >= N || tmp_y >= M || tmp_x < 0 || tmp_y < 0 || virus[tmp_x][tmp_y] != 0) continue;
            virus[tmp_x][tmp_y] = 2;
            q.push({tmp_x, tmp_y});
        }
    }
}

void count_clean(){
    int tmp = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            virus[i][j] = room[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            if(virus[i][j] == 2) bfs(i,j);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            if(virus[i][j] == 0) tmp++;
    }

    m = max(m, tmp);
}

void func(int n, int k, int l){
    if(n == 3){
        count_clean();
        return;
    }
    for(int i = k; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == k && j == 0) j = l;
            if(room[i][j] != 0) continue;
            room[i][j] = 1;
            func(n+1, i, j);
            room[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> room[i][j];
        }
    }
    func(0,0,0);
    cout << m;
    return 0;
}
