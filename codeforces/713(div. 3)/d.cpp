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

    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
      sum1+= map[i];
    }
    sum2 += map[n] - map[0];
    printf("%d %d\n", sum1,sum2);
  }
  return 0;
}