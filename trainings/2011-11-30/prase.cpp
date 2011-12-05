#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define D(x) cout << #x "  is  = " << x << endl

int main(){
  int N, alerts = 0;
  cin >> N;
  map<string, int> child_pieces;
  string kid;
  for(int i=1;i<=N;++i){
    cin >> kid;
    child_pieces[kid]++;
    if(i - child_pieces[kid] < child_pieces[kid] - 1) alerts++;
  }
  cout << alerts << endl;
  return 0;
}