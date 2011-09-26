/**
* Nicolás Hock Isaza
* Name: 424.cc
* Created On: 07 Jun 2009
*/

#include<inttypes.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

using namespace std;

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {                      \
for(int __i=0; __i<rows; cout<<endl, ++__i)     \
  for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()


string sum(string a,string b, int base=10){
  if(a.sz<b.sz) return sum(b,a);
  string res=a;
  int N=a.sz,M=b.sz,j=M-1;
  bool carry=0;
  for(int i=N-1;i>=0;--i){
    int t1=a[i]-48,t2=0;
    if(j>=0) t2=b[j]-48,j--;
    int temp = t1+t2+carry;
    res[i]=temp%base + 48;
    carry=(temp>=base);
  }
  if(carry) res="1"+res;
  return res;
}


int main(){
  string a,b;
  getline(cin,a);
  b=a;
  while(getline(cin,a) && a!="0")
    b = sum(a,b);
  cout<<b<<endl;
  return 0;
}
