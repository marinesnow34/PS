#include <cstdio>
#include <vector>

using namespace std;

int main(){
  const int max=987654321;
  
  int n,m;
  scanf("%d %d", &n, &m);

  vector<vector<int> > map(n+1,vector<int>(n+1,max));
  vector<int> cost(n+1,max), visit(n+1);

  for(int i=0;i<m;i++){
    int start, end, far;
    scanf("%d %d %d", &start, &end, &far);
    // 중복 간선 있을 때 작은 값 으로
    if(map[start][end] > far) map[start][end] = far;
  }
  
  int departure, arrive;
  scanf("%d %d", &departure, &arrive);

  cost[departure] = 0;
  
  // 다익스트라
  for(int i=0;i<n;i++){

    int min_idx = 0, min_dis = max;

    // 방문하지 않은 거리가 최소인 노드 찾기
    for(int j=1;j<n+1;j++){

      if(visit[j] == 0 && cost[j] < min_dis){
        min_idx = j, min_dis = cost[j];
      }

    }

    visit[min_idx] = 1;

    // 찾은 노드로 부터 거리 갱신
    for(int j=1;j<n+1;j++){

      if(visit[j]) continue;

      if(cost[j] > map[min_idx][j] + cost[min_idx]) cost[j] = map[min_idx][j] + cost[min_idx];
    }

  }

  printf("%d", cost[arrive]);

  return 0;
}