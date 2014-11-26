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

int N, K;
map<int, vector<int> > g; // g[i][j] -> i comes before j
set<int> s; // A way to know all the numbers in the input. Since they're not ordered.
map<int, int> d; //d[i] dependencies before I can run node i.

// Simple edge. Weight is the dependencies to that edge.
struct edge {
    int to;
    int weight;
    edge() {}
    edge(int t, int w) : to(t), weight(w) {}

    // Sort by weight and then by "name". This is what guarantees that the topological
    // sort we build is the lexicographically smallest one.
    bool operator<(const edge &e)const {
      if(weight != e.weight){ return weight > e.weight; }
      return to > e.to;
    }
};


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
      g[u].push_back(v); d[v]++;
      u = v;
    }
  }

  priority_queue<edge> q;

  // Here we fill the queue with the nodes that have no dependencies. The priority
  // queue will sort them by <number_of_dependencies, id> ascending.
  for(set<int>::iterator i = s.begin(); i != s.end(); ++i){
    int node = *i;
    if(d[node] == 0){ q.push( edge(node, d[node]) ); }
  }

  vector<int> sort;

  while(q.size()){
    int node = q.top().to;
    int deps = q.top().weight;
    q.pop();

    // Since we're always queuing up the nodes, we only process them when they're
    // ready. The queue will always get a node that has no dependencies over one
    // that has. We can just ignore the other ones.
    if( deps == 0){
      sort.push_back(node);

      // Go to all the connected dependencies of `node` and let them know that `node`
      // is ready. We queue the new weights and the priority queue will take care of
      // ordering everything.
      for(int i = 0; i < g[node].size(); ++i){
        int v = g[node][i];
        d[v]--;
        if(d[v] == 0){
          q.push(edge(v, d[v]));
        }
      }
    }else{
      // Once the first "weight" is not 0, that means we've processed *all* of the
      // nodes in the sequence. We're guaranteed that the sequence exist, so all
      // the nodes in the queue are already in the topsort.
      //
      // I'm almost sure this `if` is not needed, but better to be safe than sorry.
      if( sort.size() == s.size() ){ break; }
    }
  }

  // Just print the topsort.
  printf("%d", sort[0]);
  for(int i = 1; i < sort.size(); ++i){ printf(" %d", sort[i]); }
  puts("");

  return 0;
}
