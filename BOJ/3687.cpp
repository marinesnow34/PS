#include <bits/stdc++.h>

using namespace std;
/*
 * 2개 1
 * 3개 7
 * 4개 4,
 * 5개 2, 3, 5
 * 6개 0, 6, 9
 * 7개 8
----
 * 1 개 x
 * 2 개 1
 *
 *
*/

long long INF = 1000000000000000;
int m_num[8] = {0,0, 1,7,4,2,0,8};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long dp[105] = {0, 9, 1, 7, 4, 2, 6, 8};
    for(int i = 8; i < 105; i ++) dp[i] = INF;
    for(int i = 8; i < 101; i++){
        for(int j = 2; j < 8; j++){
            dp[i] = min(dp[i], dp[i-j] * 10 + m_num[j]);
        }
    }
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << dp[n] << " ";
        while(n != 0){
            if(n%2 == 1){
                cout << "7";
                n -= 3;
            }
            else{
                cout << "1";
                n -= 2;
            }
        }
        cout << "\n";
    }
}
