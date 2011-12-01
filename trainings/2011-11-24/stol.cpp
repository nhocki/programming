#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define D(x) cout <<#x" is "<< x << endl;
#define INF 2<<30-1
#define MAXN 405

int blocked[MAXN][MAXN]; // blocked[i][j] = number of blocked spots in row i till column j
string apto[MAXN];

int R, S;


int main(){
  scanf("%d%d", &R, &S);
  for(int i=0;i<R;++i){
    cin >> apto[i];
    for(int j=0;j<S;++j){
      blocked[i][j] = (apto[i][j] == 'X');
      blocked[i][j] += blocked[i][j - 1]
    }
  }
  int best = -1;
  for(int i=0;i<S;++i){
    current = -1;
    for(int j=i+1;j<S;++j){
      for(int x = 0; x < R; ++x){
        for(int y = x + 1; y < R; ++y){
          int tmp = blocked[x]
          current = 
        }
      }
    }
    best = max(current, best);
  }
  return 0;
}