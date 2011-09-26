/**
* Nicolás Hock Isaza
* Name: 10189.cc
* Created On: 03 Apr 2009
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

char m[103][103], r[103][103];

int main()
{
  int N,M,caso=1;
  while(scanf("%d%d",&N,&M)==2 && (M+N))
  {
    if(caso!=1)puts("");
    mem(m,46) , mem(r,48);
    For2(i,1,N+1) For2(j,1,M+1)	cin>>m[i][j];
    For2(i,1,N+1) For2(j,1,M+1)
    {
      if(m[i][j]!='*')
      {
        r[i][j]+=(m[i-1][j-1]=='*');
        r[i][j]+=(m[i-1][j]=='*');
        r[i][j]+=(m[i-1][j+1]=='*');
        r[i][j]+=(m[i][j+1]=='*');
        r[i][j]+=(m[i+1][j+1]=='*');
        r[i][j]+=(m[i+1][j]=='*');
        r[i][j]+=(m[i+1][j-1]=='*');
        r[i][j]+=(m[i][j-1]=='*');
      }
      else r[i][j]='*';
    }
    printf("Field #%d:\n",caso++);
    for(int i=1;i<=N;++i)
    {
      for(int j=1;j<=M;++j) cout<<r[i][j];
      puts("");
    }
  }
  return 0;
}
