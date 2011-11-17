// Complete search

// The idea is to loop through all the possible combinations
// of tracks. Using a bitmask we can easily know which tracks we are using.
// If there are at most 20 tracks in the CD, there are at most 2^20 combinations
// to look into. Which, easily fits into an integer.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

#define D(x) cout << #x " is " << x << endl

// N is the length of the CD
// T is the number of tracks (at most 20)
int N, T, songs[20], dp[21][1<<20];
bool picked[21][1<<20];

int f(int index, int remT, bool chosen){
  if(dp[index][remT] != -1) return dp[index][remT];
  if(index == T) return dp[index][remT] = remT;
  if(remT == 0) return dp[index][remT] = 0;
  int la_cojo = 1 << 30;
  if(remT - songs[index] >= 0){
    la_cojo = f(index + 1, remT - songs[index], true);
  }
  int no_la_cojo = f(index + 1, remT, false);
  if(la_cojo < no_la_cojo){
    picked[index][remT] = true;
  }else{
    picked[index][remT] = false;
  }
  return dp[index][remT] = min(la_cojo, no_la_cojo);
}

void bt(int index, int remT, bool first = false){
  // printf("bt with %d %d\n", index, remT);
  if(!first){
    printf("%d ", songs[index]);
  }
  for(int i=index + 1;i<=T; ++i){
    int new_rem = remT - songs[index];
    if(picked[i][new_rem]){
      return bt(i, new_rem);
    }
  }
}

int main(){
  while(scanf("%d", &N) == 1){
    scanf("%d", &T);
    for(int i=0;i<T;++i){ scanf("%d", &songs[i]); }
    for(int i=0;i<=T;++i) for(int j = 0; j <= N;++j) {dp[i][j] = -1; picked[i][j] = false;}
    int res = f(0, N, true);
    
    // for(int i=0;i<=T;++i){
    //   for(int j=0;j<=N;++j){
    //     printf("%d ", picked[i][j]);
    //   }
    //   puts("");
    // }
    
    bt(-1, N, true);
    
    
    printf("sum:%d\n", N-res);
    // puts("*****\n");
  }
  return 0;
}