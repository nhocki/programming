#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define D(x) cout << #x " is " << x << endl

using namespace std;

int N = 11;
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long memo[13][30010];

long long count(int coin, int value){
  if(value == 0)              return 1;
  if(value <  0 || coin >= N) return 0;
  if(memo[coin][value] != -1) return memo[coin][value];
  return memo[coin][value] = count(coin, value - coins[coin]) + count(coin + 1, value);
}

int main(){
  double amount;
  memset(memo, -1, sizeof(memo));
  while(scanf("%lf", &amount) == 1 && amount != 0.0){
    long long ways = count(0, (int)((amount * 100) + 1e-5));
    printf("%6.2lf%17lld\n", amount, ways);
  }
  return 0;
}
