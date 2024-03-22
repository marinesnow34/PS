#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, m[3], now_max[3] = {0, }, now_min[3] = {0, };
    cin >> N;
    for(int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        now_max[i] = tmp;
        now_min[i] = tmp;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++) cin >> m[j];
        int tmp0 = now_max[0], tmp1 = now_max[1], tmp2 = now_max[2];
        now_max[0] = max(m[0] + tmp0, m[0] + tmp1);
        now_max[1] = max(m[1] + tmp0, max(m[1] + tmp1, m[1] + tmp2));
        now_max[2] = max(m[2] + tmp2, m[2] + tmp1);

        tmp0 = now_min[0], tmp1 = now_min[1], tmp2 = now_min[2];
        now_min[0] = min(m[0] + tmp0, m[0] + tmp1);
        now_min[1] = min(m[1] + tmp0, min(m[1] + tmp1, m[1] + tmp2));
        now_min[2] = min(m[2] + tmp2, m[2] + tmp1);
    }
    cout << max(now_max[0], max(now_max[1], now_max[2])) << " " << min(now_min[0], min(now_min[1], now_min[2]));
}
