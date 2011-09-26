/**
* Nicolás Hock Isaza
* Name: 534.cc
* Created On: 08 May 2009
*/

#include<iostream>
#include<iterator>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int d[202][202];

struct point{
  int x, y;
  point(){}
  point(int X, int Y):x(X),y(Y){}
};

int distsq (const point &p1, const point &p2){
  return ((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main()
{
  int caso = 1, n,id=0;
  while(scanf("%d",&n)==1 && n){
    vector<point> points;
    for(int i=0;i<n;++i){
      int xx, yy;
      cin>>xx>>yy;
      points.push_back(point(xx,yy));
    }
    for(int i=0;i<points.size();++i){
      for(int j=i+1;j<points.size();++j){
        d[i][j]=d[j][i]=distsq(points[i],points[j]);
        d[i][i]=d[j][j]=0.0;
      }
    }
    int N = points.size();
    for(int k=0; k<N; ++k)
      for(int i=0; i<N; ++i)
      for(int j=0; j<N; ++j)
      d[i][j]=min(d[i][j],max(d[i][k], d[k][j]));

    printf("Scenario #%d\n",caso++);
    printf("Frog Distance = %0.3f\n\n",sqrt(d[0][1]));
  }
  return 0;
}
