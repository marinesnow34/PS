#include <iostream>
#include <vector>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n, c = 0;
    scanf("%d",&n);
    vector<vector<char> > map(n,vector<char>(n));
    pair<int, int> a, b;

    for(int i =0;i<n;i++){
      getchar();
      for(int j =0;j<n;j++){
        scanf("%c", &map[i][j]);
        if(map[i][j] == '*' && c == 0) a.first = i, a.second = j, c = 1;
        if(map[i][j] == '*' && c == 1) b.first = i, b.second = j;
      }
    }

    if(a.first == b.first){
      if(a.first){
        map[0][a.second] = '*';
        map[0][b.second] = '*';
      }
      else{
        map[1][a.second] = '*';
        map[1][b.second] = '*';
      }
    }
    else if(a.second == b.second){
      if(a.second){
        map[a.first][0] = '*';
        map[b.first][0] = '*';
      }
      else{
        map[a.first][1] = '*';
        map[b.first][1] = '*';
      }
    }
    else{
      map[a.first][b.second] = '*';
      map[b.first][a.second] = '*';
    }
    for(int i =0;i<n;i++){
      for(int j =0;j<n;j++){
        printf("%c", map[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}