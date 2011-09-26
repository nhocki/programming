
/**
* Provincia Express
* Name: 880.cc
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

typedef long long ll;

int main (){
  long long num;
  while(  scanf("%lld",&num)!=EOF){
    long long i;
    long double n=1.0;

    n=(-1.0+sqrt(1+8*num))/2.0;
    if(n != (ll)n) n = (ll)(n+1.0);

    i=(((ll)n*((ll)n+1))/2)-num+1;
    printf("%lld/%lld\n",i,(ll)n-i+1);
  }
  return 0;
}
