#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct st {
    int x, y, idx;
}arr[N];

string s;
int t, inv[N], suf[N], ran[N], n, lcp[N];

bool cmp( st x, st y ) {
    return ( x.x == y.x ) ? x.y < y.y : x.x < y.x;
}

void computeSuffix() {
    s += '$';
    for( int i = n-1 ; i >= 0 ; i-- ) {
        arr[i].x = s[i] - 'A';
        arr[i].y = ( i+1 < n ) ? s[i+1] - 'A' : -1;
        arr[i].idx = i;
    }
    sort( arr, arr+n, cmp );
    /*for( int i = 0 ; i < n ; i++ ) printf("%d ",arr[i].idx);
    printf("\n");
    printf("SUFFIX\n");*/
    for( int k = 4 ; k <= 2*n ; k *= 2 ) {
        int rannow = 0;
        int prev = arr[0].x;
        arr[0].x = rannow;
        ran[arr[0].idx] = 0;
        for( int i = 1 ; i < n ; i++ ) {
            if( arr[i].x == prev && arr[i].y == arr[i-1].y ) arr[i].x = rannow;
            else prev = arr[i].x, arr[i].x = ++rannow;
            ran[arr[i].idx] = i;
        }
        /*for( int i = 0 ; i < n ; i++ ) printf("%d ",arr[i].x);
        printf("\n");*/
        for( int i = 0 ; i < n ; i++ ) {
            int nxt = arr[i].idx + k/2;
            arr[i].y = nxt < n ? arr[ran[nxt]].x : -1;
        }
        sort( arr, arr+n, cmp );
    }
    for( int i = 0 ; i < n ; i++ ) suf[i] = arr[i].idx;
}


void computeLCP() {
    for( int i = 0 ; i < n ; i++ ) inv[suf[i]] = i;
    int k = 0;
    for( int i = 0 ; i < n ; i++ ) {
        //printf("inv:%d\n",inv[i]);
        if( inv[i] == n-1 ) {
            lcp[inv[i]] = k = 0;
            continue ;
        }
        int j = suf[inv[i]+1];
        while( s[i+k] != '$' && s[j+k] != '$' && s[i+k] == s[j+k] ) k++;
        lcp[inv[i]] = k;
        if( k > 0 ) k--;
    }
}

void solve() {
    cin >> s;
    int ans = 0;
    n = s.length();
    computeSuffix();
    /*for( int i = 0 ; i < n ; i++ ) printf("%d ",suf[i]);
    printf("\n");*/
    computeLCP();
    ans = n - suf[0];
    for( int i = 0 ; i < n-1 ; i++ ) {
        //printf("%d ",lcp[i]);
        ans += max( 0, n - suf[i+1] - lcp[i] );
    }
    //printf("\n");
    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&t);
    while( t-- ) {
        solve();
    }
    return 0;
}