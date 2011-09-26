/**
* Nicolás Hock Isaza
* Name: 485.cc
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

const int N = 210;
string choose[N+1][N+1];

string sum(string a, string b, int base=10)
{
  if(a.size()<b.size()) swap(a,b);
  a="0"+a;
  string res= a;
  int N=a.size(), M=b.size(),j=M-1;
  bool carry = 0;
  for(int i=N-1;i>=0;--i)
  {
    int t1 = a[i]-48, t2=0;
    if(j>=0) t2=b[j]-48, j--;
    int temp = t1+t2+carry;
    res[i]=temp%base + 48;
    carry=(temp>=base);
  }
  for(int i=0;i<res.size();++i)
  {
    if(res[i]!='0') {res=res.substr(i);break;}
    else if (i+1==res.size()) res='0';
  }
  return res;
}

int main()
{
    /* Binomial coefficients */
  for (int i=0; i<=N; ++i) choose[i][0] = choose[i][i] = "1";
  for (int i=1; i<=N; ++i)
  for (int j=1; j<i; ++j){
    choose[i][j] = sum(choose[i-1][j-1],choose[i-1][j]);
  }
  bool fin = false;
  for(int i=0;i<N && !fin;++i)
  {
    if(choose[i][0][0]=='0') choose[i][0]=choose[i][0].substr(1);
    cout<<choose[i][0];
    for(int j=1;j<i+1;++j)
    {
      if(choose[i][j][0]=='0') choose[i][j]=choose[i][j].substr(1);
      if(choose[i][j].size()>=61) {fin = true; }
      cout<<" "<<choose[i][j];
    }
    puts("");
  }

  return 0;
}
