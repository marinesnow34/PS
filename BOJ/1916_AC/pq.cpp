#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
  const int INF = 987654321;
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> dist(n+1, INF);
  vector<vector<pair<int,int> > > map(n+1);

  for(int i=0;i<m;i++){
    int start, end, far;
    scanf("%d %d %d", &start, &end, &far);
    map[start].push_back(pair<int, int> (end, far));
  }

  int departure, arrive;
  scanf("%d %d", &departure, &arrive);

  // 우선순위 큐 선언 후 출발지 넣기
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  pq.push(pair<int,int>(0,departure));
  dist[departure] = 0;

  // 다익스트라
  while(pq.size()){
    int city = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    for(int i = 0; i < map[city].size();i++){
      int next_city = map[city][i].first;
      int next_cost = map[city][i].second;
      if(cost + next_cost < dist[next_city]){
        dist[next_city] = cost + next_cost;
        pq.push(pair<int,int>(dist[next_city], next_city));
      }
    }
  }

  printf("%d", dist[arrive]);
  return 0;
}