#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5+10,M = 1e5+10;

int n,m;
struct Edge {
    int u,v,w;
} edges[M];
int p[N];

int find (int u) {
    if (u == p[u]) {
        return u;
    } else {
        return p[u] = find (p[u]);
    }
}

bool comp (Edge a, Edge b) {
    return a.w < b.w;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0;i < m;i ++) {
        scanf ("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (int i = 1;i <= n;i ++) {
        p[i] = i;
    }

    sort (edges, edges+m, comp);

    int sum = 0;
    for (int i = 0;i < w;i ++) {
        int u = edges[i].u,v = edges[i].v;
        u = find (u);
        v = find (v);

        if (u != v) {
            p[u] = v;
            sum += edges[i].w;
        }
    }
    printf ("%d\n", sum);
}
