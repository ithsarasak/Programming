#include<bits/stdc++.h>
#define inf 4000000000000000001;
using namespace std;
struct po{
    long long x, y;
}cam[1010], po[1010];
double ans;
int n, c;
long long mi = 0, mt;
int main()
{
    scanf("%d %d",&n,&c);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld %lld",&po[i].x,&po[i].y);
    }
    for( int i = 0 ; i < c ; i++ ){
        scanf("%lld %lld",&cam[i].x,&cam[i].y);
    }
    for( int i = 0 ; i < n ; i++ ){
        mt = inf;
        for( int j = 0 ; j < c ; j++ ){
            long long t = ( po[i].x - cam[j].x )*( po[i].x - cam[j].x )+( po[i].y - cam[j].y )*( po[i].y - cam[j].y );
            mt = min( mt, t );
        }
        mi = max( mi, mt );
    }
    ans = sqrt( double( mi ) );
    printf("%.4f",ans);
    return 0;
}
