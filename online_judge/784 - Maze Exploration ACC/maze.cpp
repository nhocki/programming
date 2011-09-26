/**
 * Nicolás Hock Isaza
 * Name: maze.cc
 * Created On: 11 Sep 2009
 */

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
#define D_v(x) for(int i=0;i<x.size();cout<<x[i++], i==x.size()?puts(""):NULL)
#define D_m(m, rows, cols) ( {						\
	    for(int __i=0; __i<rows; cout<<endl, ++__i)			\
		for(int __j=0;__j<cols;) cout<<m[__i][__j++]<<"   ";})
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)

#define SWAP(a,b) ( ( (a)^=(b) ), ( (b)^=(a) ), ( (a) ^=(b) ) )
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

typedef pair<int,int> node;

char wall;

void BFS(vector<string> &m,node init){
    queue <node> q;
    q.push(init);
    while(q.size()){
	node ac = q.front();
	q.pop();
	if(m[ac.first][ac.second]== wall ||m[ac.first][ac.second]== '#' ) continue;
	m[ac.first][ac.second]='#';
	q.push(node(ac.first-1,ac.second-1));
	q.push(node(ac.first-1,ac.second));
	q.push(node(ac.first-1,ac.second+1));

	q.push(node(ac.first,ac.second-1));
	q.push(node(ac.first,ac.second+1));
	
	q.push(node(ac.first+1,ac.second-1));
	q.push(node(ac.first+1,ac.second));
	q.push(node(ac.first+1,ac.second+1));
    }
}

int main(){
    int C;
    scanf("%d",&C);
    string line;
    getline(cin,line);
    while(C--){
	getline(cin,line);
	wall = line[0];
	vector<string> maze;
	while(line[0]!='_'){
	    maze.pb(line);
	    getline(cin,line);
	}
	node init;
	for(int i=0;i<maze.sz;++i)
	    for(int j=0;j<maze[i].sz;++j)
		if(maze[i][j]=='*'){
		    init.first = i;
		    init.second = j;
		    break;
		}
	BFS(maze,init);
	for(int i=0;i<maze.sz;++i) cout<<maze[i]<<endl; cout<<line<<endl;
    }
    return 0;
}
