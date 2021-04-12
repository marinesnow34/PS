#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  vector<int> board(101), dist(101);

  for(int i=0;i<N+M;i++){
    int base, go;
    scanf("%d %d", &base, &go);
    board[base]=go;
  }

  queue<int> q;
  q.push(1);

  //bfs
  while(!q.empty()){
    int now;
    now = q.front();
    q.pop();

    if(now == 100) break;

    for(int i = 1;i<7;i++){
      int next = now + i;
      if(next > 100) break;
      if(board[next] != 0) next = board[next];
      if(dist[next] == 0){
        q.push(next);
        dist[next] = dist[now] + 1;
      }
    }
  }

  printf("%d", dist[100]);
  return 0;
}