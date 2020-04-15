#include <bits/stdc++.h>

using namespace std;

int t;
int a, b, c, d, x1, x2, y1, y2, x, y;
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        int temp1 = b - a, temp2 = d - c;
        if( ( ( x1 == x2 ) && ( a != 0 || b != 0 ) ) || ( ( y1 == y2 ) && ( c != 0 || d != 0 )  ) ){
            printf("NO\n");
            continue ;
        }
        if( x + temp1 >= x1 && x + temp1 <= x2 && y + temp2 >= y1 && y + temp2 <= y2 ) {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}