#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)==1){
	int ret = -1;
	vector<int>S(n);
	vector<int>A(n,1);
	for(int i=0;i<n;++i)scanf("%d", &S[i]);
	for(int i=0;i<n;++i){
	    for(int j=0;j<i;++j){
		if(S[i]>S[j]){
		    A[i]=max(A[i],A[j]+1);
		}
	    }
	    ret = max(ret, A[i]);
	}
	printf("%d\n", ret);
    }
    return 0;
}
