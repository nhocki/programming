/**
* Nicolás Hock Isaza
* Name: friends.cc
* Created On: 25 Jun 2009
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

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {						\
for(int __i=0; __i<rows; cout<<endl, ++__i)			\
  for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

//bool g[30002][30002];
  bool visited[30002];
int N;

map<int,set<int> > graph;

// int DFS(int start){
//     visited[start] = 1;
//     for(int i=1;i<=N;++i)
// 	if(g[start][i] && !visited[i])
// 	    return 1+DFS(i);
//     return 1;
// }

int DFS_set(int start){
  visited[start]=1;
  int ans = 0;
  foreach(i,graph[start]){
    if(!visited[*(i)]) 
      ans+= (1+DFS_set(*(i)));
  }
  return ans;
}

int main(){
  int C;
  scanf("%d",&C);
  while(C--){
  //memset(g,false,sizeof(g));
    memset(visited,false,sizeof(visited));
    graph.clear();
    int M,x,y;
    scanf("%d%d",&N,&M);
    while(M--){
      scanf("%d%d",&x,&y);
      graph[x].insert(y);
      graph[y].insert(x);
      //g[x][y] = g[y][x] = 1;
    }
    int most = -1;
    for(int i=1;i<=N;++i)
      if(!visited[i])
      most = max(most,DFS_set(i)+1);
    printf("%d\n",most);
  }
  return 0;
}
