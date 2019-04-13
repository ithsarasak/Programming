#include<bits/stdc++.h>

using namespace std;
struct di{
    int w, h, d;
    bool operator<( const di &k )const{
        return d < k.d;
    }
}dish[1000010];
int l, k;
long long ans;
int main()
{
    scanf("%d %d",&l,&k);
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d %d",&dish[i].w,&dish[i].h);
        dish[i].d = dish[i].w - dish[i].h;
    }
    sort( dish , dish + k );
    int j;
    for( j = 0 ; j < l ; j++ ){
        if( dish[j].d > 0 ){
            break;
        }
        ans += ( long long )dish[j].w;
    }
    for( int i = j ; i < k ; i++ ){
        ans += ( long long )dish[i].h;
    }
    printf("%lld",ans);
    return 0;
}
