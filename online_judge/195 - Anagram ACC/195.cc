#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    string word;
    cin >> word;
    vector<int>conv;
    for(int i=0;i<word.size();++i){
      char letter = word[i];
      if(letter <= 'Z') conv.push_back((letter - 'A') * 2);
      else conv.push_back((letter - 'a') * 2 + 1);
    }
    sort(conv.begin(), conv.end());
    do{
      for(int i=0;i<conv.size();++i){
        char letter;
        if(conv[i] & 1) letter = ((conv[i] - 1) / 2) + 'a';
        else letter = (conv[i] / 2) + 'A';
        printf("%c", letter);
      }
      puts("");
    }while(next_permutation(conv.begin(), conv.end()));
  }
}
