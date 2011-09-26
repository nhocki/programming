/**
* Nicolás Hock Isaza
* Name: 10656.cc
* Created On: 01 Jun 2009
*/

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
  int N;
  while(scanf("%d",&N)==1 && N){
    int k;
    vector<int> v;
    for(int i=0;i<N;++i){
      scanf("%d",&k);
      if(k!=0) v.push_back(k);
    }
    if(v.size()==0) puts("0");
    else{
      printf("%d",v[0]);
      for(int i=1;i<v.size();++i) printf(" %d",v[i]);
      puts("");
    }
  }
  return 0;
}
