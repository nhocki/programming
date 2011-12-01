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
  int nums[3];
  map<char, int>m;
  for(int i=0;i<3;++i){
    cin >> nums[i];
    m['A' + i] = i;
  }
  sort(nums, nums + 3);
  string order;
  cin >> order;
  for(int i=0;i<2;++i){
    printf("%d ", nums[m[order[i]]]);
  }
  printf("%d\n", nums[m[order[2]]]);
  return 0;
}