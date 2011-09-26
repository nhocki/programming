/**
* Nicolás Hock Isaza
* Name: bombs.cc
* Created On: 25 Jun 2009
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

#define MAX 1000
#define inside(x,y) (x)>=0 && (x)<R && (y)>=0 && (y)<C
#define mine(x,y) grid[x][y]

bool grid [MAX+1][MAX+1];

struct node{
  int x,y,dist;
  node(int xx=0,int yy=0,int d=0):x(xx),y(yy),dist(d){}
  bool operator == (const node &o) const{
    return x == o.x && y==o.y;
  }
};

int R,C;

int BFS(const node &start, const node &end){
  queue<node>q;
  q.push(start);
  while(q.size()){
    node actual = q.front();
    q.pop();
    if(actual == end) return actual.dist;
    if(!(inside(actual.x,actual.y) ) ) continue;
    if(mine(actual.x,actual.y) ) continue;
    mine(actual.x,actual.y)=1;
    q.push(node(actual.x, actual.y-1, actual.dist+1) );
    q.push(node(actual.x, actual.y+1, actual.dist+1) );
    q.push(node(actual.x-1, actual.y, actual.dist+1) );
    q.push(node(actual.x+1, actual.y, actual.dist+1) );
  }
  return -1;
}

int main(){
  while(scanf("%d%d",&R,&C)==2 && (R+C)){
    memset(grid,0,sizeof grid);
    int queries;
    scanf("%d",&queries);
    while(queries--){
      int row,total;
      scanf("%d%d",&row,&total);
      while(total--){
        int col;
        scanf("%d",&col);
        grid[row][col]=1;
      }
    }
    int startX, startY, endX, endY;
    scanf("%d%d%d%d",&startX,&startY,&endX,&endY);
    printf("%d\n",BFS( node(startX,startY), node(endX,endY) ) );
  }
  return 0;
}
