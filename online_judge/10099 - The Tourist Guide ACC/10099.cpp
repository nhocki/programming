/**
 * Nicolã¡s Hock Isaza
 */
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <climits>

#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl

using namespace std;

int g[102][102];

int main(){
    int N,R,C=1;
    while(scanf("%d%d", &N, &R)==2 && (N+R)){
	int a,b,w;
	for(int i=0;i<N+2;++i) for(int j=0;j<N+2;++j) g[i][j]=0;
	for(int i=0;i<R;++i){
	    scanf("%d%d%d", &a, &b, &w);
	    g[a][b]=g[b][a]=w;
	}
	for(int k=1;k<N+2;++k)
	    for(int i=1;i<N+2;++i)
		for(int j=1;j<N+2;++j)
		    g[i][j]=max(g[i][j], min(g[i][k], g[k][j]));
	scanf("%d%d%d", &a, &b, &w);
	int t = ceil((double)w/(g[a][b]-1));
	printf("Scenario #%d\n", C++);
	printf("Minimum Number of Trips = %d\n", t);
	puts("");
    }
}
