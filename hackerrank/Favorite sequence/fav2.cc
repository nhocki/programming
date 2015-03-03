#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iterator>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000020;
int N, K;
vector<int>g[MAXN]; // g[i][j]: i comes before j. (i is a dependency of j).
set<int> s;         // A way to know all the numbers in the input. They might not all appear.
int d[MAXN];        // d[i]: dependencies before I can run node i.

int main(){
  scanf("%d", &N);
  for(int c = 0; c < N; ++c){
    scanf("%d", &K);
    int u, v;

    // If the input is: `1 2 3` we don't need to add the vertix (1, 3), since
    // the relation is transitive, so having (1, 2) and (2, 3) will mean we have
    // (1, 3). This is why we add only the needed edges. Otherwise each line
    // would require O(n^2) to be processed.
    scanf("%d", &u);
    for(int i=1; i<K;++i){
      scanf("%d", &v);
      s.insert(u); s.insert(v);
      g[u].push_back(v);
      d[v]++;
      u = v;
    }
  }

  // Use a priority queue that will give you the smallest integer instead of the
  // largest. This way we can assure we're getting the lexicographically smallest
  // one.
  priority_queue<int, vector<int>, std::greater<int> > q;

  // Here we fill the queue with the nodes that have no dependencies. The priority
  // queue will sort them by <id> descending.
  for(set<int>::iterator i = s.begin(); i != s.end(); ++i){
    int node = *i;
    if(d[node] == 0){ q.push( node ); }
  }

  vector<int> sort;

  while(q.size()){
    int node = q.top();
    q.pop();
    sort.push_back(node);

    // Go to all the connected dependencies of `node` and let them know that `node`
    // is ready. We queue the nodes that are ready and the priority queue will
    // take care of the order of things.
    for(int i = 0; i < g[node].size(); ++i){
      int v = g[node][i];
      d[v]--;
      if(d[v] == 0){ q.push(v); }
    }
  }

  // Just print the topsort.
  printf("%d", sort[0]);
  for(int i = 1; i < sort.size(); ++i){ printf(" %d", sort[i]); }
  puts("");

  return 0;
}
