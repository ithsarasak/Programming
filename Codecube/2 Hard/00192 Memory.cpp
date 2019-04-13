#include <bits/stdc++.h>
using namespace std;
const int N = 5010, INF = 1e9;
int A[N], B[N], dp[2][N], mn[N];
int main()
{
     int n, m, k;
     scanf("%d%d%d", &n, &m, &k);
     for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
     dp[0][0] = 0;
     for (int j = 1; j <= m; ++j) {
        scanf("%d", &B[j]);
        dp[0][j] = mn[j] = j;
     }
     int ans = 0;
     for (int i = 1; i <= n; ++i) {
        int x = i&1;
        dp[x][0] = 1;
        for (int j = 1; j <= m; ++j) {
            dp[x][j] = A[i] == B[j] ? dp[x^1][j-1] : INF;
            dp[x][j] = min(dp[x][j], dp[x][j-1]+1);
            dp[x][j] = min(dp[x][j], dp[x^1][j-1]+1);
            dp[x][j] = min(dp[x][j], mn[j]+1);
            if (dp[x][j] <= k) ans = max(ans, j);
                mn[j] = min(mn[j], dp[x][j]);
        }
     }
     printf("%d\n", ans);
     return 0;
}
