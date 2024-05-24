#include <bits/stdc++.h>

using namespace std;

int vvisit[2005] = {0, };
int cnt = 0;
int sol = 0;

void func(vector<vector<int> >& person, int& now){
    if(sol) return;
    if(cnt == 5){
        sol = 1;
        return;
    }
    for(int i : person[now]){
        if(vvisit[i]) continue;
        vvisit[i] = 1;
        cnt += 1;
        func(person, i);
        vvisit[i] = 0;
        cnt -= 1;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > person(N, vector<int> (0));
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        person[a].push_back(b);
        person[b].push_back(a);
    }
    for(int i = 0; i < N && sol == 0; i++) {
        vvisit[i] = 1;
        cnt++;
        func(person, i);
        vvisit[i] = 0;
        cnt--;
    }
    cout << sol;

    return 0;
}
