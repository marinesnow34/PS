#include <bits/stdc++.h>

using namespace std;

int res[25] = {0,};
string sol = "";

void hanoi(int n, int now, int goal){
    if(n == 1){
        cout << now << " " << goal << "\n";
        return;
    }

    hanoi(n - 1, now, 6 - abs(now + goal));
    cout << now << " " << goal << "\n";
    hanoi(n - 1, 6 - abs(now + goal), goal);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    res[1] = 1;
    for(int i = 2; i <= N; i++) res[i] = res[i-1] * 2 + 1;
    cout << res[N] << "\n";
    hanoi(N, 1, 3);
    return 0;
}
