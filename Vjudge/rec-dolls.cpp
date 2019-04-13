#include<bits/stdc++.h>

using namespace std;
struct d{
    int w, h;
    bool operator<( const d &k )const{
        if( w == k.w ){
            return h > k.h;
        }
        else return w > k.w;
    }
}doll[20010];
struct d2{
    int w, h;
    bool operator<( const d2 &k )const{
        if( h == k.h ){
            return w > k.w;
        }
        else return h > k.h;
    }
}doll2[20010];
int n, ma, ma2, co, co2, t;
int main()
{
    scanf("%d",&t);
    while( t-- ){
        ma = -1, ma2 = -1;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d %d",&doll[i].w,&doll[i].h);
            doll2[i].w = doll[i].w;
            doll2[i].h = doll[i].h;
        }
        sort( doll, doll + n );
        sort( doll2, doll2 + n );
        co = 1;
        for( int i = 1 ; i < n ; i++ ){
            //printf("%d ",co);
            if( doll[i].w < doll[i - 1].w && doll[i].h < doll[i-1].h ){
                //printf("%d",i);
                ma = max( ma, co );
                co = 0;
            }
            co++;
            //printf("\n");
        }
        ma = max( ma, co );
        co2 = 1;
        for( int i = 1 ; i < n ; i++ ){
            if( doll2[i].w < doll2[i - 1].w && doll2[i].h < doll2[i-1].h ){
                ma2 = max( ma2, co2 );
                co2 = 0;
            }
            co2++;
            /*printf("%d ",i);
            printf("%d ",co2);
            printf("%d",ma2);
            printf("\n");*/
        }
        //printf("%d\n",co2);
        ma2 = max( ma2, co2 );
        printf("%d %d\n",ma,ma2);
        printf("%d\n",min( ma, ma2 ) );
    }
    return 0;
}

