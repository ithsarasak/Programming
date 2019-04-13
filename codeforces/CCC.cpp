#include <bits/stdc++.h>
#include <stdio.h>
#define pi pair<int, int>
#define a first
#define b second

using namespace std;

const int N = 5e3 + 100;

int n, q, ans;
int dp[N], cnt[N];
pi a[N], a1(1e9, -1), a2(1e9, -1);

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d %d", &a[i].a, &a[i].b);
        dp[a[i].a]++, dp[a[i].b+1]--;
    }
    for(int i = 1; i <= n; i++){
        dp[i] += dp[i-1];
    }
    for(int i = 1; i <= q; i++){
        for(int j = a[i].a; j <= a[i].b; j++){
            if(dp[j] == 1) cnt[i]++; 
        }
    }
    for(int i = 1; i <= q; i++){
        a1 = min(a1, pi(cnt[i], i));
    }
    memset(dp, 0, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= q; i++){
        if(i != a1.b){
            dp[a[i].a]++;
            dp[a[i].b+1]--;
        }
    }
    for(int i = 1; i <= n; i++)dp[i] += dp[i-1];
    for(int i = 1; i <= q; i++){
        if(i != a1.b){
            for(int j = a[i].a; j <= a[i].b; j++){
                if(dp[j] == 1) cnt[i]++; 
            }
        }
    }
    for(int i = 1; i <= q; i++){
        if(i != a1.b) a2 = min(a2, pi(cnt[i], i));
    }
    for(int i = a[a2.b].a; i <= a[a2.b].b; i++)dp[i]--;
    for(int i = 1; i <= n; i++)ans += !!dp[i];
    printf("%d\n", ans);
    return 0;
}