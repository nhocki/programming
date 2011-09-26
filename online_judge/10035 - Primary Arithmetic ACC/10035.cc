/**
* Nicolás Hock Isaza
* Name: 10035.cc
* Created On: 26 Feb 2009
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
#define D_m(m,rows,cols) for(int i=0;i<rows;cout<<endl,++i) for(int j=0;j<cols;) cout <<m[i][j++]<<"  "
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
  string f,s;

  int ans=0;
  for (;cin>>f>>s && (f[0]+s[0]-96);ans=0)
  {
    int n=f.size(), m=s.size();
    int carry=0,dif=n-m;
    dif = abs(dif);
    string &a=(f.size()>s.size())?s:f;
    for (int i=0;i<dif;++i) a = "0"+a;
    for (int i=f.size()-1;i>=0;--i)
    {
      if (f[i]+s[i]+carry - 96 >9) carry=1,ans++;
      else carry=0;
    }
    if (ans>1) printf("%d carry operations.\n",ans);
    else if (ans==1) printf("1 carry operation.\n");
    else printf("No carry operation.\n");
  }
  return 0;
}
