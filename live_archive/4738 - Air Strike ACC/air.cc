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

const double EPS = 1e-11;

int cmp(long double x, long double y = 0, long double tol = EPS){
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T> 
string toStr(const T &x)
  { stringstream s; s<<x; return s.str();}

template <class T> 
int toInt (const T &x)
  { stringstream s; s<<x; int r; s>>r; return r;}
int N;
const int MAX = 1005;
const long double PI = 3.141;
long double X[MAX], Y[MAX];
long double  x1,Y1, x2,y2, T;

bool cover(long double xi, long double yi, long double r2, long double r22)
{
  if((cmp(xi,x1) == 0 and cmp(yi,Y1) == 0) or (cmp(xi,x2) == 0 and cmp(yi,y2) == 0) ) return true;

  if(cmp( (xi-x1)*(xi-x1) + (yi-Y1)*(yi-Y1) , r2) <= 0) return true;
  if(cmp( (xi-x2)*(xi-x2) + (yi-y2)*(yi-y2) , r22) <= 0) return true;

  return false;
}

int min_missiles()
{
  int min_p = N;
  for(int i = 0; i<N; ++i)
  {
    long double r2 = (X[i]-x1)*(X[i]-x1) + (Y[i]-Y1)*(Y[i]-Y1);
    if(cmp(PI*r2,T)>0) continue;
    long double r22 = (T - r2*PI)/PI;
    int ans = 0;
    for(int j = 0; j<N;++j)
      if(!cover(X[j],Y[j],r2,r22))
      ++ans;
    min_p = min(ans,min_p);
  }
  for(int i = 0; i<N; ++i)
  {
    long double r22 = (X[i]-x2)*(X[i]-x2) + (Y[i]-y2)*(Y[i]-y2);
    if(cmp(PI*r22,T)>0) continue;
    long double r2 = (T - r22*PI)/PI;
    int ans = 0;
    for(int j = 0; j<N;++j)
      if(!cover(X[j],Y[j],r2,r22))
      ++ans;
    min_p = min(ans,min_p);
  }

  return min_p;
}

int main(){
  int C = 1;
  while(scanf("%d",&N) == 1 and N)
  {
    cin >> x1 >> Y1 >> x2 >> y2 >> T;
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    printf("%d. %d\n",C++, min_missiles());

  }

  return 0;
}
