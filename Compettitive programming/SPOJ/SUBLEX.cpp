#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int q, lcp[N], n, suf[N], inv[N], ran[N];
long long sum[N], uni;

struct st {
    int x, y, idx;
}arr[N];

bool cmp( st x, st y ) {
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}

void computeSuffix() { 
    for( int i = n-1 ; i >= 0 ; i-- ) {
        arr[i].x = s[i] - 'a';
        arr[i].y = ( i+1 < n ) ? s[i+1] - 'a' : -1;
        arr[i].idx = i;
    }
    //for( int i = 0 ; i < n ; i++ ) printf("%d %d %d\n",arr[i].x,arr[i].y,arr[i].idx);
    sort( arr, arr+n, cmp );
    for( int k = 4 ; k <= 2*n ; k *= 2 ) {
        int prev = arr[0].x, rannow = 0;
        ran[arr[0].idx] = 0;
        arr[0].x = rannow;
        for( int i = 1 ; i < n ; i++ ) {
            if( arr[i].x == prev && arr[i].y == arr[i-1].y ) arr[i].x = rannow;
            else prev = arr[i].x, arr[i].x = ++rannow;
            ran[arr[i].idx] = i;
        }
        for( int i = 0 ; i < n ; i++ ) {
            int nxt = arr[i].idx + k / 2;
            //printf("%d %d %d %d\n",i,nxt,n,arr[ran[nxt]].x);
            if( nxt < n ) {
                //printf("NXT %d %d\n",i,nxt);
                arr[i].y = arr[ran[nxt]].x;
                //printf("%d\n",arr[i].y);
            }
            else arr[i].y = -1;
        }
        //printf("FUCK\n");
        //for( int i = 0 ; i < n ; i++ ) printf("%d %d %d\n",arr[i].x,arr[i].y,arr[i].idx);
        sort( arr, arr+n, cmp );
        //for( int i = 0 ; i < n ; i++ ) printf("%d %d %d\n",arr[i].x,arr[i].y,arr[i].idx);
    }
    //for( int i = 0 ; i < n ; i++ ) printf("%d %d %d\n",arr[i].x,arr[i].y,arr[i].idx);
    for( int i = 0 ; i < n ; i++ ) suf[i] = arr[i].idx;
}


void computeLCP() {
    for( int i = 0 ; i < n ; i++ ) inv[suf[i]] = i;
    int k = 0;
    for( int i = 0 ; i < n ; i++ ) {
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

int main()
{
    scanf("%s",s);
    n = strlen( s );
    s[n] = '$';
    computeSuffix();
    computeLCP();
    /*for( int i = 0 ; i < n ; i++ ) printf("%d ",suf[i]);
    printf("\n");*/
    sum[0] = lcp[0];
    sum[0] = n - suf[0];
    for( int i = 1 ; i < n ; i++ ) {
        sum[i] = max( 0, n - suf[i] - lcp[i-1] );
        sum[i] += sum[i-1];
    }
    scanf("%d",&q);
    while( q-- ) {
        int pos;
        scanf("%d",&pos);
        if( ( long long )pos > sum[n-1] ) {
            //printf("%d ",suf[n-1]);
            for( int i = suf[n-1] ; i < n ; i++ ) printf("%c",s[i]);
            printf("\n");
            continue ;
        }
        int l = 0, r = n-1;
        while( l < r ) {
            int mid = l + r >> 1;
            if( sum[mid] >= pos ) r = mid;
            else l = mid + 1;
        }
        pos -= !l ? 0 : sum[l-1];
        int en = suf[l] + ( !l ? 0 : lcp[l-1] ) + pos;
        for( int i = suf[l] ; i < en ; i++ ) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}