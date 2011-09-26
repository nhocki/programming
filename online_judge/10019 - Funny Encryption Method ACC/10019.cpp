#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
  int N,M;
  scanf("%d",&N);
  while(N--){
    string t;
    cin >> t;
    int d,h;
    sscanf(t.c_str(), "%x", &h);
    sscanf(t.c_str(), "%d", &d);
    int dec = __builtin_popcount(d);
    int hex = __builtin_popcount(h);
    printf("%d %d\n",dec,hex);
  }
  return 0;
}
