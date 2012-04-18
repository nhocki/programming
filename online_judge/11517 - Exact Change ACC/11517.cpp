#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

int main(){
  int T, oo = 1<<30;
  scanf("%d", &T);
  while(T--){
    int price, n;
    scanf("%d%d", &price, &n);
    vector<int>c(n), dp(30011, oo);
    for(int i=0;i<n;++i) scanf("%d", &c[i]);

    dp[0] = 0;
    for(int i = 0;i<n;++i)
      for(int j = 30000; j>=0; --j)
        if(dp[j] != oo && j + c[i] < 30000)
          dp[j + c[i]] = min(dp[j] + 1, dp[j + c[i]]);


    for(int i = price; i<30000; ++i)
      if(dp[i] != oo){
        printf("%d %d\n", i, dp[i]);
        break;
      }

  }
  return 0;
}
