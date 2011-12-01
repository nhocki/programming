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
  int N;
  cin >> N;
  int mid = (N+2) / 2;
  int oth = mid + (N%2 != 0);
  printf("%d\n", mid * oth);
  return 0;
}