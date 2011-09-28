#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
int c, l, h, n;
pair<int, pair<int, int> > edges[100000];
int p[3000], r[3000];
vector<int> E[3000], W[3000];


// Union Find Algorithm
// Simple version
void makeSet(int u){
    p[u] = u; r[u] = 0;
    E[u].resize(0);   W[u].resize(0);
}

void link(int a, int b){
    if(r[a] > r[b]) swap(a, b);
    p[a] = b;
    if(r[a] == r[b]) r[b]++;
}
int find(int u){
    return p[u] == u ? u : p[u] = find(p[u]);
}
void Union(int u, int v){
    link(find(u), find(v));
}



//pai[i]   = the parent of the node i
//pp[i][j] = the (2^j)th parent of the node i (pp[i][0] = pai[i]; pp[i][1] = pai[ pai[i] ] ...)
//dist[i]  = level of node i. How deep it's in the tree.
int maxi[3000][20], pai[3000], inf = 1 << 30, dist[3000], pp[3000][20];

void dfs(int v, int p, int f, int c){
    pai[v] = f;
    dist[v] = p;
    maxi[v][0] = c;
    for(int i = 0; i < E[v].size(); i++){
        if(E[v][i] == f) continue;
        dfs(E[v][i], p + 1, v, W[v][i]);
    }
}

void pre(){
    memset(pai, -1, sizeof pai);

    for(int i = 0; i < n; i++){
        for(int j = 0; (1 << j) < n; j++){
            pp[i][j] = -1;
            maxi[i][j] = -inf;
        }
    }
    dfs(0, 0, -1, 0);
    pai[0] = 0;
    maxi[0][0] = inf;

    ////// DP to find the (2^j)th parent of the node i

    // First state. The (2^0) parent of the node i is the parent
    for(int i = 0; i < n; i++) pp[i][0] = pai[i];

    for(int j = 1; (1 << j) < n; j++){
        for(int i = 0; i < n; i++){
            if(pp[i][j - 1] == -1) continue;
            // Find the parent
            pp[i][j] = pp[pp[i][j - 1]][j - 1];
            // Find the maximum edge to get there
            maxi[i][j] = max(maxi[pp[i][j - 1]][j - 1], maxi[i][j - 1]);
        }
    }
}

// Small modification of the LCA algorithm
// Instead of only finding the LCA, find the maximum
// weight of going to the LCA.
// If you're looking for the LCA(a, b), then
// maxi[a][0] will have the maximum edge from a to LCA(a,b)
// maxi[b][0] will have the maximum edge from b to LCA(a,b)
int resolve(int a, int b){
    int rmaxi = -inf;
    if(dist[a] < dist[b]) swap(a, b);
    int log;
    for(log = 1; (1 << log) <= dist[a]; log++);
    log--;
    for(int i = log; i >= 0; i--){
        // Find one ancestor on the same level
        if(dist[a] - (1 << i) >= dist[b]){
            rmaxi = max(rmaxi, maxi[a][i]);
            a = pp[a][i];
        }
    }

    // If a was an ancestor of b, we're done
    if(a == b) return rmaxi;

    // Go down finding the lowest ancestor
    // Notice that the i is going lower
    // meaning that we're going deeper and deeper
    for(int i = log; i >= 0; i--){
        if(pp[a][i] != -1 && pp[a][i] != pp[b][i]){
            rmaxi = max(rmaxi, maxi[a][i]);
            rmaxi = max(rmaxi, maxi[b][i]);
            a = pp[a][i]; b = pp[b][i];
        }
    }
    rmaxi = max(rmaxi, maxi[a][0]);
    rmaxi = max(rmaxi, maxi[b][0]);
    return rmaxi;
}


int main(){
    while(scanf("%d %d %d", &c, &l, &h) && c != -1){
        int edg = 0;
        while(l--){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            edges[edg++] = make_pair(w, make_pair(a - 1, b - 1));
        }

        // Start the Kruskal algorithm
        // An edge is represented by the triplet
        // <W, a, b> meaning that the edge <a, b> costs W.
        sort(edges, edges + edg);
        for(int i = 0; i < c; i++) makeSet(i);

        for(int i = 0; i < edg; i++){
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(find(u) != find(v)){
                Union(u, v);
                E[u].push_back(v); E[v].push_back(u);
                W[u].push_back(w); W[v].push_back(w);
            }
        }
        // End of Kruskal Algorithm

        n = c;
        pre();

        for(int i = 0; i < h; i++){
            if(i) printf(" ");
            int a, b; scanf("%d %d", &a, &b); a--; b--;
            printf("%d", resolve(a, b));
        }
        printf("\n");

    }            
}