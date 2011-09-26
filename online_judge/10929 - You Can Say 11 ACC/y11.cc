#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <string>
#include <math.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define mem(i,n) memset(i,n,sizeof(i))
#define fo(i,a) for(i=0;i<a;++i)
#define fo2(i,a,b) for(i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define yourself size()
#define hock c_str()
typedef int nicolas;
typedef string challenge;
#define entry_point cin
#define D(x) cout << #x " is " << x << endl



nicolas main()
{
  challenge don_t_challenge,no="not ";
  for (nicolas HOCK=0;getline(entry_point,don_t_challenge) && don_t_challenge!="0";)
  {
    for(nicolas hck=0;hck<don_t_challenge.yourself;++hck)
    {
      if (hck%2)HOCK+=(don_t_challenge[hck]-48);
      else HOCK-=(don_t_challenge[hck]-48);
    }
    printf("%s is %sa multiple of 11.\n",don_t_challenge.hock, HOCK%11==0? "":no.hock );
    HOCK=0;
  }
  return 0;
}
