#include<bits/stdc++.h>

using namespace std;
struct po{
    double y1, y2;
    bool operator<( const po &k )const{
        return y1 < k.y1;
    }
};
int n;
long long ans;
double x0, x1;
int fen[100100];
vector<po> v;
vector<double> v2;
int query( int idx )
{
    int sum = 0;
    for( int i = idx - 1 ; i > 0 ; i -= ( i & -i ) ){
        sum += fen[i];
    }
    return sum;
}
void up( int idx )
{
    for( int i = idx ; i <= n ; i += ( i & -i ) ){
        fen[i] += 1;
    }
    return ;
}
int main()
{
    scanf("%d",&n);
    scanf("%lf %lf",&x0,&x1);
    for( int i = 0 ; i < n ; i++ ){
        double m, c, y1, y2;
        scanf("%lf %lf",&m,&c);
        y1 = m*x0 + c;
        y2 = m*x1 + c;
        v2.push_back( y2 );
        v.push_back({ y1, y2 });
    }
    sort( v.begin(), v.end() );
    sort( v2.begin(), v2.end() );
    for( int i = 0 ; i < v.size() ; i++ ){
        //printf("%f %f\n",v[i].y1,v[i].y2);
        v[i].y2 = lower_bound( v2.begin(), v2.end(), v[i].y2 ) - v2.begin();
        v[i].y2++;
    }
    for( int i = v.size() - 1 ; i >= 0 ; i-- ){
        ans += ( long long )query( v[i].y2 );
        up( v[i].y2 );
    }
    printf("%lld",ans);
    return 0;
}
