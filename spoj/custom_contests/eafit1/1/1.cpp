#include <iostream>
#include <cstdio>

int main(){
  int n;
  while(scanf("%d", &n)){
    if(n==42) break;
    printf("%d\n", n);
  }
  return 0;
}
