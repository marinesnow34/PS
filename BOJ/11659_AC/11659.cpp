#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  vector<int> num(N+1);
  for(int i = 1; i<N+1;i++){
    scanf("%d", &num[i]);
    num[i]+=num[i-1];
  }
  while(M--){
    int start, end;
    scanf("%d %d", &start, &end);
    for(int i = 1; i<N+1;i++){
    }
    printf("%d\n", num[end] - num[start-1]);
  }
  
  return 0;
}