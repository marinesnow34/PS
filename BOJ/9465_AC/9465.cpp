#include <iostream>
#include <vector>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    vector<vector<int> > sticker(2, vector <int>(n));

    for(int i = 0 ; i < 2; i++){
      for(int j = 0; j < n; j++){
        scanf("%d", &sticker[i][j]);
      }
    }

    if(n > 1){
      sticker[0][1] += sticker[1][0];
      sticker[1][1] += sticker[0][0];
    }

    for(int i = 2; i < n; i++){
          if(sticker[1][i-1] < sticker[1][i-2]) sticker[0][i] += sticker[1][i-2];
          else sticker[0][i] += sticker[1][i-1];

          if(sticker[0][i-1] < sticker[0][i-2]) sticker[1][i] += sticker[0][i-2];
          else sticker[1][i] += sticker[0][i-1];
    }

    printf("%d\n", sticker[0][n-1] > sticker[1][n-1] ? sticker[0][n-1] : sticker[1][n-1]);
  }
  return 0;
}