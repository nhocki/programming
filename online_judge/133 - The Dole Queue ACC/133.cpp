
/**
* Nicolás Hock Isaza
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
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

vector<int>q;
int N,k,m;
bool second_t = false;
int gCW(int p){
  int t = *(max_element(all(q)));
  if(t==-1) return -10;
  int c=0;
  while(true){
    if(q[p]!=-1)c++;
    if(c>=m) break;
    p--;
    if(p<0) p=q.size()-1;
  }
  return p;
}

int gCCW(int p){
  int c=0;
  int t = *(max_element(all(q)));
  if(t==-1) return -10;
  while(c<k){
    if(q[p]!=-1)c++;
    ++p%=q.size();
  }
  return p!=0?p-1:q.size()-1;
}

int main(){
  while(scanf("%d%d%d",&N,&k,&m)==3 && (N+k+m)){
    q.clear();
    for(int i=0;i<N;++i) q.pb(i+1);
    int p1=0,p2=N-1;
    while(N>0){
      int kk=gCCW(p1);
      int t=gCW(p2);
      p1=(kk+1)%q.size();
      p2=t-1;
      if(p2<0)p2=q.size()-1;
      if(N!=q.size())printf(",");
      if(kk!=t){
        printf("%3d%3d", q[kk],q[t]);
      }else{
        printf("%3d", q[kk]);
      }
      q[kk]=q[t]=-1;
      N--;
      if(t!=kk){
        N--;
      }
    }
    puts("");
  }
}
