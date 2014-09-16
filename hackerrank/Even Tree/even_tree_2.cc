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
#define sz size()
#define lng length()
#define cs c_str()

using namespace std;

int N, M;
vector<int> g[150];

int countNodes(int node){
  int result = 1;

  for(int i=0; i<g[node].size(); ++i)
    result += countNodes(g[node][i]);

  return result;
}

int main(){
  while(scanf("%d%d", &N, &M) == 2){
    for(int i=0; i<= N + 2; ++i) g[i].clear();

    for(int i=0; i<M; ++i){
      int u,v;

      scanf("%d%d", &u, &v);
      g[v].push_back(u);
    }
    int result = 0;

    for(int i = 1; i<=N; ++i){
      result += (countNodes(i) % 2 == 0);
    }

    printf("%d\n", result - 1);
  }
  return 0;
}
