#include<bits/stdc++.h>

using namespace std;
struct re{
    int f1, f2, r;
    bool operator<( const re &k )const{
        return r < k.r;
    }
}rela[5000010];
int n, m, q, k, mst[4010], ans, par[4010], si;
int findroot( int num )
{
    if( par[num] == num ){
        return num;
    }
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d %d",&rela[i].f1,&rela[i].f2,&rela[i].r);
    }
    sort( rela, rela + m );
    for( int i = 0 ; i <= n ; i++ ){
        par[i] = i;
    }
    for( int i = 0 ; i < m ; i++ ){
        int a = findroot( rela[i].f1 );
        int b = findroot( rela[i].f2 );
        if( a != b ){
            mst[si] = rela[i].r;
            si++;
            par[a] = b;
        }
    }
    sort( mst, mst + si );
    for( int i = 0 ; i < q ; i++ ){
        scanf("%d",&k);
        int idx = upper_bound( mst, mst + si, k ) - mst;
        printf("%d\n",n - idx);
    }
    return 0;
}
