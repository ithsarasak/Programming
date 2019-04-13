#include<bits/stdc++.h>

using namespace std;
int n, s;
int num[101010];
int main()
{
    scanf("%d %d",&n,&s);
    if( s % 3 != 0 ){
        printf("-1");
        return 0;
    }
    if( n == 1 ){
        if( s != 6 ) printf("-1");
        else printf("6");
        return 0;
    }
    num[n-1] = 1;
    s--;
    if( s >= 8 ){
        num[0] = 8;
        s -= 8;
    }
    else{
        int t = s / 2;
        num[0] = t*2;
        s -= t*2;
    }
    for( int i = 1 ; i < n ; i++ ){
        if( s <= 0 )break;
        if( s >= 9 - num[i] ){
            s -= 9 - num[i];
            num[i] = 9;
        }
        else{
            num[i] += s;
            s = 0;
        }
    }
    if( s != 0 ){
        printf("-1");
        return 0;
    }
    for( int i = n - 1 ; i >= 0 ; i-- ){
        printf("%d",num[i]);
    }
    return 0;
}
