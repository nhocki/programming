/**
* Nicolás Hock Isaza
* Name: bridge.cc
* Created On: 24 Apr 2009
*/

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

#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define sz size()

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

map<char,int> m,pintas;

//Club < diamond < spade < heart
struct card{
  char c,p;
  card() {}
  card(char C, char P): c(C) , p(P) { }
};

struct player{
  string pos;
  vector<card>cards;
  int next;
  player(){}
  player(string p):pos(p){
    next = m[pos[0]];
  }

  friend ostream& operator<<(ostream& o, player p)
  {
    printf("%c:",p.pos[0]);
    for(int i=0;i<p.cards.sz;++i)
      printf(" %c%c",p.cards[i].p, p.cards[i].c);
    return o<<"\n";
  }
};

bool cmp(card a, card b)
{
  if(a.p != b.p) return pintas[a.p]>pintas[b.p];
  int t = m[a.c], s=m[b.c];
  if(t == 0 && s == 0) return a.c < b.c;
  return t<s;
}

int main()
{

  string first;

  m['N']=1;
  m['E']=2;
  m['S']=3;
  m['W']=0;

  m['T']=10;
  m['J']=11;
  m['Q']=12;
  m['K']=13;
  m['A']=14;

  pintas['H']=1;
  pintas['S']=2;
  pintas['D']=3;
  pintas['C']=4;

  char pp='N';


  while(cin>>pp && pp!='#'){

    vector<player>players(4);
    players[0] = player("North");
    players[1] = player("East");
    players[2] = player("South");
    players[3] = player("West");


    getline(cin,first); //Get the rubbish

    int f = m[pp]; //Who starts?

    getline(cin,first);
    for(int i=0;i<first.sz-1;i+=2)
    {
      char C,P;
      P = first[i];
      C = first[i+1];
      players[f].cards.pb(card(C,P));
      f = players[f].next;
    }

    getline(cin,first);
    for(int i=0;i<first.sz-1;i+=2)
    {
      char C,P;
      P = first[i];
      C = first[i+1];
      players[f].cards.pb(card(C,P));
      f = players[f].next;
    }

    for(int i=0;i<players.sz;++i) sort(all(players[i].cards), cmp);

    cout<<players[2];
    cout<<players[3];
    cout<<players[0];
    cout<<players[1];
  //puts("");
  }
  return 0;
}
