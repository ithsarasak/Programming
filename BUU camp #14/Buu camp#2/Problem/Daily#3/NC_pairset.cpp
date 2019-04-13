#include<bits/stdc++.h>

using namespace std;
int n, m, k, ans;
int x[100010], y[110], z[100010];
unordered_map< int , int > ma;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&x[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&y[i]);
    }
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d",&z[i]);
    }
    sort( x , x + n );
    for( int i = 0 ; i < k ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            int idx = lower_bound( x, x + n, z[i] - y[j] ) - x;
            if( x[idx] == z[i] - y[j] ){
                ans++;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
