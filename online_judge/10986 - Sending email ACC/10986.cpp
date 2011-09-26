/**
* Nicolás Hock Isaza
* Name: 10986.cc
* Created On: 06 May 2009
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

struct edge{
  int to;
  int weight;
  edge(){}
  edge(int t, int w): to(t), weight(w) {}
  bool operator < (const edge &e) const{
    return weight > e.weight;
  }
};

int Dijkstra(int source, int to, vector< vector<edge> > &g){
  vector<int> distance(g.size(), INT_MAX);
  distance[source]=0;
  priority_queue <edge> q;
  q.push(edge(source,0));
  while(q.size()){
    int node = q.top().to;
    int dist = q.top().weight;
    q.pop();
    if( dist > distance[node]) continue;
    if( node == to) break;

    for(int i=0;i<g[node].size(); ++i){
      int t = g[node][i].to;
      int w = g[node][i].weight;

      if(w + dist < distance[t]){
        distance[t] = w+dist;
        q.push(edge(t,distance[t]));
      }
    }
  }
  return distance[to];
}

int main()
{
  int cases;
  cin >> cases;
  int count = 1;
  while(cases--) {
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    vector<vector<edge> > g(n);
    for(int i=0;i<m;++i){
      int from,to,w;
      scanf("%d%d%d",&from,&to,&w);
      g[from].pb(edge(to,w));
      g[to].pb(edge(from,w));
    }
    int res = Dijkstra(s,t,g);
    printf("Case #%d: ",count++);
    if(res==INT_MAX) cout<<"unreachable"<<endl;
    else cout<<res<<endl;
  }
  return 0;
}
