#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <cassert>

#define D(x) cout << #x" is " << x <<endl;
#define all(x) x.begin(),x.end()
using namespace std;

const int MAXD = 1000005;
int h[MAXD];

int main(){
  int C;
  scanf("%d", &C);
  while(C--){
    int d, n;
    scanf("%d %d", &d, &n);

    for (int i = 0; i < d; ++i) h[i] = 0;
    h[0] = 1;

    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++){
      int x; scanf("%d", &x);
      sum += (long long)x;
      ans += h[sum % d];
      h[sum % d]++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
