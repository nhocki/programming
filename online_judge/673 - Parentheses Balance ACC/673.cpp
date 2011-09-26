/**
* Nicolás Hock Isaza
* Name: 673.cc
* Created On: 21 Aug 2009
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

int main(){
  int N;
  scanf("%d",&N);
  string line;
  getline(cin,line);
  while(N--){
    getline(cin,line);
    stack <char> q;
    if(line =="") {puts("Yes"); continue;}
    bool g = true;
    for(int i=0;i<line.size();++i){
      if(line[i] == '(' || line[i]=='['){
        q.push(line[i]);
      }else if(q.size()){
        char d = line[i];
        char o = q.top();
        q.pop();
        if(!(o+1 == d || o+2==d)){
          g = false;
          break;
        }
      }
      else{
        g = false;
        break;
      }
    }
    if(q.size()) g = false;
    if(g) puts("Yes");
    else puts("No");
  }
  return 0;
}
