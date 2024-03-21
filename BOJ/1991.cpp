#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > tree(26);

void pre(int n){
    cout << (char) (n + 65);
    if(tree[n].first > -1) pre(tree[n].first);
    if(tree[n].second > -1) pre(tree[n].second);
}

void inorder(int n){
    if(tree[n].first > -1) inorder(tree[n].first);
    cout << (char) (n + 65);
    if(tree[n].second > -1) inorder(tree[n].second);
}

void postorder(int n){
    if(tree[n].first > -1) postorder(tree[n].first);
    if(tree[n].second > -1) postorder(tree[n].second);
    cout << (char) (n + 65);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;

    while(N--){
        char node, left, right;
        cin >> node >> left >> right;
        if(left == '.') tree[node - 65].first = -1;
        else tree[node - 65].first = left - 65;
        if(right == '.') tree[node - 65].second = -1;
        else tree[node - 65].second = right - 65;
    }
    pre(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
}
