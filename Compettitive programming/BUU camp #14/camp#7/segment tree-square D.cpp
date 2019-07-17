#include<bits/stdc++.h>

using namespace std;
int n, q;
int num[100100], cluster[320];
int sq;
int main()
{
    scanf("%d %d",&n,&q);
    sq = sqrt( n );
    while( q-- ){
        int a, b;
        char c;
        scanf(" %c %d %d",&c,&a,&b);
        a--;
        if( c == 'U' ){
            num[a] = b;
            cluster[a/sq] = -1e9;
            for( int i = (a/sq)*sq ; i < min( n, (a/sq)*sq+sq) ; i++ ){
                cluster[a/sq] = max( cluster[a/sq], num[i] );
            }
        }
        else{
            int ans = -1e9;
            b--;
            for( int i = a ; i <= b ; ){
                if( i % sq == 0 && i + sq - 1 <= b ){
                    ans = max( ans, cluster[i/sq] );
                    i += sq;
                }
                else{
                    ans = max( ans, num[i] );
                    i++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
