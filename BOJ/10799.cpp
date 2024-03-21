#include <bits/stdc++.h>

using namespace std;

/*
 * 레이저 쏘면 현재 위치의 갯수 * 2
 * 괄호 -> 스택
 * 괄호의 차이가 1이면 레이저
 */

int main(){
    int count = 0;
    string s;
    cin >> s;

    stack<int> st;

    int open = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') {
            st.push(i);
            open++;
        }
        else{
            int start = st.top();
            st.pop();
            open--;
            if(i - start == 1) count += open;
            else{
                count++;
            }
        }
    }
    cout << count;
}
