#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2

vector<int> segment_tree;
vector<int> A;

void init_seg_tree(int N){
  int length = (int) (2.0 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
  segment_tree.resize(length, 0);
  A.resize(N,0);
}

void build_segment_tree(int code, int node, int b, int e){
  printf("Building segment tree from %d to %d on node %d\n", b, e, node);
  if(b == e){
    if(code == RANGE_SUM) segment_tree[node] = A[b];
    else segment_tree[node] = b;
  }else{
    int lft = 2*node, rght = 2*node + 1;
    int mid = (b+e)/2;
    build_segment_tree(code, lft, b, mid);
    build_segment_tree(code, rght, mid+1, e);
    int lC = segment_tree[lft], rC = segment_tree[rght];
    printf("Building segment tree from %d to %d on node %d got lC = %d and rC = %d\n", b, e, node, lC, rC);
    if(code == RANGE_SUM)
      segment_tree[node] = max(0, lC+rC);
    else{
      int lV = A[lC], rV = A[rC];
      if(code == RANGE_MIN) segment_tree[node] = (lV <= rV) ? lC : rC;
      else segment_tree[node] = (lV >= rV) ? lC : rC;
    }
  }
}

int query(int code, int node, int b, int e, int i, int j){
  printf("Quering segment tree from %d to %d on node %d interval (%d, %d)\n", b, e, node, i, j);
  if(i > e || j < b){
    printf("query from %d to %d returned %d\n", b, e, -1);
    return -1;
  }
  if(b >= i && e <= j){
    printf("query from %d to %d returned %d\n", b, e, segment_tree[node]);
    return segment_tree[node]; //It's inside!
  }
  int lft = 2*node, rght = 2*node + 1;
  int mid = (b+e)/2;
  int p1 = query(code, lft, b, mid, i, j);
  int p2 = query(code, rght, mid+1, e, i, j);
  printf("query from %d to %d returned p1 = %d and p2 = %d\n", b, e, p1, p2);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  if(code == RANGE_SUM) return max(0, p1 + p2);
  if(code == RANGE_MIN) return (A[p1] <= A[p2]) ? p1 : p2;
  return (A[p1] >= A[p2]) ? p1 : p2;
}

int main(){
  int N, M;
  scanf("%d", &N);
  init_seg_tree(N);
  for(int i=0;i<N;++i) scanf("%d", &A[i]);
  build_segment_tree(RANGE_SUM, 0, 0, N-1);
  scanf("%d", &M);
  int x, y;
  for(int i=0;i<M;++i){
    scanf("%d%d", &x, &y);
    printf("%d\n", query(RANGE_SUM, 0, 0, N-1, --x, --y));
  }
  return 0;
}
