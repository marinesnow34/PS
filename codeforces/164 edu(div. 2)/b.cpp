#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, sol = -1;
        cin >> n;
        int arr[300005];
        vector<int> iidx(0);
        for(int i = 0; i < n; i++) cin >> arr[i];
 
        int tmp = arr[0];
 
        for(int i = 0; i < n; i++){
            if(tmp != arr[i]) iidx.push_back(i);
        }
        int m = 100000000;
        if(iidx.size() == 0){
            cout << -1 << "\n";
            continue;
        }
        for(int i = 0; i < (int)iidx.size() - 1; i++){
            m = min(m, iidx[i+1] - iidx[i] - 1);
        }
        int k = min(iidx[0], n - iidx[iidx.size() - 1] - 1);
        cout << min(m,k) << "\n";
    }
    return 0;
}