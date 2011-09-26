#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

#define MAX 10005

#define D(x) cout << #x" is "<<x<<endl

map<string,int> d;
set<string> s;

int bfs(string start, string end){
    //puts("*** BFS ***");
  d[start]=0;
  queue<string> q;
  q.push(start);
  while(q.size()){
    string act = q.front();
    q.pop();
    string v = act;
    if(act == end) return d[act];
    for(int i=0;i<4;++i){
      for(int dl=-1;dl<=1;dl+=2){
        int t = ((v[i]-48+dl)+10)%10;
        v[i] = t+48;
        if(v==end) return d[act]+1;
        if(!s.count(v)){
          if(d[v]==0){
            d[v] = d[act]+1;
            q.push(v);
          }
        }
        t = ((-48+v[i]-dl)+10)%10;
        v[i]= t+48;
      }
    }
  }
  return -1;
}

int main(){
  int C;
  scanf("%d", &C);
  while(C--){
    s.clear();
    d.clear();
    int ss = 0;
    string from(4,'a');
    string to(4,'b');
    for(int i=0;i<4;++i){
      scanf("%d", &ss);
      from[i] = char(ss+48);
    }
    for(int i=0;i<4;++i){
      scanf("%d", &ss);
      to[i] = char(48+ss);
    }
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;++i){
      string tmp(4, 'a');
      for(int i=0;i<4;++i){
        scanf("%d", &ss);
        tmp[i]=char(ss+48);
      }
      s.insert(tmp);
    }
    if(from != to)
      printf("%d\n", bfs(from,to));
    else puts("0");
  }
  return 0;
}
