#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <iterator>
#include <sstream>
#include <fstream>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define D(x) cout << #x" is " << x << endl

#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!=(v).end; ++x)
#define For(i,a,b) for(int i=(a); i<(b); ++i)
#define mem(x,a) memset(x,a,sizeof(x))

const double EPS = 1e-9;

int cmp(double x, double y = 0, double tol = EPS){
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T> 
string toStr(const T &x)
  { stringstream s; s<<x; return s.str();}

template <class T> 
int toInt (const T &x)
  { stringstream s; s<<x; int r; s>>r; return r;}

#define SIZE 1000002

bool criba[SIZE];
set<int> ps;
vector<int> primes;

void crib(){
  memset(criba,true,sizeof(criba));
  criba[0]=criba[1] = false;
  primes.push_back(2);
  for(int i=4;i<SIZE; i+=2) criba[i]=false;
  for(unsigned long long i=3;i<SIZE;i+=2){
    if(criba[i]){
      primes.push_back(i);
      //	    D(i);
      for(unsigned long long j=i*i; j<SIZE; j+=i){
        criba[j]=false;
      }
    }
  }
}

map<int,int> prime_map (int N){
  map<int,int> ans;
  if (criba[N]){
    ans[N]++;
    ps.insert(N);
    return ans;
  }

  int SZ = primes.size();
  for(int k=0;k<SZ && primes[k] <= N; ++k){
    int i = primes[k];
    while (N % i == 0){
      N /= i;
      ans[i]++;
      ps.insert(i);
    }
  }
  assert(N == 1);
  return ans;
}

int main(){
  crib();
  int A,B;
  int C = 1;
  while(scanf("%d%d",&A,&B)==2 && (A+B)){
    ps.clear();
    map<int,int> mA = prime_map(A);
    map<int,int> mB = prime_map(B);
    int dif = 0;
    for(set<int>::iterator k = ps.begin(); k!=ps.end();++k){
      int i = *(k);
      //D(i);
      //D((abs(mA[i] - mB[i])));
      dif+=(abs(mA[i] - mB[i]));
    }
    printf("%d. %d:%d\n",C++,ps.size(), dif);
  }
  return 0;
}
