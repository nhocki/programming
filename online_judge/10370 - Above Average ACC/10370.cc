/**
* Nicolás Hock Isaza
* Name: 10370.cc
* Created On: 15 Mar 2009
*/

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int C;
  scanf("%d",&C);
  while(C--)
  {
    int N;
    double sum=0,total=0;
    scanf("%d",&N);
    vector<int>g(N,0);
    for(int i=0;i<N && scanf("%d",&g[i])==1;sum+=g[i++]);
    sum/=N;
    for(int i=0;i<N;total+=(sum<g[i++]));
    printf("%.3f%\n",(total/N)*100);
  }
  return 0;
}
