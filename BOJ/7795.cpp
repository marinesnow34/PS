#include <bits/stdc++.h>

using namespace std;

int a[20005], b[20005], T;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        int tmp1, tmp2, cnt = 0;
        cin >> tmp1 >> tmp2;
        for(int i = 0; i < tmp1; i++) cin >> a[i];
        for(int i = 0; i < tmp2; i++) cin >> b[i];
        sort(a, a + tmp1);
        sort(b, b + tmp2);
        int lidx = 0, ridx = 0;
        while(lidx < tmp1 && ridx < tmp2){
            if(a[lidx] > b[ridx]){
                ridx++;
            }
            else{
                cnt += ridx;
                lidx++;
            }
        }
        for(int i = lidx; i < tmp1; i++) cnt += ridx;
        cout << cnt << "\n";
    }
    return 0;
}
