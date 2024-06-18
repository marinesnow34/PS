#include <bits/stdc++.h>

using namespace std;

int student[1000005];
int N, K;

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        student[i] = student[i - 1] + tmp;
    }
    while(K--){
        int A, B;
        cin >> A >> B;
        printf("%.2f\n", (double) (student[B] - student[A-1]) / (B - A + 1));
    }
    return 0;
}
