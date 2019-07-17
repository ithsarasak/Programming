#include <bits/stdc++.h>

using namespace std;

struct tri{
    int x, y, a, b;
};
vector<tri> t;
int n;
int main()
{
    scanf("%d",&n);
    if( n != 2 ) return !printf("vbvb");
    for( int i = 1, x, y, a, b ; i < n ; i++ ) {
        scanf("%d %d %d %d",&x,&y,&a,&b);
        t.emplace_back({ x, y, a, b });
    }
    int x1 = t[0].x, y1 = t[0].y;
    int x2 = x1 + t[0].a, y2 = y1;
    int x3 = x1, y3 = y1 + t[0].b;
    int a1 = t[1].x, b1 = t[1].y;
    int a2 = a1 + t[1].a, b2 = b1;
    int a3 = a1, b3 = b1 + t[1].b;
    int w = check( x1, y1, a1, b1, a2, b2, a3, b3 ), tt = check( x2, y2, a1, b1, a2, b2, a3, b3 ), f = check( x3, y3, a1, b1, a2, b2, a3, b3 );
    if( w && tt && f ) {
        printf("%lld",cal( a1, b1, a2, b2, a3, b3 ));
    }  
    else if( w && tt ) {

    }
    else if( w && f ) {
        
    }
    else if( f && tt ) {

    }
    else if( w ) {

    }
    else if( tt ) {

    }
    else if( f ) {

    }
    else printf("%d",ans);
    return 0;
}