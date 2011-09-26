/**
* Nicolás Hock Isaza
* Name: 10229.cc
* Created On: 19 Mar 2009
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


using namespace std;

typedef unsigned long long uulong;

uulong fib(int n)
{
  uulong i=1,j=0,k=0,h=1,t=0;
  while(n>0)
  {
    if (n%2==1)
    {
      t=j*h;
      j=i*h + j*k + t;
      i = i*k + t;
    }
    t = h*h;
    h = 2*k*h + t;
    k = k*k + t;
    n = floor(n/2);
  }
  return j;
}

int main()
{
  int N,M;
  while(scanf("%d%d",&N,&M)==2)
  {
    uulong fN = fib(N);
    uulong res = fN % (uulong)pow(2,(double)M);
    printf("%llu\n",res);
  }
  return 0;
}
