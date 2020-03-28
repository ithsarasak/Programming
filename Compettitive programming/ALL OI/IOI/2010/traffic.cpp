#include "vector"
#include "traffic.h"
 
const int maxn = 1e6+10;
 
std::vector<int> grafo[maxn];
 
int c[maxn], sum[maxn], ans=2000000010, idans;
 
void dfs(int u, int p=-1){
    sum[u] = c[u];
    for(auto v : grafo[u]){
        if(v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
    }
}
 
int diff;
 
void solve(int u, int p=-1){
    int maxi = 0;
    for(auto v : grafo[u]){
        if(v == p) continue;
        if(maxi < sum[v]) maxi = sum[v];
        solve(v, u);
    }
 
    diff = sum[0] - sum[u];
 
    if(maxi < diff) maxi = diff;
 
    if(ans > maxi){
        ans = maxi;
        idans = u;
    }
}
 
int LocateCentre(int n, int *p, int *s, int *d){
    for(int i=0; i<n; i++){
        c[i] = p[i];
        if(i+1<n){
            grafo[s[i]].push_back(d[i]);
            grafo[d[i]].push_back(s[i]);
        }
    }
 
    dfs(0);
    solve(0);
 
    return idans;
}