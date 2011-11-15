#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define D(x) cout << #x " is " << x << endl

int main(){
  int N, n, k;
  scanf("%d", &N);
  while(N--){
    scanf("%d%d", &n, &k);
    if(n >= k){
      // 1) x + y = n
      // 2) x - y = k
      //
      // -> 3) x = k + y (from 2)
      // -> 4) y = (n - k) / 2  (from 3 in 1)

      // `y` has to be an integer or the input is not valid
      double y = (n - k) / 2.0;
      double x = k + y;
      if( y != floor(y)){
        puts("impossible");
      }else{
        printf("%d %d\n", (int)floor(x), (int)floor(y));
      }
    }else{
      puts("impossible");
    }
  }
  return 0;
}