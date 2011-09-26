/**
* Nicolás Hock Isaza
* Name: 11512.cc
* Created On: 12 Apr 2009
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

#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define sz size()

using namespace std;

int main()
{
  int N;
  cin>>N;
  while(N--)
  {
    string l,line;
    cin>>l;
    line = l;
    vector<string> subs;
    subs.push_back(line);
    while(line.size()>0) line.erase(line.begin()),subs.push_back(line);
    sort(all(subs));

    string max="";
    int total=0;
    for(int i=1;i<subs.size();++i)
    {
      int j;
      for(j=0; j<subs[i].sz && j<subs[i-1].sz && subs[i][j]==subs[i-1][j]; ++j);
      if(j>0){
        line = subs[i].substr(0,j);
        if(line==max) total++;
        else if(j>max.size() || (j==max.size() && line < max)) max = line, total=2;
      }
    }
    if(max=="") cout << "No repetitions found!\n";
    else cout<< max << " "<<total<<endl;
  }
  return 0;
}
