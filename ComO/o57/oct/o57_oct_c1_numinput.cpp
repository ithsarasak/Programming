#include<bits/stdc++.h>

using namespace std;
struct vv{
    int pos, va;
    bool operator<( const vv &k )const{
        return pos < k.pos;
    }
};
int n, qe, sum;
vector<int> v2;
vector<vv> v;
int cnr[1100][1100], ans = 1;
int main()
{
    cnr[0][0] = 1;
    for( int i = 1 ; i <= 1000 ; i++ ){
        for( int j = 0 ; j <= i ; j++ ){
            if( j == 0 || j == i )cnr[i][j] = 1;
            else cnr[i][j] = ( cnr[i-1][j-1] + cnr[i-1][j] ) % 9901;
        }
    }
    /*for( int i = 0 ; i < 10 ; i++ ){
        for( int j = 0 ; j < 10 ; j++ ){
            printf("%d ",cnr[i][j]);
        }
        printf("\n");
    }*/
    scanf("%d %d",&n,&qe);
    for( int i = 1 ; i <= n ; i++ ){
        int num;
        scanf("%d",&num);
        sum += num;
        for( int j = 0 ; j < num ; j++ )v2.push_back( i );
    }
    v.push_back({ 1, 1 });
    /*for( int i = 0 ; i < v2.size() ; i++ ){
        printf("%d ",v2[i]);
    }*/
    //cout << endl;
    for( int i = 0 ; i < qe ; i++ ){
        int pos;
        scanf("%d",&pos);
        v.push_back({ pos, v2[pos-1] });
    }
    v.push_back({ sum, n });
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < v.size() - 1 ; i++ ){
        //printf("%d %d\n",v[i].pos,v[i].va);
        if( v[i].pos == v[i+1].pos )continue;
        if( v[i].va == v[i+1].va )continue;
        if( v[i].va + 1 == v[i+1].va ){
            ans *=  ( v[i+1].pos - v[i].pos );
            ans %= 9901;
        }
        else{
            int emp = v[i+1].pos - v[i].pos - 1, nu = v[i+1].va - v[i].va - 1;
            ans *= ( cnr[emp-1][nu-1] + 2*cnr[emp-1][nu] + cnr[emp-1][nu+1] );
            ans %= 9901;
        }
    }
    //printf("%d %d\n",v[v.size()-1].pos,v[v.size()-1].va);
    printf("%d",ans);
    return 0;
}
