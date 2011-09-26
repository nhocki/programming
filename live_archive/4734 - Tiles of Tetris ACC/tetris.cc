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

#define foreach(x,v) for(typeof (v).begin() x = (v).begin() ; x!= (v).end; ++x)
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

int main(){
  long long W, H;
  int C = 1;
  while(cin >> W >> H){
    if (W == 0 and H == 0) break;
    long long g = __gcd(W, H);
    long long lcm = W / g * H;
    long long res = (lcm / W) * (lcm / H);
    printf("%Ld\n", res);
  }
  return 0;
}
