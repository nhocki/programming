#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <iterator>
#include <sstream>
#include <fstream>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define toggle(x) ((x=='W') ? 'B' : 'W')

struct board{
  short F,D;
  string s;
};

bool good (const board &b){
  const string &str = b.s;
  string::size_type first = str.find_first_of("B");
  string::size_type firstW = str.find_first_of("W", first);
  if(first == string::npos or firstW == string::npos) return true;
  string::size_type last = str.find_last_of("B");
  if(last == first) return true;
  if(firstW == string::npos) return true;
  if(firstW < last) return false; 
  return true;
}

int bfs(string &start, int f){
  board curr,a1;
  curr.s = start;
  curr.F = f;
  curr.D = 0;
  set<string> s;
  s.insert(start);
  queue<board> q;
  q.push(curr);
  while(q.size()){
    curr = q.front();
    q.pop();
    if(good(curr)) return curr.D;
    if(curr.D < 9){
      curr.D++;
      a1=curr;
      if(a1.F > 0 ){
    //Se mueve hacia atras
        swap(a1.s[a1.F], a1.s[a1.F-1]);
        a1.F--;
        if(!s.count(a1.s))
          q.push(a1), s.insert(a1.s);
      }
      a1 = curr;
      if(a1.F + 1 < a1.s.size()){
    //Se mueve hacia adelante
        swap(a1.s[a1.F], a1.s[a1.F + 1]);
        a1.F++;
        if(!s.count(a1.s)){
          q.push(a1);
          s.insert(a1.s);
        }
      }
      a1 = curr;
      if(a1.F > 1){
    //Salta hacia atras
        swap(a1.s[a1.F], a1.s[a1.F - 2]);
        a1.s[a1.F] = toggle(a1.s[a1.F]);
        a1.F=a1.F-2;
        if(!s.count(a1.s))
          q.push(a1), s.insert(a1.s);

      }
      a1 = curr;
      if(a1.F + 2 < a1.s.size()){
    //Salta hacia adelante
        swap(a1.s[a1.F], a1.s[a1.F + 2]);
        a1.s[a1.F] = toggle(a1.s[a1.F]);
        a1.F=a1.F+2;
        if(!s.count(a1.s))
          q.push(a1), s.insert(a1.s);
      }
    }
  }
  return -1;
}

int main(){
  int C = 1;
  string line;
  while(cin >> line && line[0]!='-'){
    int t = line.find("F");
    printf("%d. %d\n",C++,bfs(line, t));
  }
  return 0;
}
