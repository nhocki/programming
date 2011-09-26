#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define D(x) cout << #x " is " << x << endl

const int MAXN = 30;

map<int, vector<int> > g;
set<int> visited;

int p[30];
int rank[40];


void make_set(int i){ p[i] = i; }
int find(int i){ return (p[i] != i) ? p[i] = find(p[i]) : p[i]; }
int merge(int i, int k){p[find(i)] = find(k);}

inline int index(char a){
  return a - 'A' + 1;
}

int main(){
  int N;
  scanf("%d", &N);
  string line;
  getline(cin, line);
  getline(cin, line);
  bool first = true;
  while(N--){
    if(!first) puts("");
    first = false;
    char _max_node;
    scanf("%c", &_max_node);
    int max_node = _max_node - 'A' + 1;
    getline(cin, line);
    for(int i=0;i<30;++i){
      g[i].clear();
      make_set(i);
    }
    visited.clear();
    while(cin.peek() >= 'A'){
      getline(cin, line);
      char a = line[0], b = line[1];
      int _a = find(index(a));
      int _b = find(index(b));
      if(_a != _b){
        merge(index(a), index(b));
      }
    }
    getline(cin, line);
    int count = 0;
    visited.clear();
    for(int i=1;i<=max_node;++i){
      visited.insert(find(i));
    }
    cout << visited.size() << endl;
  }
  return 0;
}
