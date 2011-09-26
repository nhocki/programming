/**
* Nicolás Hock Isaza
* Name: 108.cc
* Created On: 12 Apr 2009
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
  int N;
  int t=0;
  int a[102][102]; //Matriz
  vector<int>pr(102,0);
    //    int pr[102]; //Arreglo auxiliar

  int S = 1<<31, s=0, k,l,x1=0,x2=0,y1=0,y2=0,j;
  cin >> N;
  for(int i=0;i<N;++i)
    for(j=0;j<N;++j)
    cin>>a[i][j];

    //     for(int i=0;i<N;++i,puts(""))
    // 	for(j=0;j<N;++j)
    // 	    cout<<a[i][j]<<"   ";

  for(int z=0;z < N;++z)
  {
      //memset(pr,0,sizeof(pr));
    pr = vector<int>(102,0);
    for(int x=z;x<N;++x)
    {
      t=0;
      s = 1<<31; //s is new sum
      j=k=l=0;
      for(int i=0;i<N;++i) //Kadanes Algorithm
      {
        pr[i]=pr[i]+a[x][i];
        t = t+pr[i];
        if (t>s)
        {
          s = t;
          k = i;
          l = j;
        }
        if(t<0)
        {
          t=0;
          j=i+1;
        }
      }
      if (s > S) //If the new one is bigger than the old bigest
      {
        S = s;
        x1 = x;
        y1 = k;
        x2 = z;
        y2 = l;
      }
    }
  }
    //cout <<x1<<"  "<<y1<<"  "<<x2<<"  "<<y2<<endl;
  printf("%d\n",S);
    //cout<< S<<endl;
  return 0;
}
