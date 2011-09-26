/**
* Nicolás Hock Isaza
* Name: risk.cc
* Created On: 03 Sep 2009
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

int main(){
  int x;
  int C = 1;
  while(scanf("%d",&x)==1){
    vector<vector<int> > dist(22, vector<int>(22, 300));
    for(int j=0;j<x;++j){
      int node;
      dist[1][1]=0;
      scanf("%d",&node);
      dist[1][node]=dist[node][1] = 1;
    }
    for(int i=2;i<=19;++i){
      dist[i][i] = 0;
      scanf("%d",&x);
      int node;
      for(int j=0;j<x;++j){
        scanf("%d",&node);
        dist[i][node]=dist[node][i] = 1;
      }
    }

    for(int k=0;k<22;++k){
      for(int i=0;i<22;++i){
        for(int j=0;j<22;++j){
          dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
      }
    }
    printf("Test Set #%d\n",C++);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
      int from, to;
      scanf("%d%d",&from,&to);
      printf("%2d to %2d: %d\n",from,to,dist[from][to]);
    }
    puts("");
  }
  return 0;
}
