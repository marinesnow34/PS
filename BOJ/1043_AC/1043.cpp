#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> truth(n + 1), judge, stack;
  vector<vector<int> > meet(n + 1);

  int tmp;
  scanf("%d", &tmp);

  for(int i = 0; i < tmp; i++){
    int person;
    scanf("%d", &person);
    truth[person] = 1;
    stack.push_back(person);
  }

  for(int i = 0; i < m; i++){
    int headcount, link = 0;
    scanf("%d", &headcount);
    for(int j = 0; j < headcount; j++){
      int member;
      scanf("%d", &member);
      if(j == 0) judge.push_back(member);
      meet[member].push_back(link);
      meet[link].push_back(member);
      link = member;
    }
  }

  while(!stack.empty()){
    int tmp = stack.back();
    stack.pop_back();

    for(int i = 0; i < meet[tmp].size(); i++){
      if(meet[tmp][i] != 0){
        if(truth[meet[tmp][i]] != 1){
          truth[meet[tmp][i]] = 1;
          stack.push_back(meet[tmp][i]);
        }
      }
    }
  }

  int result = 0;
  for(int i = 0; i < judge.size(); i++){
    if(truth[judge[i]] != 1) result++;
  }

  printf("%d", result);

  return 0;
}