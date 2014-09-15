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
#define sz size()
#define lng length()
#define cs c_str()

using namespace std;

string arena[105];

// N - E - S - W
char orientation[] = {'N', 'L', 'S', 'O'};
int orIndex = 0, result = 0;

int x, y;
int N, M, S;
int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};


void move(){
  int nx = x + dx[orIndex];
  int ny = y + dy[orIndex];

  if(nx >=0 && ny >=0 && arena[nx][ny] != '#' && nx < N && ny < M){
    x = nx, y = ny;
    if(arena[x][y] == '*'){
      result++;
      arena[x][y] = '.';
    }
  }
}

void rotate(char c){
  if(c == 'D'){
    orIndex = (orIndex + 1) % 4;
  }else if(c == 'E'){
    orIndex--;
    if(orIndex < 0) orIndex = 3;
  }
}

void findOrIndex(char c){
  for(int i=0; i<4; ++i)
    if(orientation[i] == c){
      orIndex = i;
      break;
    }
}

void printArena(){
  for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
      printf("%c", arena[i][j]);
    }
    puts("");
  }
}

int main(){
  // D => 90 right
  // E => 90 left
  // F => Move forward
  while(scanf("%d%d%d", &N, &M, &S) == 3 && N + S + M > 0){
    orIndex = -1;
    result = 0;

    for(int i=0; i<N; ++i){
      cin >> arena[i];

      for(int j=0; j<M; ++j){
        char c = arena[i][j];
        if(c == 'N' || c == 'L' || c == 'S' || c == 'O'){
          x = i, y = j;
          findOrIndex(c);
          arena[i][j] = '.';
        }
      }

    }

    string moves;
    cin >> moves;

    for(int i=0; i<S; ++i){
      char c = moves[i];
      if( c == 'F') { move(); }
      else { rotate(c); }
    }

    cout << result << endl;

  }
  return 0;
}
