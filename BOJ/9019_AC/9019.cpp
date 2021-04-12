#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int D(int num){
  return (num * 2) % 10000;
}
int S(int num){
  if(num == 0) return 9999;
  return num - 1;
}
int L(int num){
  return (num * 10) % 10000 + int(num / 1000);
}
int R(int num){
  return int(num / 10) + (num % 10) * 1000;
}

int main(){
  int T;
  scanf("%d" ,&T);
  while(T--){
    int A, B;
    scanf("%d %d", &A, &B);

    string dslr;
    vector<int> visit(10000);
    queue<pair<int,string> > q;
    q.push(pair<int,string>(A, ""));

    while(!q.empty()){
      int num = q.front().first;
      dslr = q.front().second;
      q.pop();
      if(num == B) break;
      if(visit[D(num)] == 0){
        q.push(pair<int,string>(D(num), dslr + "D"));
        visit[D(num)] = 1;
      }
      if(visit[S(num)] == 0){
        q.push(pair<int,string>(S(num), dslr + "S"));
        visit[S(num)] = 1;
      }
      if(visit[L(num)] == 0){
        q.push(pair<int,string>(L(num), dslr + "L"));
        visit[L(num)] = 1;
      }
      if(visit[R(num)] == 0){
        q.push(pair<int,string>(R(num), dslr + "R"));
        visit[R(num)] = 1;
      }      
    }
    
    printf("%s\n", dslr.c_str());
  }
  return 0;
}