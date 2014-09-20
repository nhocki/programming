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
#define MAXN 50002
#define mem(i,n) memset(i,n,sizeof(i))

bool visited[MAXN];
int g[MAXN];  // g[i] => martian i sends email to g[i]
int dp[MAXN];

int dfs(int i){
  if(visited[i]) return 0;
  visited[i] = true;
  dp[i] = dfs(g[i]) + 1;
  visited[i] = false;
  return dp[i];
}

int main(){
  int T;
  scanf("%d", &T);
  for(int C = 1; C<=T; ++C){
    mem(g, -1);
    mem(dp, 0);
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;++i){
      int u,v;
      scanf("%d%d", &u, &v);
      g[u] = v;
    }

    int best = -1, res = -1;
    for(int i=1; i<=N;++i){
      int tmp = -1;
      if(dp[i] == 0){
        dfs(i);
      }
    }

    for(int i=1; i<=N;++i){
      if(dp[i] > best){
        best = dp[i];
        res = i;
      }
    }

    printf("Case %d: %d\n", C, res);
  }
  return 0;
}
