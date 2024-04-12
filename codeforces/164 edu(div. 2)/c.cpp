#include <bits/stdc++.h>

using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        string x, y, r_x = "", r_y = "";
        int flag = 1;
        cin >> x >> y;
        for(int i = 0; i < x.size(); i++){
            if(flag){
                if(x[i] > y[i]){
                    r_x += x[i];
                    r_y += y[i];
                }
                else if(x[i] == y[i]){
                    r_x += x[i];
                    r_y += y[i];
                    continue;
                }
                else{
                    r_x += y[i];
                    r_y += x[i];
                }
                flag = 0;
            }
            else{
                if(x[i] >= y[i]){
                    r_x += y[i];
                    r_y += x[i];
                }
                else{
                    r_x += x[i];
                    r_y += y[i];
                }
            }
        }
        cout << r_x << "\n" << r_y << "\n";
 
 
    }
    return 0;
}