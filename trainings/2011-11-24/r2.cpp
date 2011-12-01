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
  int R1, S;
  cin >> R1 >> S;
  int R2 = 2*S - R1;
  printf("%d\n", R2);
  return 0;
}