#include<bits/stdc++.h>

using namespace std;
struct vv{
    int pos, h;
    bool operator<( const vv &k )const{
        return h < k.h;
    }
};
int n, m, rb, lb;
int mark[100100];
vector<vv> v;
int main()
{
    scanf("%d %d",&n,&m);
    v.push_back({ 0, 0 });
    for( int i = 1 ; i <= n ; i++ ){
        int h;
        scanf("%d",&h);
        v.push_back({ i, h });
    }
    sort( v.begin(), v.end() );
    rb = n;
    mark[0] = 1;
    mark[n+1] = 1;
    for( int z = 1 ; z <= m ; z++ ){
        int que;
        scanf("%d",&que);
        int l = 1, r = rb;
        while( l < r ){
            int mid = ( l + r ) / 2;
            if( v[mid].h > que )r = mid;
            else l = mid + 1;
        }
        if( v[l].h <= que )l++;
        int cnt = 0;
        //printf("L%d]\n",l);
        for( int i = l ; i <= rb ; i++ ){
            if( mark[v[i].pos] == 0 || mark[v[i].pos] == z ){
                if( mark[v[i].pos] == 0 )mark[v[i].pos] = z,cnt++;
                if( mark[v[i].pos-1] == 0 )mark[v[i].pos-1] = z,cnt++;
                if( mark[v[i].pos+1] == 0 )mark[v[i].pos+1] = z,cnt++;
            }
        }
        rb = l - 1;
        printf("%d\n",cnt);
    }
    return 0;
}
