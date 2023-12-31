#include <bits/stdc++.h>

using namespace std;

int N, M, a[11][11], tmp[11][11], m = 65, c_cctv;
vector<pair<int, int> > cctv;

void make_watch(int& x, int& y, int& type){
    //우측
    if(type == 1 || type == 5 || type == 7 || type == 8 || type == 11 || type == 12 || type == 14 || type == 15){
        for(int i = y + 1; i < M; i++){
//            cout << x << " " << i << "\n";
            if(tmp[x][i] == -1) break;
            if(tmp[x][i] == 0) tmp[x][i] = -2;
        }
    }
    //아래
    if(type == 2 || type == 6 || type == 8 || type == 9 || type == 11 || type == 12 || type == 13 || type == 15){
        for(int i = x + 1; i < N; i++){
            if(tmp[i][y] == -1) break;
            if(tmp[i][y] == 0) tmp[i][y] = -2;
        }
    }

    //좌측
    if(type == 3 || type == 5 || type == 9 || type == 10 || type == 12 || type == 13 || type == 14 || type == 15){
        for(int i = y - 1; i > -1; i--){
            if(tmp[x][i] == -1) break;
            if(tmp[x][i] == 0) tmp[x][i] = -2;
        }
    }
    //상단
    if(type == 4 || type == 6 || type == 7 || type == 10 || type == 11 || type == 13 || type == 14 || type == 15){
        for(int i = x - 1; i > -1; i--){
            if(tmp[i][y] == -1) break;
            if(tmp[i][y] == 0) tmp[i][y] = -2;
        }
    }
}

void start_watch(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmp[i][j] == -2) tmp[i][j] = 0;
        }
    }
    for(int i = 0; i < c_cctv; i++) {
        int x = cctv[i].first, y = cctv[i].second;
        make_watch(x, y, tmp[x][y]);
    }
}

int count_spot(){
    int c = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmp[i][j] == 0) c++;
        }
    }
    return c;
}

void func(int n){
    if(n == c_cctv) {
        start_watch();
        m = min(count_spot(), m);
        return;
    }
    if(a[cctv[n].first][cctv[n].second] == 1){
        for(int i = 1; i <= 4; i++) {
            tmp[cctv[n].first][cctv[n].second] = i;
            func(n + 1);
        }
    }
    else if(a[cctv[n].first][cctv[n].second]==2){
        for(int i = 5; i <= 6; i++) {
            tmp[cctv[n].first][cctv[n].second] = i;
            func(n + 1);
        }
    }
    else if(a[cctv[n].first][cctv[n].second]==3){
        for(int i = 7; i <= 10; i++) {
            tmp[cctv[n].first][cctv[n].second] = i;
            func(n + 1);
        }
    }
    else if(a[cctv[n].first][cctv[n].second]==4){
        for(int i = 11; i <= 14; i++) {
            tmp[cctv[n].first][cctv[n].second] = i;
            func(n + 1);
        }
    }
    else if(a[cctv[n].first][cctv[n].second]==5){
        tmp[cctv[n].first][cctv[n].second] = 15;
        func(n + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == 6) tmp[i][j] = -1;
            else if(a[i][j]) cctv.push_back({i, j});
        }
    }
    c_cctv = (int) cctv.size();
    func(0);

    cout << m;
    return 0;
}
