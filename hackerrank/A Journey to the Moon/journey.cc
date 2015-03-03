#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100020;

bool visited[MAXN];
unsigned long long total[MAXN], partials[MAXN];
vector<int>g[MAXN];
vector<int>which;

unsigned long long dfs(int u){
  visited[u] = true;
  int ans = 1;
  vector<int> &out = g[u];
  for(int i = 0; i < out.size(); ++i){
    int node = out[i];
    if(!visited[ node ]){ ans += dfs(node); }
  }
  return ans;
}

int main(){
  int N, I;
  scanf("%d%d", &N, &I);

  int u,v;
  for(int i = 0; i < I; ++i){
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for(int i = 0; i<N ; ++i){
    if(!visited[i]) {
      which.push_back(i);
      total[i] = dfs(i);
    }
  }

  unsigned long long ans = 0;
  int n = which.size();
  partials[0] = total[0];

  for(int i = 1; i < n; ++i){
    partials[i] = partials[i - 1] + total[which[i]];
  }

  for(int i = 0; i < n; ++i){
    ans += (total[which[i]] * (partials[n - 1] - partials[i]));
  }

  printf("%llu\n", ans);

  return 0;
}
