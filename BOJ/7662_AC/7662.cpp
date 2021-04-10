#include <iostream>
#include <set>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int Q;
    scanf("%d", &Q);

    multiset<int> ms;

    while(Q--){
      char D;
      int n;

      getchar();
      scanf("%c %d", &D, &n);

      //삽입
      if(D == 'I'){
        ms.insert(n);
      }
      //비어 있을 때 삭제 불가
      else if(ms.empty()) continue;
      // 최대 삭제
      else if(n == 1){
        ms.erase(--ms.end());
      }
      // 최소 삭제
      else if(n == -1){
        ms.erase(ms.begin());
      }
    }

    if(ms.size() == 0) printf("EMPTY\n");
    else{
      printf("%d %d\n", *(--ms.end()), *ms.begin());
    }

  }
  return 0;
}