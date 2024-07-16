#include <iostream>
#include <cmath>

using namespace std;

long dot[10005][2];

int main(){
    long N, x1, x2, y1, y2;
    double s = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dot[i][0] >> dot[i][1];
    }
    // ay = bx + c
    // (x2 - x1)(y - y1) = (y2-y1)(x - x1)
    for(int i = 1; i < N - 1; i++){
        long x1 = dot[i][0], y1 = dot[i][1], x2 = dot[i+1][0], y2 = dot[i+1][1];
        double x = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        // |(x2 - x1)(tmpy - y1) = (y2-y1)(tmpx - x1)|
        // sqrt((x2-x1)^2 + (y2-y1)^2)

        s += x * (((x2 - x1)*(dot[0][1] - y1) + (y2-y1)*(dot[0][0] - x1) * -1) / sqrt(pow(x2-x1, 2) + pow(y2-y1,2))) / 2;
    }
    printf("%.1f", abs(s));
    return 0;
}
