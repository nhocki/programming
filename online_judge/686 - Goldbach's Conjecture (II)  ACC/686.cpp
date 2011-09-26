#include <cstdio>
#include <vector>

using namespace std;

const int _max=32769; //2^15 + 1
bool prim[_max];

void criba()
{
  memset(prim,true,sizeof(prim));
  prim[0]=prim[1]=false;
  for(int i=4;i<_max;i+=2) prim[i]=false;

  for(int i=3;i<_max;i+=2) if(prim[i])for(int j=i*i;j<_max;j+=i) prim[j]=false;
}

int count(int k)
{
  int mid = k/2, cont=0;
  for (int i=2;i<=mid;++i) if (prim[i]) cont+=prim[k-i];
  return cont;
}

int main()
{
  criba();
  for(int N;scanf("%d",&N) && N;printf("%d\n",count(N)));
  return 0;
}
