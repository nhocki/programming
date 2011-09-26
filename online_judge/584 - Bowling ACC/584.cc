// Nicolas Hock Isaza
// Number: 584
// Title: Bowling
// OJ: Online Judge

using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl
#define mem(i,n) memset(i,n,sizeof(i))
#define fo(i,a) for(i=0;i<a;++i)
#define fo2(i,a,b) for(i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int decode(char c)
{
  if (c!='/' && c!='X') return c-'0';
  return 10;
}

int main()
{
  string in="";
  int sum=0, temp =0;
  double t=0;
  for (char c;scanf("%c",&c) && c!='G'; )
  {
    if (c!=' ')
    {
      if(c=='\n') //Lei la palabra!
      {
        //CODIGO
        for(int i=0;i<in.lng && t<10;++i)
        {
          if(in[i]=='/')
          {
            temp=(10+decode(in[i+1])-decode(in[i-1]));
            t+=0.5;
          }
          else if (in[i]=='X')
          {
            t++;
            if (in[i+2]!='/')
              temp=(10+decode(in[i+1])+decode(in[i+2]));
            else
              temp=20;
          }
          else
          {
            t+=0.5;
            temp=decode(in[i]);
          }
          sum+=temp;
        }
        ///FIN CODIGO
        in="";
        t=0;
        cout <<sum<<endl;
        sum=0;
      }
      else
        in+=c;
    }
  }
  return 0;
}
