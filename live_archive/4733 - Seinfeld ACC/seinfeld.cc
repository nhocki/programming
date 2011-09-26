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

const int MAXN = 2005;

int dp[MAXN][MAXN];
const int oo = INT_MAX / 2 - 1;

void minimize(int &x, int y){
  if (y < x) x = y;
}

int solve(const string &s){
  int n = s.size();
  for (int j = 0; j < MAXN; ++j) dp[0][j] = oo;
  dp[0][1] = (s[0] == '}');

  for (int i = 1; i < n; ++i){
    for (int j = 0; j < MAXN; ++j) dp[i][j] = oo;
    for (int j = 0; j < n; ++j){
      if (s[i] == '{'){
        if (j - 1 >= 0) minimize(dp[i][j], dp[i-1][j-1]);
        minimize(dp[i][j], dp[i-1][j+1] + 1);
      }else{
        minimize(dp[i][j], dp[i-1][j+1]);
        if (j - 1 >= 0) minimize(dp[i][j], dp[i-1][j-1] + 1);
      }
    }
  }
  return dp[n-1][0];
}

int main(){
  string line;
  int C = 1;
  while(cin >> line && line[0]!='-'){
    int res = solve(line);
    printf("%d. %d\n",C++,res);
  }
  return 0;
}
