/**
* Nicolás Hock Isaza
* Name: nc.cc
* Created On: 04 Sep 2009
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

#define MAXNODES 750

struct edge{
  int start,end; 
  double weight;
  edge(int s,int e, double w):start(s),end(e),weight(w) {    }
  bool operator < (const edge &that) const{
    return weight < that.weight;
  }
};

struct point{
  int x,y;
  point(int xx=0,int xy=0):x(xx),y(xy){}
};

int p[MAXNODES], rank[MAXNODES];

void make_set(int x){ p[x] = x, rank[x] = 0;}
void link(int x, int y){
  if(rank[x]>rank[y]) p[y]=x;
  else{
    p[x]=y;
    if(rank[x]==rank[y]) rank[y]++;
  }
}

int find_set(int x){
  return x!=p[x] ? p[x] = find_set(p[x]) : p[x];
}

void merge(int x, int y){ link(find_set(x),find_set(y));}

double dist(point &p1, point &p2){
  double d1 = (p1.x - p2.x) * (p1.x-p2.x), d2 = (p1.y-p2.y)*(p1.y-p2.y);
  return sqrt(d1+d2);
}

int n;

double kruskal(vector<edge> &e){
  double total = 0.0;
  sort(all(e));
  for(int i=0;i<=n;++i){
    make_set(i);
  }
  for(int i=0;i<e.sz;++i){
    int u = e[i].start, v = e[i].end; double w = e[i].weight;
    if(find_set(u)!=find_set(v)){
      total+=w;
      merge(u,v);
    }
  }
  return total;
}

int main(){
  while(scanf("%d",&n)==1){
    vector<point> campus;
    for(int i=0;i<n;++i){
      int x,y;
      scanf("%d%d",&x,&y);
      campus.pb(point(x,y));
    }
    set<pair<int,int> >cables;
    int queries;
    scanf("%d",&queries);
    vector<edge> dists;
    for(int i=0;i<queries;++i){
      int from,to;
      scanf("%d%d",&from,&to);
      --from;--to;
      cables.insert(pair<int,int>(from,to));
      cables.insert(pair<int,int>(to,from));

      dists.push_back(edge(from,to,0));
      dists.push_back(edge(to,from,0));
    }
    for(int i=0;i<campus.sz;++i){
      for(int j=i+1;j<campus.sz;++j){
        if(cables.count(pair<int,int>(i,j)) || i==j) continue;
        double dd = dist(campus[i],campus[j]);
        dists.push_back(edge(i,j,dd));
        dists.push_back(edge(j,i,dd));
      }
    }
    double total = kruskal(dists);
    printf("%.2lf\n",total);
  }
  return 0;
}
