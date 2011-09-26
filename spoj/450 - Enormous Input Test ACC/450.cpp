#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n,k,r=0;
    scanf("%d%d", &n, &k);
    for(int x, i=0;i<n;++i){
	scanf("%d", &x);
	r+= (x%k == 0);
    }
    printf("%d\n", r);
}
