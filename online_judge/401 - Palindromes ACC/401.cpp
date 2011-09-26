
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

using namespace std;

#define D(x) cout<<__LINE__<<"  "#x" is "<<x<<endl
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

map<char,char> rev;

bool isPal(string k){
  string t = k;
  reverse(all(t));
  return t==k;
}

bool isMir(string k){
  int j = k.size()-1;
  for(int i=0;i<=j-i;++i)
    if(k[i]!=rev[k[j-i]]) return false;
  return true;
}

int main(){
  rev['A']='A';
  rev['E']='3';
  rev['H']='H';
  rev['I']='I';
  rev['J']='L';
  rev['L']='J';
  rev['M']='M';
  rev['O']='O';
  rev['S']='2';
  rev['T']='T';
  rev['U']='U';
  rev['V']='V';
  rev['W']='W';
  rev['X']='X';
  rev['Y']='Y';
  rev['Z']='5';
  rev['1']='1';
  rev['2']='S';
  rev['3']='E';
  rev['5']='Z';
  rev['8']='8';

  string line;
  while(cin >> line){
    bool pal = isPal(line);
    bool mir = isMir(line);
    if(pal && mir){
      cout << line <<" -- is a mirrored palindrome."<<endl;
    }else if(pal){
      cout << line <<" -- is a regular palindrome."<<endl;
    }else if(mir){
      cout << line <<" -- is a mirrored string."<<endl;
    }else{
      cout << line <<" -- is not a palindrome."<<endl;
    }
    puts("");
  }
}
