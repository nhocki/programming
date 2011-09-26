#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
int p[100002], prof[100002], cost[100002];

LL LCA(int a, int b) {
  LL cont = 0;
  int pa = prof[a];
  int pb = prof[b];
  if (pa < pb) {
    swap(a, b);
    swap(pa, pb);
  }
  while (pa != pb) {
    cont += LL(cost[a]);
    a = p[a];
    pb++;
  }
  while (a != b) {
    cont += LL(cost[b]);
    cont += LL(cost[a]);
    a = p[a];
    b = p[b];
  }
  return cont;
}

int main() {
  int n, q, a, b;
  p[0] = cost[0] = prof[0] = 0;
  while (scanf("%d", &n)) {
    if(n == 0) break;
    for (int i=1; i<n ;i++) {
      scanf("%d %d", &a, &b);
      p[i] = a;
      cost[i] = b;
      prof[i] = prof[a]+1;
    }
    scanf("%d", &q);
    for(int i=0; i<q ;i++) {
      if (i) printf(" ");
      scanf("%d %d", &a, &b);
      printf("%lld", LCA(a, b));
    }
    puts("");
  }
}
