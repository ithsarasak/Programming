#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
    int d;
    bool operator<( const ee &k )const{
        return d < k.d;
    }
}e[1000100];
struct po{
    int x, y;
}p[1010];
int n, k;
int s, ae, par[1010], ma;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            e[s].f = i;
            e[s].t = j;
            e[s].d = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y);
            s++;
        }
    }
    for( int i = 0 ; i <= n ; i++ ){
        par[i] = i;
    }
    sort( e, e + s );
    for( int i = 0 ; i < s ; i++ ){
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            par[a] = b;
            ae++;
            ma = max( ma, e[i].d );
        }
        if( ae >= n - k ){
            break;
        }
    }
    printf("%d",ma);
    return 0;
}

