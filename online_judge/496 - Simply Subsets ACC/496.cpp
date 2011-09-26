#include <algorithm>
#include <iostream>
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
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <cassert>
#include <set>

#define pb(x) push_back(x)
#define sz size()
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main(){
  string l1,l2;
  while(getline(cin,l1) && getline(cin,l2)){
    set<int>f,s;
    int t;
    stringstream ss(l1.c_str()); 
    while(ss>>t) f.insert(t);
    ss.clear();
    ss.str(l2.c_str());
    while(ss>>t) s.insert(t);
    set <int> tmp;
    set_intersection(f.begin(),f.end(),s.begin(),s.end(), inserter(tmp, tmp.begin()));
    bool a,b;
    a = tmp==f;
    b = tmp==s;
    if(a&&b){
      puts("A equals B");   
    }else if(a){
      puts("A is a proper subset of B");
    }else if(b){
      puts("B is a proper subset of A");
    }else if(tmp.sz){
      puts("I'm confused!");
    }else{
      puts("A and B are disjoint");
    }

  }
  return 0;
}
