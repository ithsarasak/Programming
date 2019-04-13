#include<bits/stdc++.h>

using namespace std;

int soaps[1001], n, mon;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&soaps[i]);
    }
    scanf("%d",&mon);
    sort( soaps , soaps + n );
    int l = 0, r = n - 1;
    while( l < r ){             //1 4 5 7 9 10 <8> | 3 4 3
        if( soaps[l] == mon ){
            printf("%d",l + 1);
            return 0;
        }
        else if( soaps[r] == mon ){
            printf("%d",r + 1);
            return 0;
        }
        if( l + 1 == r ){
            printf("%d",r);
            return 0;
        }
        int m = ( l + r ) / 2;
        if( mon < soaps[m] ){
            r = m - 1;
        }
        else if( mon > soaps[m] ){
            l = m + 1;
        }
        else{
            printf("%d",m + 1);
            return 0;
        }
    }
    printf("%d",l + 1);
}
