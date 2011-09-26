/**
* Nicolás Hock Isaza
* Name: 572.cc
* Created On: 23 Apr 2009
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

int N,M;
char m[102][102];

int xs[8] = {-1,0,1,-1,1,-1,0,1};
int xy[8] = {-1,-1,-1,0,0,1,1,1};

int total = 0;

void BT(int x, int y){
  total+=(m[x][y]=='@');
  m[x][y]='*';
  for(int i=0;i<8;++i)
  {
    int n_x = x+xs[i], n_y=y+xy[i];
    if(m[n_x][n_y]=='@') total--, BT(n_x,n_y);
  }
}

int main()
{
  while(scanf("%d%d",&M,&N)==2 && M)
  {
    string line;
    mem(m,'*');
    getline(cin,line);
    for(int i=1;i<=M;++i)
      for(int j=1;j<=N;++j)
      cin>>m[i][j];

    for(int i=1;i<=M;++i)
      for(int j=1;j<=N;++j)
      if(m[i][j]=='@') BT(i,j);

    printf("%d\n",total);
    total = 0;
  }
  return 0;
}
