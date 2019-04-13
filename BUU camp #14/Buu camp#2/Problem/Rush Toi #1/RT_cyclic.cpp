#include<bits/stdc++.h>

using namespace std;
int ta[10000][10000], t, n, q;
int main()
{
    scanf("%d",&t);
    while( t-- ){
        scanf("%d %d",&n,&q);
        int tt = n;
        int x = 0, y = 0;
        int num = 1;
        int c = 0;
        while( n > 0 ){
            if( c ) x++, y++;
            for( int i = 0 ; i < n ; i++ ){
                ta[x][y] = num;
                num += 1;
                num %= 10;
                y++;
            }
            n--;
            if( n == 0 ){
                break;
            }
            y--;
            x++, y--;
            for( int i = 0 ; i < n ; i++ ){
                ta[x][y] = num;
                num += 1;
                num %= 10;
                x++, y--;
            }
            n--;
            if( n == 0 ){
                break;
            }
            x--, y++;
            x--;
            for( int i = 0 ; i < n ; i++ ){
                ta[x][y] = num;
                num += 1;
                num %= 10;
                x--;
            }
            n--;
            if( n == 0 ){
                break;
            }
            c = 1;
        }
        for( int i = 0 ; i < q ; i++ ){
            int a, b;
            scanf("%d %d",&a,&b);
            printf("%d\n",ta[a][b-a]);
        }
    }
}
