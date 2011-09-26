/**
* Nicolás Hock Isaza
* Name: 544.cc
* Created On: 07 May 2009
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define mem(i,n) memset(i,n,sizeof(i))

using namespace std;

int  d[202][202]; 

int main()
{
  int n, r,caso=1;
  while(scanf("%d%d",&n,&r)==2 && (n+r)){
    printf("Scenario #%d\n",caso++);
    int count = 0;
    map<string,int> ids;
    set<string> entered;
    string from,to;
    for(int i=0;i<r;++i){
      int ww;
      cin>>from>>to>>ww;
      if(ids[from]==0 && !entered.count(from))
        {ids[from]=count++; entered.insert(from);}
      if(ids[to]==0 && !entered.count(to))
        {ids[to]=count++; entered.insert(from);}
      int i = ids[from], j = ids[to];
      d[i][j] = d[j][i] = ww;
      d[i][i]=d[j][j]=0;
    }

    cin>>from>>to;

    for(int k = 0; k<n;++k)
      for(int i = 0; i<n;++i)
      for(int j = 0; j<n; ++j)
      d[i][j]=max(d[i][j], min(d[i][k], d[k][j]));

    printf("%d tons\n\n",d[ids[from]][ids[to]]);
    mem(d,0);
  }
  return 0;
}
