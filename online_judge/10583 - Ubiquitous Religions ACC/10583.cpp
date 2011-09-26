/**
* Nicolás Hock Isaza
* ACC
* Union Find
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl

int p[50005], rank [50005];
set<int>s;
void make_set(int x){ p[x] = x; rank[x] = 0;}
void link(int x, int y) {
  if (rank[x] > rank[y]){
    p[y]=x;
    s.erase(y);
  }
  else{
    p[x]=y;
    s.erase(x);
    if (rank[x]==rank[y]) rank[y]++;
  }
}
int find_set(int x) { return x!=p[x] ? p[x] = find_set(p[x]) : p[x];}
void merge(int x, int y){link(find_set(x), find_set(y));}

int main(){
  int n, m;
  int C=1;
  while(scanf("%d%d", &n,&m)==2 && (n+m)){
    s.clear();
    for(int i=1;i<=n;++i) { make_set(i); s.insert(i); }
    for(int i=0;i<m;++i){
      int A,B;
      scanf("%d%d", &A, &B);
      if(find_set(A)!=find_set(B))
        merge(A,B);
    }
    printf("Case %d: %d\n", C++, s.size());
  }
  return 0;
}
