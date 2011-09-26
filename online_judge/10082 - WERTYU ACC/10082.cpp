/**
* Nicolás Hock Isaza
* Name: 10082.cc
* Created On: 27 Mar 2009
*/

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
#include <set>

#define sz size()
#define lng length()
#define cs c_str()

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int main()
{
  string all = " 1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./",res="";
  while(getline(cin,res))
  {
    string r="";
    for(int i=0;i<res.sz;++i){
      if (res[i]==' ') {r+=' ';continue;}
      string::size_type loc = all.find(res.substr(i,1));
      r+=all[loc-1];
    }
    printf("%s\n",r.cs);
  }
  return 0;
}
