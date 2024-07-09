#include <iostream>
#include <map>
#include <queue>

using namespace std;

//0은 본인 1은 좌회전 2는 우회전 3은 반바퀴
map<string, int> move_set = {
	{"RR",0},{"RU",1},{"RD",2},{"RL",3},
	{"UU",0},{"UL",1},{"UR",2},{"UD",3},
	{"LL",0},{"LD",1},{"LU",2},{"LR",3},
	{"DD",0},{"DR",1},{"DL",2},{"DU",3}
};

char m[4] = {'D', 'R', 'U', 'L'};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char maze[55][55], vis[55][55][4];
int R, C, K;

int main(){
    int res = 0;
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
		}
	}

	priority_queue<pair<pair<int,int>, pair<int,int> > > pq;

    pq.push({{0,0},{0,0}});

    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        // cout << -now.first.first << " " << -now.first.second << " | " << now.second.first << " " << now.second.second << "\n";
        if(now.second.first == R - 1 && now.second.second == C - 1) {
            res = 1; // 성공
            break;
        }
        for(int i = 0; i < 4; i++) {
            int x = now.second.first + dx[i];
            int y = now.second.second + dy[i];
            int left = -now.first.first;
            int right = -now.first.second;
            if(x < 0 || x >= R || y < 0 || y >= C || vis[x][y][i]) continue;
            string move = string(1, maze[now.second.first][now.second.second]) + m[i];
            if(move_set[move] == 3) continue;
            else if(move_set[move] == 1) right++;
            else if(move_set[move] == 2) left++;
            // cout << move << " " << left << " " << right << " | " << x << " " << y << "\n";
            if(left > K || right > K) continue;
            pq.push({{-left, -right},{x, y}});
            vis[x][y][i] = 1;
        }
    }

    if(res) cout << "Yes";
    else cout << "No";

	return 0;
}