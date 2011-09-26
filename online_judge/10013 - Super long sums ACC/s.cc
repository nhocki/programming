/**
* Nicolás Hock Isaza
* Name: s.cc
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

int main()
{
  int m[1000002],N,M;
  scanf("%d",&N);
  while(N--)
  {
    scanf("%d",&M);
    mem(m,0);
    for(int i=M-1;i>=0;--i)
    {
      int a,b;
      bool k;
      scanf("%d%d",&a,&b);
      k=((a+b)>9);
      m[i]=(a+b)%10;
      m[i+1]+=k;
    }
    for(int i=M-1;i>=0;--i) printf("%d",m[i]);
    puts("\n"); //imprime una linea más al final.
  }
  return 0;
}
