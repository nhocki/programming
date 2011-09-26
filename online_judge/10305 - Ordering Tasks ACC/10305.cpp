#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int d[105];
vector<int> g[105];

void add_edge(int u, int v){
  g[u].push_back(v);
  d[v]++;
}

int main(){
  int n,m,u,v;
  while(scanf("%d%d",&n,&m)==2 && (m+n)){
    bool first = true;
    for(int i=0;i<n;++i){d[i] = 0; g[i].clear();}
    while(m--){
      scanf("%d%d",&u,&v);
      u--;v--;
      add_edge(u,v);
    }
    queue<int> q;
    for(int i=0;i<n;++i) if(d[i] == 0) q.push(i);
    while(q.size()){
      int node = q.front(); q.pop();
      if(!first) printf(" ");
      printf("%d", node+1);
      first = false;
      for(int i=0;i<g[node].size();++i){
        int j = g[node][i];
        d[j]--;
        if(d[j] == 0){
          q.push(j);
        }
      }
    }
    puts("");
  }
  return 0;
}
