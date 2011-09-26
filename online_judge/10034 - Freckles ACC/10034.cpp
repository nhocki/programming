/**
* Nicolás Hock Isaza
* Name: 10034.cc
* Created On: 24 May 2009
*/

#include<algorithm>
#include<iostream>
#include<cstring>
#include<climits>
#include<cctype>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<cmath>

using namespace std;

#define all(x) x.begin(), x.end()

struct point{
  double x, y;
  point(double X=0.0, double Y=0.0):x(X),y(Y){}
};

struct edge{
  int start,end;
  double w;
  bool operator < (const edge &o)const{
    return w < o.w;
  }
};

double dist(const point& p1, const point&p2){
  double k1 = p1.x - p2.x, k2= p1.y - p2.y;
  double kk = k1*k1 + k2*k2;
  return sqrt(kk);
}

/* Union Find */
int p[505], rank [505];
void make_set(int x){ p[x] = x; rank[x] = 0;}
void link(int x, int y) {
  if (rank[x] > rank[y]) p[y]=x;
  else{
    p[x]=y;
    if (rank[x]==rank[y]) rank[y]++;
  }
}
int find_set(int x) { return x!=p[x] ? p[x] = find_set(p[x]) : p[x];}
void merge(int x, int y){ link(find_set(x), find_set(y)); }
/* End Union Find */double total = 0.0;

int main()
{
  int C;
  scanf("%d",&C);
  while(C--){
    memset(p,0,sizeof p);
    memset(rank,0,sizeof rank);
    int n;
    scanf("%d",&n);
    double x, y;
    vector<point> pts;
    vector<edge> e;
    for(int k=0;k<n;++k){
      make_set(k);
      scanf("%lf%lf",&x,&y);
      pts.push_back(point(x,y));
    }
    make_set(n);
    for(int i=0;i<pts.size();++i){
      for(int j=i+1;j<pts.size();++j){
        double W = dist(pts[i],pts[j]);
        edge t;
        t.start = i;
        t.end = j;
        t.w = W;
        e.push_back(t);
      }
    }
    long double total = 0.0;
    sort(all(e));
    for(int i=0;i<e.size();++i){
      int u=e[i].start, v=e[i].end;
      double w = e[i].w;
      if(find_set(u)!=find_set(v)){
        total+=w;
        merge(u,v);
      }
    }
    printf("%0.2llf\n",total);
    if(C) puts("");
  }
  return 0;
}
