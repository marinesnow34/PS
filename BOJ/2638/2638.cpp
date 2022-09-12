#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int> > map(n, vector<int> (m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &map[i][j]);
    }
  }

  int tmp = 1, x, y;

  while(true){
    int judge=0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(map[i][j] == tmp){
          judge = 1;
          x = i;
          y = j;
          break;
        }
      }
    }

    if(!judge) break;
    while()
    

    tmp++;
  }

  return 0;
}