/**
* Nicolás Hock Isaza
* Name: 439.cc
* Created On: 04 Sep 2009
*/

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

#define sz size()
#define cs c_str()

#define inside(x,y) (x>=0 && x<=7 && y>=0 && y<=7)

int dis[8]={-2,-2,-1,-1,1,1,2,2};
int djs[8]={-1,1,-2,2,-2,2,-1,1};

typedef pair<int,int> node;
bool v[30][30];
int dist[30][30];

int BFS(node init, node end){
  queue<node> q;
  dist[init.first][init.second] = 0;
  q.push(init);
  while(q.size()){
    node actual = q.front(); q.pop();
    if(!inside(actual.first, actual.second) || v[actual.first][actual.second]) continue;
    v[actual.first][actual.second] = true;
    if(actual == end) return dist[actual.first][actual.second];
    for(int i=0;i<8;++i){
      int nx = dis[i] + actual.first;
      int ny = djs[i] + actual.second;
      q.push(node(nx,ny));
      dist[nx][ny] = dist[actual.first][actual.second]+1;
    }
  }
  return dist[end.first][end.second];
}

int main(){
  string from, to;
  while(cin>>from>>to){
    memset(v,false,sizeof v);
    memset(dist,300,sizeof dist);
    node init(from[1]-'0'-1,from[0]-'a');	
    node en(to[1]-'0'-1,to[0]-'a');
    printf("To get from %s to %s takes %d knight moves.\n", from.cs, to.cs, BFS(init,en));
  }
  return 0;
}
