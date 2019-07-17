#include<bits/stdc++.h>

using namespace std;
int n, b;
int soi[500100];
int check( int mid )
{
    long long ans = 0;
    for( int i = 0 ; i < n ; i++ ){
        int te = soi[i] / mid;
        if( te * mid != soi[i] )te++;
        ans += ( long long )te;
    }
    if( ans <= ( long long )b )return 1;
    else return 0;
}
int main()
{
    scanf("%d %d",&n,&b);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&soi[i]);
    }
    int l = 0, r = 5000000;
    while( l < r ){
        int mid = ( l + r ) / 2;
        if( check( mid ) ) r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}

