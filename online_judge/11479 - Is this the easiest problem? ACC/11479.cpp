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

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

int main(){
  int N;
  scanf("%d",&N);
  int C=1;
  while(N--){
    long long x,y,z;
    scanf("%lld%lld%lld",&x,&y,&z);
    if((x>=y+z) || (y>=x+z) || (z>=x+y) || (x<=0) || (y<=0) || (z<=0)){
      printf("Case %d: Invalid\n",C++);
      continue;
    }
    bool a12,a23,a31;
    a12=(x==y);
    a23=(y==z);
    a31=(x==z);
    if(a12 && a23){
      printf("Case %d: Equilateral\n",C++);
    }else if(a12 || a23 || a31){
      printf("Case %d: Isosceles\n",C++);
    }
    else{
      printf("Case %d: Scalene\n",C++);
    }
  }
  return 0;
}
