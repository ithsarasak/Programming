#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
 
struct UFT {
    vector <int> p;
    UFT(int n) {
        p.resize(n+1);
        for(int i = 1; i <= n; i++) p[i] = i;
    }
 
    int find(int x) {
        return p[x] == x ? p[x] : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        p[max(x, y)] = min(x, y);
    }
};
 
vector <int> g[MAX];
int low[MAX], ord[MAX], cnt = 0;
 
void dfs(int x, int pa) {
    ord[x] = low[x] = ++cnt;
    bool was = false;
    for(auto i : g[x]) {
        if(i == pa && !was) {
            was = true;
            continue;
        }
        if(ord[i] == 0) {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
        else if(ord[i] < ord[x]) {
            low[x] = min(low[x], ord[i]);
        }
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        if(low[i] > ord[x]) cout << x << ' ' << i << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    UFT t1(n), t2(n);
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(t1.find(u) != t1.find(v)) {
            t1.uni(u, v);
            g[u].eb(v), g[v].eb(u);
        }
        else if(t2.find(u) != t2.find(v)) {
            t2.uni(u, v);
            g[u].eb(v), g[v].eb(u);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(ord[i] == 0) dfs(i, 0);
    }
}