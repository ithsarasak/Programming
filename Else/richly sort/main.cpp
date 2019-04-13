#include<bits/stdc++.h>

using namespace std;

int num, i;
struct point{
    int x, y;
    bool operator<( const point &k )const{
        if( x != k.x ){
            return x < k.x;
        }
        else{
            return y > k.y;
        }
    }
}allpoint[100100];
int main()
{
    scanf("%d",&num);
    for( i = 0 ; i < num ; i++ ){
        scanf("%d %d",&allpoint[i].x,&allpoint[i].y);
    }
    sort( allpoint , allpoint + num );
    for( i = 0 ; i < num ; i++ ){
        printf("%d %d\n",allpoint[i].x,allpoint[i].y);
    }
    return 0;
}
