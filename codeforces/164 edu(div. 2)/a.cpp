#include <bits/stdc++.h>
 
// 단일 색의 최대 값
// n - 단일색의 최대 값
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        if(n == 1 || m == 1){
            cout << "NO\n";
            continue;
        }
        int tmp = n / m;
        if(n%m != 0) tmp++;
        if(n - tmp <= k){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
 
    return 0;
}