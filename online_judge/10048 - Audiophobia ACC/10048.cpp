/**
* Nicolás Hock Isaza
* Name: 10048.cc
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

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {                      \
for(int __i=0; __i<rows; cout<<endl, ++__i)     \
  for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()
#define INF INT_MAX

  unsigned int d[105][105];

int main(){
  int C,S,Q,caso=1;
  while(scanf("%d%d%d",&C,&S,&Q)==3 && (C+S+Q)){
    if(caso!=1)puts("");
    for(int i=0;i<105;++i)  for(int j=0;j<105;++j) d[i][j] = INT_MAX;
    printf("Case #%d\n",caso++);
    for(int i=0;i<S;++i){
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      d[x][y]=d[y][x]=w;
      d[x][x]=d[y][y]=0;
    }
    for(int k=1;k<=C;++k)
      for(int i=1;i<=C;++i)
      for(int j=1;j<=C;++j)
      d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));

    for(int i=0;i<Q;++i){
      int from,to;
      scanf("%d%d",&from,&to);
      if(from > C || to > C){ puts("no path"); continue; }
      if(d[from][to] != INF)
        printf("%d\n",d[from][to]);
      else puts("no path");
    }

  }
  return 0;
}
