#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

/////////////// Complexity: O(V * E^2) ///////////////
/*
Usage:
initialize_max_flow();
Create graph using add_edge(u, v, c);
max_flow(source, sink);
WARNING: The algorithm writes on the cap array. The capacity
is not the same after having run the algorithm. If you need
to run the algorithm several times on the same graph, backup
the cap array.
*/
const int MAXE = 10000; //Maximum number of edges
const int oo = INT_MAX / 4 - 1;
int cap[MAXE];
int first[MAXE];
int next[MAXE];
int adj[MAXE];
int current_edge;
/*
Builds a directed edge (u, v) with capacity c.
Note that actually two edges are added, the edge
*/
int add_edge(int u, int v, int c){
  adj[current_edge] = v;
  cap[current_edge] = c;
  next[current_edge] = first[u];
  first[u] = current_edge++;
  adj[current_edge] = u;
  cap[current_edge] = 0;
  next[current_edge] = first[v];
  first[v] = current_edge++;
}
void initialize_max_flow(){
  current_edge = 0;
  memset(next, -1, sizeof next);
  memset(first, -1, sizeof first);
  memset(cap, 0, sizeof cap);
}
int q[MAXE];
int incr[MAXE];
int arrived_by[MAXE];
//arrived_by[i] = The last edge used to reach node i
int find_augmenting_path(int src, int snk){
    /*
    Make a BFS to find an augmenting path from the source to
    the sink. Then pump flow through this path, and return
    the amount that was pumped.
    */
    memset(arrived_by, -1, sizeof arrived_by);
  int h = 0, t = 0;
  q[t++] = src;
  arrived_by[src] = -2;
  incr[src] = oo;
  while (h < t && arrived_by[snk] == -1){ //BFS
    int u = q[h++];
    for (int e = first[u]; e != -1; e = next[e]){
      int v = adj[e];
      if (arrived_by[v] == -1 && cap[e] > 0){
        arrived_by[v] = e;
        incr[v] = min(incr[u], cap[e]);
        q[t++] = v;
      }
    }
  }
  if (arrived_by[snk] == -1) return 0;
  int cur = snk;
  int neck = incr[snk];
  while (cur != src){
        //Remove capacity from the edge used to reach node "cur"
        //Add capacity to the backedge
    cap[arrived_by[cur]] -= neck;
    cap[arrived_by[cur] ^ 1] += neck;
        //move backwards in the path
    cur = adj[arrived_by[cur] ^ 1];
  }
  return neck;
}
int max_flow(int src, int snk){
  int ans = 0, neck;
  while ((neck = find_augmenting_path(src, snk)) != 0){
    ans += neck;
  }
  return ans;
}

int main(){
  int n, caso=1;
  while(scanf("%d", &n) && n){
    initialize_max_flow();
    int source, destination, nodes;
    scanf("%d%d%d", &source, &destination, &nodes);
    int u,v,w;
    source--; destination--;
    for(int i=0;i<nodes;++i){
      scanf("%d%d%d", &u, &v, &w);
      u--; v--;
      add_edge(u,v,w);
      add_edge(v,u,w);
    }
    printf("Network %d\nThe bandwidth is %d.\n", caso++, max_flow(source, destination));
  }
  return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

/////////////// Complexity: O(V * E^2) ///////////////
/*
Usage:
initialize_max_flow();
Create graph using add_edge(u, v, c);
max_flow(source, sink);
WARNING: The algorithm writes on the cap array. The capacity
is not the same after having run the algorithm. If you need
to run the algorithm several times on the same graph, backup
the cap array.
*/
const int MAXE = 10000; //Maximum number of edges
const int oo = INT_MAX / 4 - 1;
int cap[MAXE];
int first[MAXE];
int next[MAXE];
int adj[MAXE];
int current_edge;
/*
Builds a directed edge (u, v) with capacity c.
Note that actually two edges are added, the edge
*/
int add_edge(int u, int v, int c){
  adj[current_edge] = v;
  cap[current_edge] = c;
  next[current_edge] = first[u];
  first[u] = current_edge++;
  adj[current_edge] = u;
  cap[current_edge] = 0;
  next[current_edge] = first[v];
  first[v] = current_edge++;
}
void initialize_max_flow(){
  current_edge = 0;
  memset(next, -1, sizeof next);
  memset(first, -1, sizeof first);
  memset(cap, 0, sizeof cap);
}
int q[MAXE];
int incr[MAXE];
int arrived_by[MAXE];
//arrived_by[i] = The last edge used to reach node i
int find_augmenting_path(int src, int snk){
    /*
    Make a BFS to find an augmenting path from the source to
    the sink. Then pump flow through this path, and return
    the amount that was pumped.
    */
    memset(arrived_by, -1, sizeof arrived_by);
  int h = 0, t = 0;
  q[t++] = src;
  arrived_by[src] = -2;
  incr[src] = oo;
  while (h < t && arrived_by[snk] == -1){ //BFS
    int u = q[h++];
    for (int e = first[u]; e != -1; e = next[e]){
      int v = adj[e];
      if (arrived_by[v] == -1 && cap[e] > 0){
        arrived_by[v] = e;
        incr[v] = min(incr[u], cap[e]);
        q[t++] = v;
      }
    }
  }
  if (arrived_by[snk] == -1) return 0;
  int cur = snk;
  int neck = incr[snk];
  while (cur != src){
        //Remove capacity from the edge used to reach node "cur"
        //Add capacity to the backedge
    cap[arrived_by[cur]] -= neck;
    cap[arrived_by[cur] ^ 1] += neck;
        //move backwards in the path
    cur = adj[arrived_by[cur] ^ 1];
  }
  return neck;
}
int max_flow(int src, int snk){
  int ans = 0, neck;
  while ((neck = find_augmenting_path(src, snk)) != 0){
    ans += neck;
  }
  return ans;
}

int main(){
  int n, caso=1;
  while(scanf("%d", &n) && n){
    initialize_max_flow();
    int source, destination, nodes;
    scanf("%d%d%d", &source, &destination, &nodes);
    int u,v,w;
    source--; destination--;
    for(int i=0;i<nodes;++i){
      scanf("%d%d%d", &u, &v, &w);
      u--; v--;
      add_edge(u,v,w);
      add_edge(v,u,w);
    }
    printf("Network %d\nThe bandwidth is %d.\n", caso++, max_flow(source, destination));
  }
  return 0;
}
