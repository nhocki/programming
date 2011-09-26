/**
* Nicolás Hock Isaza
* Name: 10783.cc
* Created On: 15 Mar 2009
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int C,k=1;
  cin>>C;
  for(int k=1,total=0;k<=C;printf("Case %d: %d\n",k++,total),total=0)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b) swap(a,b);
    for(int i=a;i<=b;++i)
      total+=(i%2)?i:0;
  }
  return 0;
}
