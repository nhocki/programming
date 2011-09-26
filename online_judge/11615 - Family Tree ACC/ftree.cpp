/**
* Nicolás Hock Isaza
* Name: ftree.cc
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

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {						\
for(int __i=0; __i<rows; cout<<endl, ++__i)			\
  for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

  bool m[(2<<20)+1];
int maxF = 0;

int get_father(int cell){
  return 2*cell;
}

int get_mother(int cell){
  return 2*cell + 1;
}

bool visit_cell(int cell){
  if(cell>maxF || m[cell]) return false;
  m[cell] = true;
  visit_cell(get_father(cell));
  visit_cell(get_mother(cell));
  return true;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    mem(m,false);
    int N,A,B;
    scanf("%d%d%d",&N,&A,&B);
    maxF = (1<<N)-1;
    if(A>B) SWAP(A,B);
    m[B] = true;
    visit_cell(1);
    int res=0;
    for(int i=0;i<=maxF;++i) res+=(m[i]);
    printf("%d\n",res);
  }
  return 0;
}
