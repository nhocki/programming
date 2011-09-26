#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <cassert>

#define D(x) cout << #x" is " << x <<endl;
#define all(x) x.begin(),x.end()
using namespace std;

typedef pair<int, int> point;

int di[] = {-1, -1, +0, +1, +1, +0};
int dj[] = {+0, -1, -1, +0, +1, +1};

const int MAXN = 10005;
int ans[MAXN];
int times[6];
map<point, int> num;

void solve(){
  vector<point> points;
  points.push_back(point(0, 0));
  int ring = 1;
  point cur = point(0, 0);
  while (points.size() < 10000){
    cur.first += di[5];
    cur.second += dj[5];
    points.push_back(cur);
  //arriba
    for (int k = 0; k < ring - 1; ++k){
      cur.first += di[0];
      cur.second += dj[0];
      points.push_back(cur);
    }
  //resto
    for (int side = 1; side < 6; ++side){
      for (int k = 0; k < ring; ++k){
        cur.first += di[side];
        cur.second += dj[side];
        points.push_back(cur);
      }
    }
    ring++;
  }

  memset(times, 0, sizeof times);

  num[points[0]] = 1;
  ans[0] = 1;
  times[1] = 1;

  for (int i = 1; i <= 10000; ++i){
    set<int> possible;
    for (int j = 1; j < 6; ++j) possible.insert(j);

  //borrar vecinos
    for (int k = 0; k < 6; ++k){
      point p = points[i];
      p.first += di[k];
      p.second += dj[k];
      possible.erase( num[ p ] );
    }

    if (possible.size() > 1){
      int best = INT_MAX, which = -1;
      for (set<int>::iterator j = possible.begin(); j != possible.end(); ++j){
        if (times[*j] < best){
          best = times[*j];
          which = *j;
        }
      }
      possible.clear();
      possible.insert(which);
    }
    int placed = *possible.begin();
    num[points[i]] = placed;
    times[placed]++;

    ans[i] = placed;
  }
}

int main(){
  solve();
  int C;
  cin >> C;
  while (C--){
    int n; cin >> n;
    cout << ans[--n] << endl;
  }
  return 0;
}
