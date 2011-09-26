#include <cstdio>
#include <string>

const int MAX = 7490;

int coins[] = {1,5,10,25,50};
int dp[MAX+1]; // dp[i] = how many ways to form i

int main(){
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2;i<MAX;++i){
    dp[i] = 0;
    for(int j = 0; j<5; ++j){
      int value = coins[j];
      if(i - value >= 0){
        if(dp[i] < dp[i-value])
          dp[i] = dp[i-value];
      }
    }
  }

  int n;
  while(scanf("%d", &n) == 1) printf("%d\n", dp[n]);
  return 0;
}
