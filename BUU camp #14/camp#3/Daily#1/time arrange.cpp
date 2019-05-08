#include<bits/stdc++.h>

using namespace std;
struct ww{
    int f, t;
    bool operator<( const ww &k )const{
        if( t == k.t ) return f < k.f;
        else return t < k.t;
    }
}wo[100010];
int n, e, co = 1;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&wo[i].f,&wo[i].t);
    }
    sort( wo, wo + n );
    e = wo[0].t;
    for( int i = 1 ; i < n ; i++ ){
        if( e <= wo[i].f ){
            co++;
            e = wo[i].t;
        }
    }
    printf("%d",co);
    return 0;
}
