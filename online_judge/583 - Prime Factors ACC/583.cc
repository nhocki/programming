/**
* Nicolás Hock Isaza
* Name: 583.cc
* Created On: 08 Apr 2009
*/

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

#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl
#define D_v(x) for(int i=0;i<x.size();cerr<<x[i++]<<" ")
#define D_m(m,rows,cols) for(int _i_=0;_i_<rows;cout<<endl,++_i_) for(int _j_=0;_j_<cols;) cout <<m[i][_j_++]<<"  "
#define mem(i,n) memset(i,n,sizeof(i))
#define For(i,a) for(typeof(a) i=0;i<a;++i)
#define For2(i,a,b) for(typeof(a) i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define sz size()
#define lng length()
#define cs c_str()

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

//sqrt(2^31)=46340
#define _max 46342 

int prim[_max];
vector<int> primes;

int criba()
{
  memset(prim,1,sizeof(prim));
  primes.pb(2);
  prim[0]=prim[1]=false;
  for(int i=4;i<_max;i+=2) prim[i]=false;
  for(int i=3;i<_max;i+=2)
    if(prim[i])
  {
    primes.pb(i);
    for(int j=i*i;j<_max;j+=i)
      prim[j]=false;
  }
}

int main()
{
  criba();
  int n;
  while(scanf("%d",&n)==1 && n)
  {
    printf("%d = ",n);
    if(n<0) printf("-1 x "), n=-n;
    for(int i = 0;i<primes.size() && n>1;++i)
    {
      while(n%primes[i]==0)
      {
        n/=primes[i];
        if(n>1) printf("%d x ",primes[i]);
        else printf("%d\n", primes[i]);
      }
    }
    if(n>1) printf("%d\n", n);
  }
  return 0;
}
