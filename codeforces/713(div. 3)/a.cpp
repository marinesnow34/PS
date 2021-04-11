#include <iostream>
#include <vector>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    vector<int> map(n);
    for(int i=0;i<n;i++){
      scanf("%d", &map[i]);
    }

    int normal = map[0];

    if(map[0] != map[1]){
      if(map[0] != map[2]) printf("1\n");
      else printf("2\n");
      continue;
    }

    for(int i = 2; i <n;i++){
      if(map[i] != normal){
        printf("%d\n", i+1);
        break;
      }
    }
  }
  return 0;
}