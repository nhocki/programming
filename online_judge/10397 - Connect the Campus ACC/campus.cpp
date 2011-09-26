/**
* Nicolás Hock Isaza
* Name: campus.cc
* Created On: 03 Sep 2009
*/

#include<algorithm>
#include<iostream>
#include<iomanip>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

using namespace std;

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {                      \
for(int __i=0; __i<rows; cout<<endl, ++__i)     \
  for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

#define ABS(x) x>0?x:-x

struct point{
  int x,y;
  point(int X=0, int Y=0):x(X),y(Y) {}
};

double dist(int x1, int y1, int x2, int y2){
  x1 = ABS(x1), y1 = ABS(y1), x2 = ABS(x2), y2 = ABS(y2);
  double d1 = (x1-x2)*(x1-x2);
  double d2 = (y1-y2)*(y1-y2);
  return sqrt(d1+d2);
}

double pdist(point p1,point p2){return dist(p1.x,p1.y, p2.x, p2.y);}


int main(){
  int N;
  while(scanf("%d",&N)==1){
    vector<point> campus;
    int xx,yy;
    for(int i=0;i<N;++i){
      scanf("%d%d",&xx,&yy);
      campus.pb(point(xx,yy));
    }
    int cables;
    scanf("%d",&cables);
    vector<vector<int> > graph (N+1, vector<int>(N+1,INT_MAX));
    bool con[N+1];
    mem(con,false);
    for(int i=0;i<cables;++i){
      scanf("%d%d",&xx,&yy);
      --xx; --yy;
      graph[xx][yy]=graph[yy][xx]=pdist(campus[xx],campus[yy]);
      con[xx] = con[yy] = 1;
    }
    double res = 0.0;
    for(int i=0;i<campus.sz;++i){
      if(con[i]) continue;
      double dst = INT_MAX;
      for(int j=0;j<campus.sz;++j){
        if(i!=j) {
          D(pdist(campus[i],campus[j]));
          dst = min(dst, pdist(campus[i],campus[j]));
        }
      }
      D(dst);
      res+=dst;
    }
    printf("%0.2lf\n",res);
  }
  return 0;
}
