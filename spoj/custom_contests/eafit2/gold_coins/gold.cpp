#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> dp;

ll f(ll i){  
  if( i == 0 ) return dp[i] = 0;
  if(dp[i] != 0) return dp[i];
  dp[i] = max(i, f(i/2) + f(i/3) + f(i/4));
  //printf("f(%lld) = %lld\n", i, dp[i]);
  return dp[i];
}

int main(){
  ll n;
  //fill(dp, dp + 1000000002, 0);
  //memset(dp, 0, sizeof(dp));
  while(scanf("%lld", &n)!=EOF){
    printf("%lld\n", f(n));
  }

  return 0;
}



#include <cstdio>
#include <map>

using namespace std;

typedef long long num;

map<num, num> profit;
num maxProfit(num n){
  if(n==0)return 0;
  num p = profit[n];
  if(p == 0){
    num tmp = maxProfit(n/2)+maxProfit(n/3)+maxProfit(n/4);
    p = (tmp < n)?n:tmp;
    profit[n] = p;
  }
  return p;
}

int main(){
  num n;
  while(scanf("%lld", &n)!=EOF){
    printf("%lld\n",maxProfit(n));
  }
  
  return 0;
}
