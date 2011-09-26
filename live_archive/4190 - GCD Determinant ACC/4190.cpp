#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

const int _SIZE = 1000000;
const int MOD   = 1000000007;

bool primes[_SIZE];

void buildCrib(){
  memset(primes,true, sizeof(primes));
  primes[0] = false;
  primes[1] = false;
  for(long long i = 4; i < _SIZE; i += 2) primes[i] = false;
  for(long long i = 3; i*i < _SIZE; i += 2)
    if(primes[i])
      for(long long j = i*i; j < _SIZE; j += i)primes[j] = false;
}

long long phi(long long n){ 
  if(n<_SIZE && primes[n]) return n-1;
  long long result = n;
  for(long long i=2;i*i <= n;i++){
    if (n % i == 0) result -= result / i;
    while (n % i == 0) n /= i;
  }
  if (n > 1) result -= result / n;
  return result;
} 

int main(){
  int N;
  buildCrib();
  while(scanf("%d", &N)==1){
    long long res = 1;
    int tmp;
    for(int i=0;i<N;++i){
      scanf("%d", &tmp);
      res = (res * phi(tmp)) % MOD;
    }
    cout << res << endl;
  }
  return 0;
}
