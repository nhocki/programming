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

int ind = 1;
map<string, int> m;

void f(string prefix, int size){
  if(prefix.size() == size){
    m[prefix] = ind++;
    return ;
  }

  char last;

  if(prefix == ""){
    last = 'a' - 1;
  }
  else{
    last = prefix[prefix.size() - 1];
  }

  for(char i = last + 1; i <= 'z'; ++i){
    f(prefix + i, size);
  }
}

int main(){
  for(int i = 1; i<=5; ++i){ f("", i); }

  string in;
  while(cin >> in){
    printf("%d\n", m[in]);
  }
  return 0;
}
