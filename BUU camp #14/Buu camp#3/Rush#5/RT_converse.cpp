#include<bits/stdc++.h>

using namespace std;
int q, n, c1[100010], c2[100010], ch, ans;
int buc1[10], buc2[10];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        ch = 0;
        scanf("%d",&n);
        memset( buc1, 0, sizeof buc1 );
        memset( buc2, 0, sizeof buc2 );
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&c1[i]);
            buc1[c1[i]]++;
        }
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&c2[i]);
            buc2[c2[i]]++;
        }
        ans = 0;
        for( int i = 1 ; i <= 5 ; i++ ){
            if(( buc1[i] + buc2[i] ) % 2 ){
                ch = 1;
                break;
            }
            ans += abs( buc1[i] - buc2[i]) / 2 ;
        }
        if( ch )printf("-1");
        else printf("%d\n",ans/2);
    }
}
