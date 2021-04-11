#include <iostream>
#include <queue>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  priority_queue<pair<double,int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

  while(N--){
    int x;
    scanf("%d", &x);
    
    if(x == 0){
      if(pq.empty()) printf("0\n");
      else{
        printf("%d\n", (int)pq.top().first * pq.top().second);
        pq.pop();
      }
    }
    else{
      if(x > 0){
        // 양수와 음수의 절댓값 비교 때 음수가 더 작기 위해 양수 + 0.5
        pq.push(pair<double, int> (x + 0.5,1));
      }
      else{
        // 음수를 표시하기 위해 second에 -1
        pq.push(pair<double,int>(x * (-1), -1));
      }
    }
  }
  return 0;
}