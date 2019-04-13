#include<bits/stdc++.h>

using namespace std;
struct po{
    int a, b;
    bool operator<( const po &k )const{
        return b < k.b;
    }
}data[100010];
double fenwick[100010], fenwick2[100010];
double ans;
int n, ma;
double sum( int idx )
{
    double r = 0;
    while( idx > 0 ){
        r += fenwick[idx];
        idx -= ( idx & -idx );
    }
    //printf("r : %lf\n",r);
    return r;
}
double sum2( int idx )
{
    double r = 0;
    while( idx > 0 ){
        r += fenwick2[idx];
        idx -= ( idx & -idx );
    }
    //printf("r : %d\n",r);
    return r;
}
void up( int ma, int idx ,int val )
{
    while( idx <= ma ){
        //printf("idx : %d\n",idx);
        fenwick[idx] +=  ( double )val ;
        //printf("%d",fenwick[idx]);
        idx += ( idx & -idx );
    }
}
void up2( int ma, int idx ,int val )
{
    while( idx <= ma ){
        //printf("idx : %d\n",idx);
        fenwick2[idx] += ( double )val;
        //printf("%d",fenwick[idx]);
        idx += ( idx & -idx );
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&data[i].a,&data[i].b);
        if( ma < data[i].a ){
            ma = data[i].a;
        }
    }
    sort( data , data + n );
    /*for( int i = 0 ; i < n ; i++ ){
        printf("%d %d\n",data[i].a,data[i].b);
    }*/
    for( int i = n - 1; i >= 0 ; i-- ){
        ans += ( double )sum( data[i].a - 1 );
        ans += ( double )( sum2( data[i].a - 1 ) * ( double )data[i].a );
        up( ma , data[i].a , data[i].a );
        up2( ma , data[i].a , 1 );
        //printf("%d\n",ans);
    }
    printf("%.0f",ans);
    return 0;
}

