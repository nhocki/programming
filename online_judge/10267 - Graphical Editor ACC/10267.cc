/**
* Nicolás Hock Isaza
* Name: 10267.cc
* Created On: 10 Apr 2009
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#define SP(a,b) {typeof (a) t=b;b=a;a=t;}

using namespace std;

void fill_region(vector<string>& img, int x, int y, char c, char m) {
    //If the old color == new one, do nothing!
    //if the actual color != old one, do nothing!
  if (img[y][x]!=m || img[y][x]==c) return;

  img[y][x]=c;

  if ((y-1)>=0) fill_region(img, x  , y-1, c, m);
  if ((x-1)>=0) fill_region(img, x-1, y  , c, m);
  if ((x+1)<img[y].size()) fill_region(img, x+1, y  , c, m);
  if ((y+1)<img.size())    fill_region(img, x  , y+1, c, m);
}

int main ()
{
  vector<string> image;
  int m, n;
  char C;
  while (scanf("%c", &C)) {
    if (C=='X') break;

    switch(C) {
      case 'C' :
      case 'I' : {
        scanf("%d %d", &m, &n); //Keep in mid that M=cols N = rows!
        string t(m,'O');
        image=vector<string>(n,t);
        break;
      }

      case 'L' : {
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c); //Remember you read X and Y
        image[y-1][x-1]=c;                     //But use Y and X!
        break;
      }

      case 'V' : {
        int x, y1, y2, ytmp;
        char c;
        scanf("%d %d %d %c", &x, &y1, &y2, &c);
        if (y1>y2) SP(y1,y2); //Remember to swap if y1>y2!
        for (int i=y1-1; i!=y2; ++i)
          image[i][x-1]=c;
        break;
      }

      case 'H' : {
        int x1, x2, xtmp, y;
        char c;
        scanf("%d %d %d %c", &x1, &x2, &y, &c);
        if (x1>x2) SP(x1,x2); //Obviusly remember to swap here too!
        for (int i=x1-1; i!=x2; ++i)
          image[y-1][i]=c;
        break;
      }

      case 'K' : {
        int x1, y1, x2, y2, xtmp, ytmp;
        char c;
        scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
        for (int i=y1-1; i!=y2; ++i)
          for (int j=x1-1; j!=x2; ++j)
          image[i][j]=c;
        break;
      }

      case 'F' : {
        int x, y;
        char c, match;
        scanf("%d %d %c", &x, &y, &c);
        match=image[y-1][x-1];
      //c = new color
      //match the old one
      //Flood fill method
        fill_region(image, x-1, y-1, c, match);
        break;
      }

      case 'S' : {
        string fn;
        cin >> fn;
        cout << fn << endl;
        for (int i=0; i<image.size(); ++i)
          cout << image[i] << endl;
        break;
      }

      default  : { break;} //If the line is wrong. Ignore it
    }
  }
  return 0;
}

