#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, c[N], cnt[N];

int check( int mid ) {
    int ans = 1, sum = 0;
    for( int i = 1 ; i < mid ; i++ ) cnt[c[i]]++;
    for( int i = 1 ; i < mid ; i++ ) {
        sum += cnt[i];
        if( sum >= i ) ans = 0;
    }
    for( int i = 1 ; i < mid ; i++ ) cnt[c[i]]--; 
    return ans;
}

int main()
{
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
    scanf("%d",&n);
    for( int i = 1, a ; i <= n ; i++ ) {
        scanf("%d",&a);
        c[i] = n - a;
    }
    int l = 1, r = n;
    while( l < r ) {
        int mid = l + r + 1 >> 1;
        if( check( mid ) ) l = mid;
        else r = mid - 1;
    }
    printf("%d",n-l);
    return 0;
}