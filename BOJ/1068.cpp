#include <bits/stdc++.h>

using namespace std;

int res = 0, drop;

void func(vector<vector<int> >& tree, int& now) {
    if(now == drop) return;
    if(!tree[now].size()){
        res++;
        return;
    }
    for(int i = 0; i < tree[now].size(); i++) {
        if(tree[now][i] == drop){
            if(tree[now].size() == 1) res++;
            continue;
        }
        func(tree, tree[now][i]);
    }

}

int main() {
    int N, top;
    cin >> N;
    vector<vector<int> > tree(N, vector<int> (0));

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(tmp == -1) top = i;
        else tree[tmp].push_back(i);
    }

    cin >> drop;

    func(tree, top);
    cout << res;

    return 0;
}
