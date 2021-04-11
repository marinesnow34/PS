#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    vector<int> map(n+2);
    for(int i =0;i<n+2;i++){
      scanf("%d",&map[i]);
    }
    sort(map.begin(),map.end());

    long long sum1=0,sum2=0;
    for(int i=0;i<n;i++){
      sum1+= map[i];
    }
    if(sum1 == map[n] || sum1 == map[n+1]){
      for(int i =0; i<n;i++){
        printf("%d ", map[i]);
      }
      printf("\n");
    }
    else{
      int jud=0;
      for(int i = 0;i<n;i++){
        sum2 = sum1 - map[i] + map[n];
        if(sum2 == map[n+1]){
          for(int j =0; j<n+1;j++){
            if(i==j) continue;
            printf("%d ", map[j]);
          }
          printf("\n");
          jud = 1;
          break;
        }
      }
      if(jud == 0){
        printf("-1\n");
      }
    }
  }
  return 0;
}