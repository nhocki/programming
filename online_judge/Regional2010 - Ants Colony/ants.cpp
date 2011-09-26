#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define D(x) cout << #x"  is  " << x << endl
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x != v.end(); ++x)

const int MAXN = 100005;
const int LOGMAXN = 20;
const double EPS = 1e-9;

int cmp(double x, double y, double tol = EPS){
    return (x<=y+tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef map<int, vector<int> > graph;
typedef pair<int, long long> ii;

long long st[LOGMAXN][MAXN];
long long dist[MAXN];
long long m[2*MAXN + 2];
long long l[MAXN];
ii T[MAXN+5];

int leading_zeros(int a){
  int cnt = 0, where = 0;
  while(a){
    if(a&1) where = cnt;
    cnt++;
    a>>=1;
  }
  return 31 - where;
}

void st_init(int N){
  int i,j;
  for(i = 0; i<N; i++) st[0][i] = i;
  for(j = 1; (1<<j) <= N; j++){
    for(i = 0; i+(1<<j) <= N; i++){
      if(m[st[j-1][i]] < m[st[j-1][i+(1<<(j-1))]])
        st[j][i] = st[j-1][i];
      else
        st[j][i] = st[j-1][i+(1<<(j-1))];
    }
  }
}

int st_query(int N, int s, int e){
  if(s>e) return st_query(N, e, s);
  int k = 31 - __builtin_clz(e - s);
  if(m[st[k][s]] < m[st[k][e- (1<<k) ]]) return st[k][s];
  return st[k][e - (1<<k)];
}


int _count = 1;
int which = 1;
graph g;
map<int, int> id;

inline int index(int u, bool dbg = false){
  if(id[u] == 0) id[u] = _count++;
  if(dbg) printf("@index => %d -> %d\n", u, id[u]);
  return id[u];
}

void count_if_first_time(int node){
  if(l[index(node)] == -1) l[index(node)] = which - 1;
}

void build_euler_tour(int node){
  int _id = index(node, false);
  dist[_id] = dist[T[_id].first] + T[_id].second;
  m[which++] = _id;
  count_if_first_time(node);
  for(int i=0;i<g[_id].size();++i){
    build_euler_tour(g[_id][i]);
    m[which++] = _id;
  }
}

int main(){
  int N;
  while(scanf("%d",&N)){
    if(N==0) break;
    _count = 1;
    which = 1;
    id.clear();
    g.clear();
    int A,L;
    for(int i=0;i<=N+2;++i) {T[i] = make_pair(0,0); l[i] = -1;}
    T[index(0)] = make_pair(index(0),0);
    for(int i=1;i<N;++i){
      scanf("%d%d", &A, &L);
      int index_i = index(i), index_a = index(A);
      T[index_i] = make_pair(index_a, L);
      g[index_a].push_back(i);
    }
    build_euler_tour(0);
    st_init(N+1);
    int Q;
    scanf("%d",&Q);
    int q1, q2, index1, index2;
    for(int i=0;i<Q;++i){
      scanf("%d%d", &q1, &q2);
      if(l[q1] > l[q2]) swap(q1,q2);
      index1 = index(q1);
      index2 = index(q2);
      int LCA = st_query(N+2, l[q1], l[q2]);
      printf("%lld ", dist[index(q1)] + dist[index(q2)] - 2*dist[m[LCA]]);
    }
    puts("");
  }
  return 0;
}
