#include <bits/stdc++.h>

using namespace std;

int mov_x[8] = {1,2,2,1,-1,-2,-2,-1};
int mov_y[8] = {-2,-1,1,2,2,1,-1,-2};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<vector<int> > chess(N, vector<int> (N, 0)), vis(N, vector<int> (N, 0));

        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;

        queue<pair<int, int> > q;
        vis[s_x][s_y] = 1;
        q.push({s_x, s_y});

        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if(now.first == e_x && now.second == e_y){
                cout << vis[e_x][e_y] - 1 << "\n";
            }
            for(int i = 0; i < 8; i++){
                int tmp_x = now.first + mov_x[i], tmp_y = now.second + mov_y[i];
                if(tmp_x >= N || tmp_x < 0 || tmp_y >= N || tmp_y < 0 || vis[tmp_x][tmp_y]) continue;
                vis[tmp_x][tmp_y] = vis[now.first][now.second] + 1;
                q.push({tmp_x, tmp_y});
            }
        }
    }
}
