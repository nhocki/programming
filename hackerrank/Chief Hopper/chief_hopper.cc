#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100050
#define D(x) cout << #x " is " << x << endl

long long oo = 100050;
long long N;
long long h[MAXN];

bool can(long long energy) {
  for(long long i = 1; i <= N; ++i){
    energy -= (h[i] - energy);
    if(energy > oo || energy < 0) { break; }
  }
  return energy >= 0;
}

long long bsearch(long long min, long long max){
  long long mid = min + (max - min) / 2;

  while(min < max){
    mid = min + ((max - min) / 2);

    if(can(mid)) max = mid;
    else min = mid + 1;
  }
  return min;
}

int main() {
  cin >> N;
  h[0] = 0; // always!

  for(long long i=1;i <= N;++i) cin >> h[i];
  cout << bsearch(0, oo) << endl;
  return 0;
}
