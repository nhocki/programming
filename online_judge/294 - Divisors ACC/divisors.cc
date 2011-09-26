#include <cstdio>
#include <iostream>

#define D(x) std::cout << #x " is " << x << std::endl


int countDiv(int n)
{
  int divs=0,t=0,i;
  for (i=1; i*i<=n; i++)
    if (n%i == 0)
    divs+=2;
  t=i-1;
  if ((t*t)==n) divs--;
  return divs;
}

int main()
{
  int n,i,men,may,divs=0,num=0,j,temp=0;
  for (i=0,scanf("%d",&n);i<n;printf("Between %d and %d, %d has a maximum of %d divisors.\n",men,may,num,divs),++i)
  {
    for (scanf("%d%d",&men,&may),j=men,temp=0,num=0,divs=0;j<=may;++j)
    {
      temp = countDiv(j);
      if (divs<temp) divs=temp,num=j;

    }
  }
  return 0;
}
