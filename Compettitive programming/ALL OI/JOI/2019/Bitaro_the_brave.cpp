#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3010;
vector<pii> coord;
int h, w;
vector<int> o[N], in[N];
long long ans;

int main()
{
    scanf("%d %d",&h,&w);
    for( int i = 0 ; i < h ; i++ ) {
        char arr[N];
        scanf("%s",arr);
        for( int j = 0 ; j < w ; j++ ) {
            if( arr[j] == 'J' ) coord.emplace_back( pii( i, j ) );
            else if( arr[j] == 'O' ) o[i].emplace_back( j );
            else if( arr[j] == 'I' ) in[j].emplace_back( i );
        }
    }
    for( pii i : coord ) {
        int idx = upper_bound( o[i.x].begin(), o[i.x].end(), i.y ) - o[i.x].begin();
        int idx2 = upper_bound( in[i.y].begin(), in[i.y].end(), i.x ) - in[i.y].begin();
        ans += ( long long )( ( ( int )o[i.x].size() - idx ) * ( ( int )in[i.y].size() - idx2 ) );
    }
    printf("%lld",ans);
}