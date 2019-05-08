#include<bits/stdc++.h>

using namespace std;
int q, hw;
char w[110];
int wo[30], ans;
void per( int now, int num, int sum )
{
    //printf("SUM : %d\n",sum);
    if( now == hw - 1 ){
        if( num ){
            sum |= wo[now];
        }
        if( sum == (1<<26) - 1)ans++;
        return ;
    }
    if( num ){
        sum |= wo[now];
    }
    per( now + 1, 0, sum );
    per( now + 1, 1, sum );
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d",&hw);
        memset( wo, 0, sizeof wo );
        for( int i = 0 ; i < hw ; i++ ){
            scanf("%s",w);
            int l = strlen( w );
            for( int j = 0 ; j < l ; j++ ){
                wo[i] |= 1 << ( w[j] - 'a' );
            }
        }
        /*printf("%d\n",(1<<26)-1);
        for( int i = 0 ; i < hw ; i++ ){
            printf("%d\n",wo[i]);
        }*/
        ans = 0;
        per( 0, 0, 0 );
        per( 0, 1, 0 );
        printf("%d\n",ans);
    }
    return 0;
}
