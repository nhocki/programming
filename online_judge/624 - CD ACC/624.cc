// Complete search

// The idea is to loop through all the possible combinations
// of tracks. Using a bitmask we can easily know which tracks we are using.
// If there are at most 20 tracks in the CD, there are at most 2^20 combinations
// to look into. Which, easily fits into an integer.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define D(x) cout << #x " is " << x << endl

int main(){
  // N is the length of the CD
  // T is the number of tracks (at most 20)
  int N, T, songs[20];
  while(scanf("%d", &N) == 1){
    scanf("%d", &T);

    // Best will hold the sum of the best combination so far
    // Combo will hold the best combination so far
    // Max is the maximal number to look into (2^T)
    int best = 0, max = (1<<T), combo = 0;
    for(int i=0;i<T;++i){
      scanf("%d", &songs[i]);
    }

    // Here is where we look into all the possible combinations.
    for(int i=0; i < max; ++i){
      int current = 0;
      // The second loop is to actually get the songs we're trying in this
      // combination. This loop will be at most 20!
      for(int j = 0; (1<<j) <= i; ++j)
        if((1<<j) & i)
          current += songs[j];

      // After we've added all the songs in that combination, we can check
      // if this is a better one.
      if(current > best && current <= N){
        combo = i;
        best = current;
      }
    }

    // Get all the `1` bits and print the song!
    for(int i=0; (1<<i) <= combo; ++i){
      if((1<<i) & combo){
        printf("%d ", songs[i]);
      }
    }
    printf("sum:%d\n", best);
  }
  return 0;
}