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

map<string, vector<string> >graph;
set<string> visited;

int bfs(string &from, string &to){
  queue<pair<string, int> > q;
  q.push(make_pair(from, 0));
  visited.insert(from);

  while(q.size()){
    pair<string, int> node = q.front();
    q.pop();
    visited.insert(node.first);


    for(int i=0; i<graph[node.first].size(); ++i){
      string conn = graph[node.first][i];

      if(conn == to) { return node.second + 1; }

      if(!visited.count(conn)){
        q.push(make_pair(conn, node.second + 1));
      }
    }
  }
  return -1;
}


int main(){
  int cases, M, N, P, caso = 1;
  scanf("%d", &cases);
  puts("SHIPPING ROUTES OUTPUT");

  while(cases--){
    printf("\nDATA SET  %d\n\n", caso++);

    graph.clear();
    scanf("%d%d%d", &N, &M, &P);

    for(int i=0;i<N;++i){
      string warehouse;
      cin >> warehouse;
    }

    for(int i=0; i<M; ++i){
      string from, to;
      cin >> from >> to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    for(int i = 0; i<P; ++i){
      visited.clear();
      int weight = 0;
      string from, to;
      cin >> weight >> from >> to;
      int result = 100 * weight * bfs(from, to);
      if(result >= 0){
        printf("$%d\n", result);
      }else{
        puts("NO SHIPMENT POSSIBLE");
      }
    }
  }
  puts("\nEND OF OUTPUT");
  return 0;
}
