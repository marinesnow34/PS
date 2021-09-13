#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector <vector<int> > sea(N, vector<int>(N));

    int shark_size = 2, shark_food = 0, time = 0;
    pair<int, int> shark_start;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sea[i][j]);
            if (sea[i][j] == 9) { shark_start.first = i; shark_start.second = j; }
        }
    }

    // 상 좌 하 우
    int go_y[4] = { 1, 0, -1, 0 };
    int go_x[4] = { 0, -1, 0, 1 };

    deque<pair<int, int> > dq;

    dq.push_back(shark_start);
    vector <vector<int> > visit(N, vector<int>(N));
    visit[shark_start.first][shark_start.second] = 1;
    pair<int, int> shark_loc;

    vector<int> find(3, 1000);

    while (!dq.empty()) {
        shark_loc = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            pair<int, int> shark_tmp;
            shark_tmp.first = shark_loc.first + go_y[i], shark_tmp.second = shark_loc.second + go_x[i];
            if (shark_tmp.second > -1 && shark_tmp.first > -1 && shark_tmp.first < N && shark_tmp.second < N && visit[shark_tmp.first][shark_tmp.second] == 0 && sea[shark_tmp.first][shark_tmp.second] <= shark_size) {
                // 자신과 같은 사이즈
                visit[shark_tmp.first][shark_tmp.second] = visit[shark_loc.first][shark_loc.second] + 1;
                if (sea[shark_tmp.first][shark_tmp.second] > 0 && sea[shark_tmp.first][shark_tmp.second] < shark_size && visit[shark_tmp.first][shark_tmp.second] <= find[2]) {
                    if (shark_tmp.first == find[0] && sea[shark_tmp.first][shark_tmp.second] != 0) {
                        if (shark_tmp.second < find[1]) find[1] = shark_tmp.second;
                        find[2] = visit[shark_tmp.first][shark_tmp.second];
                    }
                    if (shark_tmp.first < find[0] && sea[shark_tmp.first][shark_tmp.second] != 0) {
                        find[0] = shark_tmp.first;
                        find[2] = visit[shark_tmp.first][shark_tmp.second];
                        find[1] = shark_tmp.second;
                    }
                }
                // 지나갑니다
                else {
                    dq.push_back(shark_tmp);
                }
            }
        }
        if ((visit[shark_loc.first][shark_loc.second] > find[2] || dq.empty()) && find[0] != 1000) {
            shark_food += 1;
            if (shark_size == shark_food) {
                shark_size += 1;
                shark_food = 0;
            }
            sea[shark_start.first][shark_start.second] = 0;
            shark_start.first = find[0]; shark_start.second = find[1];
            
            time += find[2] - 1;
            
            
            //vector <vector<int> > visit(N, vector<int>(N));
            for (int l = 0; l < N; l++) for (int j = 0; j < N; j++) visit[l][j] = 0;
            visit[shark_start.first][shark_start.second] = 1;

            sea[find[0]][find[1]] = 9;
            find[0] = 1000, find[1] = 1000, find[2] = 1000;
            dq.clear();
            dq.push_back(shark_start);
        }
    }

    printf("%d", time);
    return 0;
}