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
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ){
        r += fenwick[i];
    }
    return r;
}
double sum2( int idx )
{
    double r = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ){
        r += fenwick2[i];
    }
    return r;
}
void up( int ma, int idx ,int val )
{
    for( int i = idx ; i <= ma ; i += ( i & -i ) ){
        fenwick[i] +=  ( double )val ;
    }
}
void up2( int ma, int idx ,int val )
{
    for( int i = idx ; i <= ma ; i += ( i & -i ) ){
        fenwick2[i] += ( double )val;
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
    for( int i = n - 1; i >= 0 ; i-- ){
        ans += ( double )sum( data[i].a - 1 );
        ans += ( double )( sum2( data[i].a - 1 ) * ( double )data[i].a );
        up( ma , data[i].a , data[i].a );
        up2( ma , data[i].a , 1 );
    }
    printf("%.0lf",ans);
    return 0;
}

