#include <iostream>
#include <vector>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int zero, one;
    scanf("%d %d", &zero, &one);

    vector<char> map(zero + one);
    getchar();
    for(int i = 0;i<zero+one;i++) scanf("%c", &map[i]);

    if(zero % 2 && one % 2){
      printf("-1\n");
      continue;
    }

    //홀수 가운데 값 확인
    if(map.size()%2){
      if(map[map.size()/2] == '1') one--;
      else if(map[map.size()/2] == '0') zero--;
    }

    //대칭 만들기
    for(int i = 0;i<map.size()/2;i++){
      if(map[i] == '0'){
        if(map[map.size()-i-1] == '0') zero -= 2;
        else if(map[map.size()-i-1] == '1') break;
        else if(map[map.size()-i-1] == '?'){
          map[map.size()-i-1] = '0';
          zero -= 2;
        }
      }
      else if(map[i] == '1'){
        if(map[map.size()-i-1] == '1') one -= 2;
        else if(map[map.size()-i-1] == '0') break;
        else if(map[map.size()-i-1] == '?'){
          map[map.size()-i-1] = '1';
          one -= 2;
        }
      }
      if(map[i] == '?'){
        if(map[map.size()-i-1] == '0') {
          map[i] = '0';
          zero -= 2;
        }
        else if(map[map.size()-i-1] == '1') {
          map[i] = '1';
          one -= 2;
        }
      }
    }
    // 홀수 중앙 ?채우기
    if(map.size()%2){
      if(map[map.size()/2] == '?'){
        if(zero%2){
          map[map.size()/2] = '0';
          zero--;
        }
        else{
          map[map.size()/2] = '1';
          one--;
        }
      }
    }
    //? 채우기
    for(int i = 0;i<map.size()/2;i++){
      if(map[i] == '?'){
        if(zero != 0){
          map[i] = '0', map[map.size()-i-1] = '0';
          zero -=2;
        }
        else if(one != 0){
          map[i] = '1', map[map.size()-i-1] = '1';
          one -=2;
        }
      }
    }
    
    if(zero != 0 || one != 0) printf("-1\n");
    else{
      for(int i =0;i<map.size();i++){
        printf("%c", map[i]);
      }
      printf("\n");
    }
  }

  return 0;
}