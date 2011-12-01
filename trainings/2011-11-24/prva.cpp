#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define D(x) cout <<#x" is "<< x << endl;
#define INF 2<<30-1

vector<string>g;
int R,C;

bool inline isFirstLetterUp(int i, int j){
  if(g[i][j] == '#') return false;
  if(g[i-1][j] != '#') return false;
  if(g[i+1][j] == '#') return false;
  return true;
}

bool inline isFirstLetterLeft(int i, int j){
  if(g[i][j] == '#') return false;
  if(g[i][j-1] != '#') return false;
  if(g[i][j+1] == '#') return false;
  return true;
}

void print_graph(){
  for(int i=0;i<=R + 1;++i){
    cout << g[i] << endl;
  }
}

int main(){
  scanf("%d%d", &R, &C);
  g.assign(R+4, string(C + 4, '#'));
  string temp;
  for(int i=1;i<=R;++i){
    cin >> temp;
    g[i] = "#" + temp + "#";
  }
  
  // print_graph();
  
  set<string> words;
  
  for(int i=1;i<=R;++i){
    for(int j=1;j<=C;++j){
      if(g[i][j] != '#' and isFirstLetterLeft(i, j)){
        string word = string(1, g[i][j]);
        for(int y = j+1;y<=C;++y){
          if(g[i][y]!='#'){ word += string(1, g[i][y]); }
          else{ break; }
        }
        words.insert(word);
      }
      if(g[i][j] != '#' and isFirstLetterUp(i, j)){
        string word = string(1, g[i][j]);
        for(int x = i+1;x<=R;++x){
          if(g[x][j]!='#'){ word += string(1, g[x][j]); }
          else{ break; }
        }
        words.insert(word);
      }
    }
  }
  cout << *(words.begin()) << endl;
  return 0;
}