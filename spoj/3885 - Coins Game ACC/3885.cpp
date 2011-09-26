#include <cstdio>

#define L 0
#define W 1
#define MAXN 1000002
int c[3] = {1,0,0};
bool dp[MAXN];

// dp[i] is true if the first player wins when there are i coins left

// Explanation: Suppose that you can take {1,3,4} coins.
// Then, you know that if there's 1 coin left. You've already won. The same with 3 or 4 coins.
// This positions are "Winning positions"
// Now, if there are 2 coins left, I'll always loose because I can only take 1 coin
// leaving 1 coin in the stack and the other player will take it and win.
// So, for this case, dp[2] = false. And this is a "Loosing position".
//
// Now, let's think of the state i. You'll always win if you take k coins such that 
// the other player will always loose with i-k coins (in other words, if you'll leave
// the stack with a loosing amount of coins). If you can't do this, you'll loose!
// So, just try to take a coin such that dp[i-k] is a loosing position

int main(){
  int m;
  scanf("%d%d%d", &c[1], &c[2], &m);
  for(int i=0;i<MAXN;++i){
    dp[i] = L;
    for(int j = 0; j<3;++j){
      if(i - c[j] >= 0){
        if(dp[i - c[j] ] == L) {dp[i] = W; break;}
      }
    }
  }
  while(m--){
    int n;
    scanf("%d",&n);
    if(dp[n]) printf("A");
    else printf("B");
  }
  return 0;
}
