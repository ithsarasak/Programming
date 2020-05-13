#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e15;
 
lint N, X;
lint A[200005];
lint lis[200005];
lint lds[200005];
lint anslis[200005];
 
 
lint LIS() {
    for (int i = 0; i <= N; i++) lis[i] = INF, lds[i] = -INF;
    lis[0] = -INF, lds[N] = INF;
 
    lint res = 0;
 
    for (lint i = 0; i < N; i++) {
        lint j = lower_bound(lis, lis + N + 1, A[i]) - lis;
        lis[j] = A[i], res = max(res, j);
        anslis[i] = j;
    }
 
    for (lint i = N - 1; i >= 0; i--) {
        lint j = upper_bound(lds, lds + N + 1, A[i] - X) - lds;
        res = max(res, anslis[i] + N - j);
        
        j = upper_bound(lds, lds + N + 1, A[i]) - lds - 1;
        lds[j] = A[i];
    }
 
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> A[i];
 
    lint ans = LIS();
    cout << ans << "\n"; 
 
}