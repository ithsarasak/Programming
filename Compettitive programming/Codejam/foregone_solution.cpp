#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int q, n[N], ans1[N], ans2[N];
char num[N];
int main()
{
    scanf("%d",&q);
    for( int z = 1 ; z <= q ; z++ ) {
        int chk = 0;
        memset( ans1, 0, sizeof ans1 );
        memset( ans2, 0, sizeof ans2 );
        scanf("%s",num);
        int l = strlen( num );
        for( int i = 0 ; i < l ; i++ ) n[i] = num[i] - '0';
        for( int i = l - 1 ; i >= 0 ; i-- ) {
            if( ( !n[i] || n[i] == 1 ) && i != 0 ) {
                n[i] += 10;
                int cnt = 1;
                while( n[i-cnt] == 0 ) {
                    n[i-cnt] = 9;
                    cnt++;
                }
                n[i-cnt]--;
            }
        }
        for( int i = 0 ; i < l ; i++ ) {
            int ok = 0;
            for( int j = 1 ; j < n[i] ; j++ ) {
                if( j != 4 && n[i] - j != 4 && j <= 9 && n[i] - j <= 9 ) {
                    ans1[i] = j, ans2[i] = n[i] - j;
                    ok = 1;
                    break;
                }
            } 
            if( !ok ) ans1[i] = 0, ans2[i] = n[i];
        }
        printf("Case #%d: ",z);
        for( int i = 0 ; i < l ; i++ ) {
            if( ans1[i] ) chk = 1;
            if( chk ) printf("%d",ans1[i]);
        }
        printf(" ");
        chk = 0;
        for( int i = 0 ; i < l ; i++ ) {
            if( ans2[i] != 0 ) chk = 1;
            if( chk ) printf("%d",ans2[i]);
        }
        printf("\n");
    }
    return 0;
}