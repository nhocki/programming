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
  int C = 1;
  long long n0;
  while (cin >> n0){
    if (n0 == 0) break;
    printf("%d. ", C++);

    long long n1 = 3 * n0;

    printf("%s ", n1 % 2 == 0 ? "even" : "odd");

    long long n2 = (n1 + 1) / 2;
    long long n3 = 3 * n2;
    long long n4 = n3 / 9;
    cout << n4 << endl;

  }
  return 0;
}
