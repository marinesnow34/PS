#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int test_case;
    cin >> test_case;
    while(test_case--){
        int h, w;
        cin >> h >> w;
        /*
         * 상하 좌우 1씩 확장
         * why? 주변을 0으로 채우기 위해서
         */
        vector<vector<char> > jail(h + 2, vector<char>(w + 2, '.'));
        vector<pair<int, int> > person(1, {0,0});
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> jail[i][j];
                if(jail[i][j] == '$') person.push_back({i, j});
            }
        }
        /*
         * 각 사람별 bfs 시작
         * visit[인원][x좌표][y좌표]을 -1로 채워서 문 연 횟수 구하기
         * -1로 채우는 이유 문을 연횟수 0과 미방문을 구분하기 위해서
         */
        vector<vector<vector<int> > > visit(3, vector<vector<int> >(h + 2, vector<int>(w + 2, -1)));
        for(int i = 0; i < 3; i++){
            // bfs 시작 전 세팅
            visit[i][person[i].first][person[i].second] = 0;
            // pq세팅 {문 횟수 * -1, {x, y}}
            priority_queue<pair<int, pair<int, int> > > pq;
            pq.push({0,{person[i].first, person[i].second}});
            while(!pq.empty()){
                int door_count = -pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();

                for(int j = 0; j < 4; j++){
                    int new_x = x + dx[j];
                    int new_y = y + dy[j];
                    if(new_x < 0 || new_x >= h + 2 || new_y < 0 || new_y >= w + 2) continue; // 배열 범위 초과
                    if(jail[new_x][new_y] == '*' || visit[i][new_x][new_y] != -1) continue; // 방문 불가 지역 || 이미 방문
                    visit[i][new_x][new_y] = door_count;
                    if(jail[new_x][new_y] == '#') visit[i][new_x][new_y]++; //문 열면 +1
                    pq.push({-visit[i][new_x][new_y], {new_x, new_y}});
                }
            }

        }
        /*
         * 합이 최소인 곳 구하기
         * 합이 최소인 곳이 셋이 최소로 와서 만나는 중점임
         * 문인 곳은 -2 해주기
         */
        int min_count = 30005;
        for(int i = 0; i < h + 2; i++){
            for(int j = 0; j < w + 2; j++){
                if(visit[0][i][j] < 0) continue; //미방문
                int sum_tmp = 0; // 3개의 합
                if(jail[i][j] == '#') sum_tmp -= 2; // 문 중복 카운트 빼주기
                for(int k = 0; k < 3; k++){
                    sum_tmp += visit[k][i][j];
                }
                min_count = min(min_count, sum_tmp);
            }
        }
        cout << min_count << "\n";
    }
    return 0;
}
