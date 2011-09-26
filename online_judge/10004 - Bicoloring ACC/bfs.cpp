/**
* Nicolás Hock Isaza
* Name: bicoloring-bfs.cc
* Created On: 08 May 2009
*/

#include<inttypes.h>
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

typedef int node;
typedef map<int, vector<int> > graph;

bool BFS(node &source, graph &g){
  vector<int> color(g.size(),-1);
  queue<node> q;
  int c=0;
  q.push(source);
  color[source]=c;
  while(q.size()){
    node s = q.front();
    q.pop();
    c = color[s];
    c = (c+1)%2;
    for(int i=0;i<g[s].size();++i){
      node nnode = g[s][i];
      if (color[nnode]!=-1 && color[nnode]!=c) return false;
      if(color[nnode]==-1){
        color[nnode]=c;
        q.push(nnode);
      }
    }
  }
  return true;
}

int main()
{
  int n;
  while(scanf("%d",&n)==1 && n){
    int r;
    scanf("%d",&r);
    graph m;
    for(int i=0;i<r;++i){
      int x,y;
      cin>>x>>y;
      m[x].push_back(y);
      m[y].push_back(x);
    }
    int start = 0;
    if(BFS(start,m)) cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";
  }
  return 0;
}
