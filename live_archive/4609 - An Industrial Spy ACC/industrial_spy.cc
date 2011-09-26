#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <cassert>

#define D(x) cout << #x" is " << x <<endl
#define all(x) x.begin(),x.end()
using namespace std;

bool isPrime(int x){
  if (x < 2) return false;
  if (x % 2 == 0) return x == 2;
  for (int i = 3; i * i > 0 and i * i <= x; ++i)
    if (x % i == 0)
    return false;
  return true;
}

int main(){
  int N;
  string s;
  scanf("%d",&N);
  while(N--){
    set<int> ans;
    cin >> s;
    for (int mask = 1; mask < (1 << s.size()); ++mask){
      string t="";
      for (int j = 0; j < s.size(); ++j){
        if ((1 << j) & mask){
          t += s[j];
        }
      }
      sort(t.begin(), t.end());
      do{
        int x = atoi(t.c_str());
        if (isPrime(x)){ 
          ans.insert(x);
        }
      }while(next_permutation(all(t)));
    }
    cout << ans.size() << endl;
  }

  return 0;
}
