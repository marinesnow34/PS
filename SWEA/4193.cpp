#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<int> >& sea, pair<int, int> start, pair<int, int> end){
    vector<vector<int> > visit(sea.size(),vector<int> (sea.size(), -1));
    priority_queue<pair<int, pair<int,int> > > pq; // {시간, {x, y}}
    pq.push({0,start});
    visit[start.first][start.second] = -2;
    while(!pq.empty()){
        int dis = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        if(x == end.first && y == end.second) break;
        pq.pop();
        for(int i = 0; i < 4; i++){
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            int tmp_dis = dis + 1;
            if(tmpx < 0 || tmpx >= sea.size() || tmpy < 0 || tmpy >= sea.size()) continue;
            if(sea[tmpx][tmpy] == 1) continue;
            if(sea[tmpx][tmpy] == 2 && tmp_dis % 3){
                tmp_dis = tmp_dis + (3 - tmp_dis % 3);
            }
            if(visit[tmpx][tmpy] <= tmp_dis && visit[tmpx][tmpy] != -1) continue;
            pq.push({-tmp_dis,{tmpx, tmpy}});
            visit[tmpx][tmpy] = tmp_dis;
        }
    }
    return visit[end.first][end.second];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        vector<vector<int> > sea(N,vector<int> (N));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> sea[i][j];
            }
        }
        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;
        cout << "#" << i << " " << bfs(sea, start, end) <<"\n";
    }

    return 0;
}
