#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
  const int INF = 987654321;
  int n, m, x, go, come;
  scanf("%d %d %d", &n, &m, &x);
  vector<vector<pair<int,int> > > map(n+1), map_come(n+1);
  vector<int> dist_go(n+1,INF), dist_come(n+1,INF);;
  for(int i = 0; i < m; i++){
    int start, end, far;
    scanf("%d %d %d", &start, &end, &far);
    map[start].push_back(pair<int, int> (end,far));
    map_come[end].push_back(pair<int, int> (start,far));
  }

  // x에서 출발
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  pq.push(pair<int,int>(0,x));
  dist_go[x]=0;

  // 다익스트라
  while(!pq.empty()){
    int city = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    for(int i = 0; i < map[city].size(); i++){
      int next_city = map[city][i].first;
      int next_cost = map[city][i].second;
      if(cost + next_cost < dist_go[next_city]){
        dist_go[next_city] = cost + next_cost;
        pq.push(pair<int, int> (dist_go[next_city], next_city));
      }
    }
  }

  // x로 돌아오기
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq_come;
  pq_come.push(pair<int,int>(0,x));
  dist_come[x]=0;

  // 다익스트라
  while(!pq_come.empty()){
    int city = pq_come.top().second;
    int cost = pq_come.top().first;
    pq_come.pop();

    for(int i = 0; i < map_come[city].size(); i++){
      int next_city = map_come[city][i].first;
      int next_cost = map_come[city][i].second;
      if(cost + next_cost < dist_come[next_city]){
        dist_come[next_city] = cost + next_cost;
        pq_come.push(pair<int, int> (dist_come[next_city], next_city));
      }
    }
  }

  // 최대시간 구하기
  int max_dist = 0;
  for(int i=1;i<n+1;i++){
    if(max_dist < dist_come[i] + dist_go[i]) max_dist = dist_come[i] + dist_go[i];
  }

  printf("%d",max_dist);

  return 0;
}