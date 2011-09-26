#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


#define D(x) std::cout << #x " is " << x << std::endl

const int _max=1000000;
typedef unsigned long long ull;
bool prim[_max];

void criba()
{

  memset(prim,true,sizeof(prim));
  prim[0]=prim[1]=false;
  for(ull i=4;i<_max;i+=2) prim[i]=false;

  for(ull i=3;i<_max;i+=2) if(prim[i])for(ull j=i*i;j<_max;j+=i) prim[j]=false;
}

int main()
{
  criba();
  for(int N,a,b;scanf("%d",&N)==1 && N!=0;)
  {
    int mid = N/2;
    for (int i=3;i<=mid;i+=2)
    {
      if (prim[i] && prim[N-i])
      {
        a=i,b=N-i;
        break;
      }

    }
    printf("%d = %d + %d\n",N,a,b);
  }
  return 0;
}
