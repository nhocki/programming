/**
* Nicolás Hock Isaza
* Name: 499.cc
* Created On: 02 May 2009
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
#define D_v(x) for(int i=0;i<x.size();cerr<<x[i++]<<" ")
#define D_m(m,rows,cols) for(int _i_=0;_i_<rows;cout<<endl,++_i_) for(int _j_=0;_j_<cols;) cout <<m[i][_j_++]<<"  "
#define mem(i,n) memset(i,n,sizeof(i))
#define For(i,a) for(typeof(a) i=0;i<a;++i)
#define For2(i,a,b) for(typeof(a) i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define sz size()
#define lng length()
#define cs c_str()

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int main()
{
  string line,un;
  while(getline(cin,line)){
    map<int, vector<char> > m;
    un = line;
    sort(all(un));
    un.resize(unique(all(un)) - un.begin() );
    while(un.find(" ") != string::npos) un.replace(un.find(" "), 1, "");

    for(int i=0;i<un.size();++i)
      if(isalpha(un[i]))
      m[count(all(line),un[i])].push_back(un[i]);

    int n = m.rbegin()->first;
    if(n!=0){
      for(int i=0;i<m[n].size();++i) printf("%c",m[n][i]);
      printf(" %d\n",n);
    }
  }
  return 0;
}
