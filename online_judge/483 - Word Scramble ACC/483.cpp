/**
* Nicolás Hock Isaza
* Name: 483.cc
* Created On: 14 Apr 2009
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

#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl
#define all(x) x.begin(),x.end()

using namespace std;

int main()
{
  string line;
  while(getline(cin,line))
  {
    string res="",word="";
    for(int i=0;i<line.size();++i)
    {
      if(line[i]==' ')
      {
        reverse(all(word));
        word+=' ';
        res+=word;
        word="";
      }
      else word+=line[i];
    }
    reverse(all(word));
    res+=word;
    printf("%s\n",res.c_str());
  }
  return 0;
}
