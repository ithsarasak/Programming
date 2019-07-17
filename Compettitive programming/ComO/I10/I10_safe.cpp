#include<bits/stdc++.h>

using namespace std;
int car[500100];
int n;
int main()
{
    scanf("%d",&n);
    car[0] = 1e9+1;
    for( int i = 1 ; i <= n ; i++ ){
        int t;
        scanf("%d %d",&t,&car[i]);
        printf("%d\n",max( 0, car[i] - car[i-1] ) );
        car[i] = min( car[i], car[i-1] );
    }
    return 0;
}
