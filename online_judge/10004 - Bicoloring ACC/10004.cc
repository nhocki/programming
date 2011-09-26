/**
* Nicolás Hock Isaza
* Name: 10004.cc
* Created On: 10 Mar 2009
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
#define D_m(m,rows,cols) for(int _i_=0;_i_<rows;cout<<endl,++_i_) for(int _j_=0;_j_<cols;) cout <<m[_i_][_j_++]<<"  "
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

bool DFS(int nodo, int color, int *colores, vector<int> *m)
{
  if (colores[nodo]!=-1) return colores[nodo]==color;//Si ya pinte el nodo, retorno si mi color es igual al esperado
  colores[nodo]=color;
  for (int i=0;i<m[nodo].sz;++i)
  {
    int new_color = (color+1)%2; //El color de mis vecinos tiene que ser diferente al mio
    if (DFS(m[nodo][i],new_color,colores,m) == false) return false;
  }
  return true;
}

int main()
{
  int n,L;
  while (cin >> n && n)
  {
    vector <int>m[n];
    int color[n];
    mem(color,-1); //No he pintado
    cin >> L;
    For(l,L)
    {
      int i,j;
      scanf("%d %d",&i,&j);
      m[i].pb(j),m[j].pb(i);
    }
    printf("%sBICOLORABLE.\n",(DFS(0,0,color,m)==false)?"NOT ":"");
  }
  return 0;
}
