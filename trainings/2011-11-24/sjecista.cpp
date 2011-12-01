#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

#define D(x) cout <<#x" is "<< x << endl;
#define INF 2<<30-1

int main(){
  int n, res = 0;
  cin >> n;
  for(int i=2; i<n;++i){
    res += (i-1) * (n-1-i);
  }
  res *= n;
  res /= 4;
  printf("%d\n", res);
  return 0;
}