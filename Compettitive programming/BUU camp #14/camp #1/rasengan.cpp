#include<bits/stdc++.h>

using namespace std;

int low[300010], high[300010], shot, ans, mountain[300010];
int n, m, status;
int main()
{
   scanf("%d %d",&n,&m);
   for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&mountain[i]);
        low[i - 1] = min( mountain[i - 1] , mountain[i] );
        high[i - 1] = max( mountain[i - 1] , mountain[i] );
    }
    low[n] = 0;
    high[n] = mountain[n];
    sort( low , low + n + 1 );
    sort( high , high + n + 1 );
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&shot);
        int idx1 = lower_bound( low, low + n , shot ) - low;
        if( shot > low[n] ){
            idx1++;
        }
        int idx2 = lower_bound( high, high + n, shot ) - high;
        if( shot > high[n] ){
            idx2++;
        }
        //printf("%d %d\n",idx1,idx2);
        printf("%d\n",( idx1 - idx2 ) / 2 );
    }
   return 0;
}
