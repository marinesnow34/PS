#include <bits/stdc++.h>

using namespace std;

int a[1000005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string tmp;
    int n, sum = 0, c;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    c = n*15;
    if(c/10%10 >= 5) c += 100;
    c /=100;
    for(int i = c; i < n - c; i++) {
        sum += a[i];
    }
    sum = sum * 10 / (n - 2 * c);
    if(sum%10 >= 5) sum += 10;
    sum /= 10;
    cout << sum;
    return 0;
}
