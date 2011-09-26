#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

double r1,r2,res;
const double PI = 2*acos(0);

int main()
{
  int N;
  string in;
  cin >> N;
  getchar();
  while(N-- && cin>>r1)
    if (cin.peek()!='\n') cin >> r2,printf("%.4lf\n",2*PI*abs(r1)*abs(r2));
    else printf("%.4lf\n",(PI*r1*r1)/8);
  return 0;
}
