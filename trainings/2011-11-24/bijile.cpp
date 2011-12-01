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
  int chess[] = {1, 1, 2, 2, 2, 8}, tmp;
  
  for(int i=0;i<6;++i){
    cin >> tmp;
    chess[i] -= tmp;
  }
  for(int i=0;i<5;++i){
    printf("%d ", chess[i]);
  }
  printf("%d\n", chess[5]);
  return 0;
}