#include<bits/stdc++.h>

using namespace std;
int a, b, t1, t2, c2 = 1;
int main()
{
    scanf("%d %d",&a,&b);
    t1 = sqrt( a );
    t2 = sqrt( b );
    if( t1 * t1 < a ){
        t1 += 1;
    }
    for( int i = t1 ; i <= t2 ; i++ ){
        int j = 2;
        bool c = true;
        while( j * j <= i ){
            if( i % j == 0 ){
                c = false;
                break;
            }
            j++;
        }
        if( c && i != 1 ){
            printf("%d ",i * i);
            c2 = 0;
        }
    }
    if( c2 ){
        printf("-1");
    }
    return 0;
}
