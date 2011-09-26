#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

int s[30], real[30], c[30][30],N;


//Finds the LCS betwen s (global) and n (local) where s.size() = n.size() = n
int lcs(vector<int> &n){
  for(int i=0;i<=N+1;++i) c[i][0]=c[0][i]=0;
  for(int i=1;i<=N;++i)
    for(int j=1;j<=N;++j)
    if(s[i]==n[j]) c[i][j]=c[i-1][j-1]+1;
  else c[i][j]=max(c[i-1][j],c[i][j-1]);
  return c[N][N];
}

//Returns the actual sequence between s and n
vector<int> backTrackLCS(vector<int> &n, int i, int j){
  vector<int> r;
  if(i==0 or j==0) return r;
  if(s[i]==n[j]){
    r = backTrackLCS(n,i-1,j-1);
    r.push_back(s[i]);
    return r;
  }
  if(c[i][j-1]<c[i-1][j]) return backTrackLCS(n,i-1,j);
  return backTrackLCS(n,i,j-1);
}

int main(){
  scanf("%d", &N);
  for(int i=1;i<=N;++i){
    scanf("%d", &real[i]);
    s[real[i]]=i;
  }
  vector<vector<int> > allst;
  int t;
  while(scanf("%d",&t)==1){
    vector<int> st(N+2,-1);
    st[t]=1;
    for(int i=2;i<=N;++i){
      scanf("%d", &t);
      st[t]=i;
    }
    allst.push_back(st);
  }
  for(int i=0;i<allst.size();++i){
    printf("%d\n", lcs(allst[i]));
  // vector<int> ss = backTrackLCS(allst[i],N,N);
  // for(int j=0;j<ss.size();++j) printf("%d ", ss[j]);
  // puts("");
  }
  return 0;
}
