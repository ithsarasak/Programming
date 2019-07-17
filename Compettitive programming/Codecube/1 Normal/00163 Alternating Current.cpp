#include <bits/stdc++.h>

using namespace std;
int buc[100100], n, k, mi = 1e9, ma, cnt;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        int nu;
        scanf("%d",&nu);
        mi = min( mi, nu );
        ma = max( ma, nu );
        buc[nu]++;
    }
    while( ma - mi > k ){
        if( buc[ma] > buc[mi] ){
            buc[mi+1] += buc[mi];
            buc[ma-1] += buc[mi];
            buc[ma] -= buc[mi];
            cnt += buc[mi];
            buc[mi] = 0;
        }
        else{
            buc[mi+1] += buc[ma];
            buc[ma-1] += buc[ma];
            buc[mi] -= buc[ma];
            cnt += buc[ma];
            buc[ma] = 0;
        }
        while( buc[ma] == 0 )ma--;
        while( buc[mi] == 0 )mi++;
    }
    printf("%d",cnt);
    return 0;
}
