#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
  int t, n;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    vector<string>v(n);
    for(int i=0;i<n;++i){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool valid = true;
    for(int i=0;i+1<n && valid ;++i){
      if(v[i+1].substr(0, v[i].size()) == v[i]) valid = false;
    }
    if(valid) puts("YES");
    else puts("NO");
  }
  return 0;
}
