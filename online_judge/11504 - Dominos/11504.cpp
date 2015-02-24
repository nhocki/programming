#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 100050;

vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN], in[MAXN];
int ticks, current_scc;
bool stacked[MAXN];
stack<int> s;

void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u); stacked[u] = true;

  const vector<int> &out = g[u];
  for(int i = 0; i < out.size(); ++i){
    const int &v = out[i];
    if(d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if(stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }

  // Look if I'm a SCC root
  if(low[u] == d[u]){
    int v;
    do {
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    } while(v != u);
    current_scc++;
  }
}

int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    int n,m;
    scanf("%d%d", &n, &m);

    // Clear everything.
    current_scc = 0;
    ticks = 0;
    while(s.size()) { s.pop(); }
    for(int i = 0; i <= n + 1;++i){
      d[i] = scc[i] = low[i] = -1;
      in[i] = 0;
      g[i].clear();
      stacked[i] = false;
    }

    // Build the graph
    for(int i = 0; i < m; ++i){
      int u,v;
      scanf("%d%d", &u, &v);
      u--; v--;
      g[u].push_back(v);
    }

    // Run tarjan for each node we haven't seen yet.
    for(int i = 0; i < n; ++i){
      if(scc[i] == -1){ tarjan(i); }
    }

    // For each node get its scc and check how many out edges that node has
    // to nodes in other scc.
    for(int i = 0; i < n ; ++i){
      const vector<int> &out = g[i];
      for(int j = 0; j < out.size(); ++j){
        int v = out[j];
        if(scc[i] != scc[v]){ in[ scc[v] ]++; }
      }
    }

    // Count the number of scc that need to be taken down manually.
    int count = 0;
    for(int i = 0 ; i < current_scc ; ++i){
      if(in[i] == 0){ count++; }
    }
    printf("%d\n", count);
  }
  return 0;
}
