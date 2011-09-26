/**
* Nicolás Hock Isaza
* Name: 11417.cpp
* Created On: 29 Mar 2009
*/

#include <cstdio>

using namespace std;

//Segun "The Art of Programming Contests" es la forma mas rapida del GCD.
int GCD(int a,int b) { 
  while (b > 0) { 
    a = a % b; 
    a ^= b;
    b ^= a;
    a ^= b;
  }
  return a; 
}

int main()
{
  int N;
  while(scanf("%d",&N)==1 && N)
  {
    int G=0;
    for(int i=1;i<N;++i)
      for(int j=i+1;j<=N;++j)
      G+=GCD(i,j);
    printf("%d\n",G);
  }
  return 0;
}
