#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  vector<vector<int> > map(n,vector<int>(n));

  //입력
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &map[i][j]);
    }
  }

  //거쳐가는 값
  for(int i = 0; i < n; i++){
    //출발
    for(int j = 0; j < n; j++){
      //도착
      for(int k = 0; k < n; k++){
        if(map[j][i] + map[i][k] == 2){
          map[j][k] = 1;
        }
      }
    }
  }

  //출력
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }

  return 0;
}