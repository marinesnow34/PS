#include<bits/stdc++.h>
 
using namespace std;
 
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
 
    for(int i = 1; i <= T; i++){
        int N, cnt = 0;
        cin >> N;
        vector<vector<int> > visit(N, vector<int>(N, 0)), mine(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                char tmp;
                cin >> tmp;
                if(tmp == '*'){
                    visit[i][j] = -1;
                    mine[i][j] = -1;
                    for(int k  = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || x >= N || y < 0 || y >= N || mine[x][y] == -1) continue;
                        mine[x][y]++;
                    }
                }
            }
        }
        queue<pair<int, int> > q;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mine[i][j] == 0 && visit[i][j] == 0){
                    q.push({i,j});
                    cnt++;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if(visit[x][y] != 0) continue;
                        if(visit[x][y] == 0 && mine[x][y] == 0){
                            for(int k = 0; k < 8; k++){
                                int tmpx = x + dx[k];
                                int tmpy = y + dy[k];
                                if(tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N || visit[tmpx][tmpy] != 0 || visit[tmpx][tmpy] == -1) continue;
                                q.push({tmpx, tmpy});
                            }
                        }
                        visit[x][y] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(visit[i][j] == 0) cnt++;
            }
        }
 
        cout << "#" << i << " " << cnt <<"\n";
    }
 
    return 0;
}
