#include <bits/stdc++.h>
#define pil pair<int, long long>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;

int n, mark[N];
long long hi[N], posl[N], posr[N], mx[N], sum;
vector<long long> lis, lis2;
pil ans;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&hi[i]);
    posl[1] = 1;
    lis.emplace_back( hi[1] );
    for( int i = 2 ; i <= n ; i++ ) {
        if( hi[i] >= lis.back() ){
            posl[i] = lis.size() + 1;
            lis.emplace_back( hi[i] );
        }
        else {
            int idx = upper_bound( lis.begin(), lis.end(), hi[i] ) - lis.begin();
            lis[idx] = hi[i];
            posl[i] = idx + 1;
        }
    }
    lis2.emplace_back( hi[n] );
    posr[n] = 1;
    for( int i = n - 1 ; i >= 1 ; i-- ) {
        if( hi[i] <= lis2.back() ) {
            posr[i] = lis2.size() + 1;
            lis2.emplace_back( hi[i] );
        }
        else {
            int idx = upper_bound( lis2.begin(), lis2.end(), hi[i], greater<int>() ) - lis2.begin();
            lis2[idx] = hi[i];
            posr[i] = idx + 1;
        }
    }
    // for( int i = 1 ; i <= n ; i++ ) printf("%d ",posl[i]);
    // printf("\n");
    // for( int i = 1 ; i <= n ; i++ ) printf("%d ",posr[i]);
    // printf("\n");
    for( int i = 1 ; i <= n ; i++ ) if( posl[i] + posr[i] - 1 == ( int )lis.size() ) mark[i] = 1;
    // for( int i = 1 ; i <= n ; i++ ) cout << mark[i] << " ";
    // cout << endl; 
    for( int i = n ; i >= 1 ; i-- ) if( mark[i] ) {
        // printf("%lld ",hi[i]);
        // printf("%lld\n",posr[i]);
        if( hi[i] > mx[posr[i]] ) {
            sum += hi[i] - mx[posr[i]];
            mx[posr[i]] = hi[i];
        }
        if( posr[i] == ( int )lis.size() ) ans = max( ans, pil( lis.size(), sum ) );
    } 
    printf("%d %lld",ans.x,ans.y);
    return 0;
}
