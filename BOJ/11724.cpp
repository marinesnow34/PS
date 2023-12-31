#include <bits/stdc++.h>

using namespace std;

int N, M, arr[1004], cnt = 0;

int find(int a){
    if(a == arr[a]) return a;
    return arr[a] = find(arr[a]);
}

void make_union(int a, int b){
    int aa = find(a);
    int bb = find(b);

    if(aa < bb) arr[bb] = aa;
    else arr[aa] = bb;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) arr[i] = i;
    for(int i = 0; i < M; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        make_union(tmp1, tmp2);
    }

    for(int i = 1; i <= N; i++) {
        if(i == arr[i]) cnt++;
    }

    cout << cnt;
    return 0;
}
