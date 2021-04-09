#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int N,M,X,result,max=100001;
  scanf("%d %d %d", &N, &M, &X);
  vector<vector<int> > go(N+1,vector<int>(N+1,max)), come(N+1,vector<int>(N+1,max));
  vector<int> go_visit(N+1, 1), come_visit(N+1, 1), go_dist(N+1,max), come_dist(N+1,max);
  
  for(int i=0;i<M;i++){
    int start, end, length;
    scanf("%d %d %d", &start, &end, &length);
    go[start][end] = length, come[end][start] = length;
    if(start == X){
      go_dist[end] = length;
    }
    if(end == X){
      come_dist[start] = length;
    }
  }
  

  go_dist[X]=0, go_visit[X] = 0;
  for(int i=0;i<N-1;i++){
    int min_dist = max, min_idx=X;
    // 이동할 정점 찾기
    for(int j=1;j<N+1;j++){
      if(!go_visit[j]) continue;
      if(go_dist[j] < min_dist) min_dist=go_dist[j], min_idx=j;
    }

    go_visit[min_idx]=0;

    // 해당 정점으로 부터 시간 업데이트
    for(int j=1;j<N+1;j++){
      if(!go_visit[j]) continue;
      if(go_dist[j] > go[min_idx][j] + go_dist[min_idx]) go_dist[j] = go[min_idx][j] + go_dist[min_idx];
    }
  }

  come_dist[X]=0, come_visit[X] = 0;
  for(int i=0;i<N-1;i++){
    int min_dist = max, min_idx=X;
    // 이동할 정점 찾기
    for(int j=1;j<N+1;j++){
      if(!come_visit[j]) continue;
      if(come_dist[j] < min_dist) min_dist=come_dist[j], min_idx=j;
    }

    come_visit[min_idx]=0;

    // 해당 정점으로 부터 시간 업데이트
    for(int j=1;j<N+1;j++){
      if(!come_visit[j]) continue;
      if(come_dist[j] > come[min_idx][j] + come_dist[min_idx]) come_dist[j] = come[min_idx][j] + come_dist[min_idx];
    }
  }

  //최장 시간 찾기
  for(int i=1;i<N+1;i++){
    if(result < come_dist[i] + go_dist[i]) result = come_dist[i] + go_dist[i];
  }

  printf("%d", result);
  return 0;
}