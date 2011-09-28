#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

const int inf= 1<<30;

int g[3003][3003];

void inline add_edge(int u, int v, int w){
  if(g[u][v] != 0) g[u][v] = g[v][u] = min(g[u][v], w);
  else g[u][v] = g[v][u] = w;
}

int main(){
  int C,L,H;
  while(scanf("%d%d%d", &C, &L, &H)){
    if(C == -1 and L == -1 and H == -1) break;
    int u,v,w;
    for(int i=1;i<=C;++i){
      fill(g[i], g[i] + C + 2, inf);
      g[i][i] = 0;
    }
    
    for(int i=0;i<L;++i){
      scanf("%d%d%d", &u, &v, &w);
      add_edge(u,v,w);
    }
        
    for(int k = 1; k<=C; ++k)
      for(int i = 1; i<=C; ++i)
        for(int j = 1; j<=C; ++j)
          g[i][j] = min(g[i][j], max(g[i][k],g[k][j]));
    
    for(int i = 1; i<H;++i){
      scanf("%d%d", &u, &v);
      printf("%d ", g[u][v]);
    }
    scanf("%d%d", &u, &v);
    printf("%d\n", g[u][v]);
  }
  return 0;
}
