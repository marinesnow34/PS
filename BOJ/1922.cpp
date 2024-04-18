#include <bits/stdc++.h>

using namespace std;

int uni[1005];

int find_p(int c){
    if(c == uni[c]) return c;
    return c = find_p(uni[c]);
}

void make_uni(int a, int b){
    int aa = find_p(a);
    int bb = find_p(b);
    if(aa < bb) uni[bb] = aa;
    else uni[aa] = bb;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M, connect = 0, fee = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) uni[i] = i;

    priority_queue<pair<int, pair<int, int> > > pq;

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c,{a,b}});
    }

    while(!pq.empty()){
        if(connect == N - 1) break;
        auto now = pq.top();
        pq.pop();

        if(find_p(now.second.first) == find_p(now.second.second)) continue;
        connect++;
        fee += -now.first;
        make_uni(now.second.first, now.second.second);
    }

//    for(int i = 1; i <= N; i++) cout << uni[i] << " ";
    cout << fee;

    return 0;
}
