#include <cstdio>
#include <vector>

using namespace std;

vector<long long> fib;

void makeFib(int to)
{
  for (int i=fib.size();i<=to+1;++i)
    fib.push_back(fib[i-1]+fib[i-2]+1);
}

int main()
{
  fib.push_back(0);
  fib.push_back(1);
  int n,last=0;
  for (; scanf("%d",&n) && n!=-1; printf("%lld %lld\n",fib[n],fib[n+1]))
  {
    if (n>last)
    {
      makeFib(n);
      last = n;
    }
  }
  return 0;
}
