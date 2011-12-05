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

char inline toggle(char c){
  if(c == '#') return '.';
  return '#';
}

void printg(vector<string> &g){
  for(int i=0;i<g.size(); ++i){
    cout << g[i] << endl;
  }
}

int main(){
  int R,C;
  cin >> R >> C;
  vector<string>g;
  string tmp;
  for(int i=0;i<R;++i){
    cin >> tmp;
    g.push_back(tmp);
    reverse(tmp.begin(), tmp.end());
    // Reverse it horizontally
    g[i] = g[i] + tmp;
  }

  for(int i=R-1;i>=0;--i){
    // Reverse it vertically
    g.push_back(g[i]);
  }

  int Ex, Ey;
  cin >> Ex >> Ey;
  g[Ex - 1][Ey - 1] = toggle(g[Ex - 1][Ey - 1]);

  printg(g);
  return 0;
}