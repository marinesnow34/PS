#include <bits/stdc++.h>

using namespace std;

int a[45][45], s[11][11], tmp[11][11], N, M, K, x, y, cnt = 0;

void turn(){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            tmp[i][j] = 0;
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            tmp[j][abs(x-i) -1] = s[i][j];
        }
    }
    for(int i = 0; i < max(x, y); i++){
        for(int j = 0; j < max(x, y); j++){
            s[i][j] = tmp[i][j];
        }
    }
    swap(x, y);
}

bool valid(int aa, int bb){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(a[aa+i][bb+j] == 1 && a[aa+i][bb+j] == s[i][j]) return false;
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(s[i][j]) a[aa+i][bb+j] = 1;
        }
    }
    return true;
}

bool func(){
    for(int i = 0; i < N - x + 1; i++){
        for(int j = 0; j < M - y + 1; j++){
            if(valid(i, j)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    while(K--){
        cin >> x >> y;
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                cin >> s[i][j];
            }
        }
        for(int i = 0; i < 4; i++){
            if(func()) break;
            else{
                turn();
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
