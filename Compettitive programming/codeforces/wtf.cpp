#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int arr[N], sum;
int main()
{
    for( int i = 1 ; i <= 13 ; i++ ) scanf("%d",&arr[i]);
    for( int i = 1 ; i <= 12 ; i++ ) sum += ( 13 - i + 1 ) * arr[i];
    sum %= 11;
    if( sum <= 1 ) {
        if( arr[13] != 1 - sum ) printf("1");
        else printf("0");
    }
    else if( arr[13] != 11 - sum ) printf("1");
    return 0;
}