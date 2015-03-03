#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

#define MAXN 20015

int d[MAXN], low[MAXN], scc[MAXN];
int ticks, current_scc;
bool stacked[MAXN];
stack<int>s;
vector<int>g[MAXN];

int customers, p;

void tarjan(int u){
  d[u] = low[u] = ticks++;
  stacked[u] = true;
  s.push(u);
  vector<int> &out = g[u];
  for(int i=0;i < out.size(); ++i){
    int v = out[i];
    if(d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if(stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }

  if(low[u] == d[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    } while(u != v);
    current_scc++;
  }
}

inline int no(int i) {
  return -1 * i;
}

inline int index(int i){
  return i >= 0 ? i : p - i;
}

int main(){
  while(scanf("%d%d", &customers, &p) == 2 && customers && p){
    // Clean up
    ticks = current_scc = 0;
    while(s.size()) { s.pop(); }
    for(int i = 0;i <= p + 1; ++i){
      stacked[ index(i) ] = false;
      stacked[ index(no(i)) ] = false;

      d[ index(i) ] = -1;
      d[ index( no(i) ) ] = -1;

      scc[index(i)] = scc[index(no(i))] = -1;

      g[ index(i) ].clear();
      g[ index( no(i) ) ].clear();
    }

    int w,x,y,z;
    for(int i = 0; i < customers; ++i){
      scanf("%d%d%d%d", &w, &x, &y, &z);
      //printf("%d %d %d %d\n", w, x , y , z );
      if(w || x){
        if(w == 0) w = x;
        if(x == 0) x = w;
        g[ index( no(w) )].push_back(index(x));
        g[ index( no(x) )].push_back(index(w));
        //printf("~%d -> %d\n", w, x);
        //printf("~%d -> %d\n", x, w);
      }

      if(y || z){
        if(y == 0) y = z;
        if(z == 0) z = y;
        g[ index(y) ].push_back(index( no(z) ));
        g[ index(z) ].push_back(index( no(y) ));
        //printf("%d -> ~%d\n", y, z);
        //printf("%d -> ~%d\n", z, y);
      }
    }

    // puts("\n");
    for(int i = 1; i <= p; ++i){
      if(d[ index(i) ] == -1) { tarjan(index(i)); }
      if(d[ index( no(i) ) ] == -1) { tarjan(index( no(i) )); }
    }

    bool ans = true;
    for(int i = 1; i <= p; ++i){
      if( scc[index(i)] == scc[index(no(i))]){
        ans = false;
        break;
      }
    }
    printf("%s\n", ans ? "yes" : "no");
  }
  return 0;
}
