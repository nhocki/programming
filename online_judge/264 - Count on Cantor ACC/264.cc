/**
* Provincia Express
* Name: 264.cc
* Created On: 14 Apr 2009
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main (){
  long long num;
  while(  scanf("%lld",&num)!=EOF){
    long long n=1,i;
    for(;((n*(n+1))/2 < num);n++);
    i=((n*(n+1))/2)-num+1;
    if(n%2) printf("TERM %lld IS %lld/%lld\n",num,i,n-i+1);
    else printf("TERM %lld IS %lld/%lld\n",num,n-i+1,i);
  }
  return 0;
}
