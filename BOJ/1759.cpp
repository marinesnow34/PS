#include <bits/stdc++.h>

using namespace std;

int L, C, aeiou = 0, not_aeiou = 0;

char alpha[20], res[20];

void back(int n, int now){
    if(n == L){
        if(aeiou > 0 && not_aeiou > 1){
            for(int i = 0; i < L; i++) cout << res[i];
            cout << "\n";
        }
        return;
    }
    for(int i = now; i < C; i++){
        res[n] = alpha[i];
        if(alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u'){
            aeiou++;
            back(n+1, i + 1);
            aeiou--;
        }
        else{
            not_aeiou++;
            back(n+1, i + 1);
            not_aeiou--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> alpha[i];
    }
    sort(alpha, alpha + C);

    back(0, 0);
}
