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
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end();++x)
#define mem(i,n) memset(i,n,sizeof(i))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size()
#define lng length()
#define cs c_str()

bool cmp(const pair<int, char> &a, const pair<int, char> &b ){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    int N;
    scanf("%d",&N);
    string line;
    getline(cin, line);
    map<char,int> m;
    vector<pair<int, char> >v;
    while(getline(cin,line))
	for(int i=0;i<line.sz;++i)
	    if(isalpha(line[i]))
		m[(char(toupper(line[i])))]++;
    foreach(i,m) v.pb(make_pair(i->second, i->first));
    sort(all(v),cmp);
    for(int i=0;i<v.sz;++i) cout << v[i].second <<" "<<v[i].first<<endl;
}
