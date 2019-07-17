#include<bits/stdc++.h>

using namespace std;
int num[20100];
int n, cnt;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < 2 * n ; i++ ){
        scanf("%d",&num[i]);
        if( num[i] != i % 2 )cnt++;
    }
    int mi = cnt / 2;
    cnt = 0;
    for( int i = 0 ; i < 2 * n ; i++ ){
        if( num[i] != ( i + 1 ) % 2 ){
            cnt++;
        }
    }
    printf("%d",min(mi,cnt/2));
    return 0;
}
