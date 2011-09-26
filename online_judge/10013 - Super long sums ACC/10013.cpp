/**
* Nicolás Hock Isaza
* Name: 10013.cc
* Created On: 26 Mar 2009
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

#define mem(i,n) memset(i,n,sizeof(i))
#define pb(x) push_back(x)
#define sz size()
#define cs c_str()

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

string sum(string &a,string &b)
{
  bool carry = 0;
  string res=a;
  for(int i=a.sz-1;i>=0;--i)
  {
    res[i]=((a[i]+b[i]-96+carry)%10)+48;
    carry=((a[i]+b[i]+carry-96)>9);
  }
  return res;
}

int main()
{
  int N,M;
  scanf("%d",&N);
  while(N--)
  {
    scanf("%d",&M);
    string a,b;
    for(int i=0,f,s;i<M && scanf("%d%d",&f,&s)==2;a.pb(f+48),b.pb(s+48),++i);
    a = sum(a,b);
    printf("%s%s",a.cs,N>0?"\n\n":"\n");
  }
  return 0;
}
