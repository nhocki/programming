/**
* Nicolás Hock Isaza
* Name: 11244.cc
* Created On: 01 Apr 2009
*/

#include <iostream>
#include <cstdio>

#define mem(i,n) memset(i,n,sizeof(i))

using namespace std;

char m[103][103];

int main()
{
  while(true)
  {
    int N,M;
    scanf("%d%d",&N,&M);
    if(!(N+M)) break;
    mem(m,46);
    for(int i   = 1;i<=N;++i)
      for(int j = 1;j<=M;++j)
      cin>>m[i][j];

    int total   = 0;
    for(int i   = 1;i<=N;++i)
    {
      for(int j = 1;j<=M;++j)
      {
        if(m[i][j]=='*')
        {
          if(m[i][j-1] == '*')   continue;
          if(m[i-1][j-1] == '*') continue;
          if(m[i-1][j] == '*')   continue;
          if(m[i-1][j+1] == '*') continue;
          if(m[i][j+1] == '*')   continue;
          if(m[i+1][j+1] == '*') continue;
          if(m[i+1][j] == '*')   continue;
          if(m[i+1][j-1] == '*') continue;
          total++;
        }
      }
    }
    printf("%d\n",total);
  }
  return 0;
}
