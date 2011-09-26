#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[1005];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%s", s);
    int i=0, n = strlen(s), cnt = 0;
    char current;
    for(i = 0;i<n;++i){
      cnt = 1;
      current = s[i];
      while(s[i+1] == s[i]){
        cnt++;
        i++;
      }
      printf("%d%c", cnt, current);
    }
    puts("");
  }
  return 0;
}
