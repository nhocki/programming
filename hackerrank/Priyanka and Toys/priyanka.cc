#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10005
int toys[MAXN];

int main() {
  int N;
  scanf("%d", &N);
  for(int i=0;i<N;++i){
    scanf("%d", &toys[i]);
  }
  sort(toys, toys + N);

  int res = 0;
  int curr_weight = -100;
  for(int i = 0; i < N; ++i){
    if(curr_weight + 4 < toys[i]){
      res++;
      curr_weight = toys[i];
    }
  }
  printf("%d\n", res);
  return 0;
}
