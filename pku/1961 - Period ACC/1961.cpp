#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

vector<int> kmp_table(string &P){
  int i = 0, j = -1;
  int m = P.size();
  vector<int> f(m+1);
  f[0] = -1;
  while( i < m ){
    while(j>=0 and P[i] != P[j]) j = f[j];
    f[++i] = ++j;
  }
  return f;
}

int main(){
  int T, C=1;
  string s,t;
  while(scanf("%d", &T)){
    if(T==0) break;
    printf("Test case #%d\n", C++);
    cin >> s;
    vector<int>pi = kmp_table(s);
    for(int i=1;i<=T;++i)
      if(pi[i] > 0)
        if(i % (i-pi[i]) == 0)
          printf("%d %d\n", i, i/(i-pi[i]));
    puts("");
  }  
  return 0;
}
