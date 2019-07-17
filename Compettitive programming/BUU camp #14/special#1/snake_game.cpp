#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 +10;
int r, c, ans;
char ma[N][N];
vector<int> jelly[N];
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 1 ; i <= r ; i++ ) scanf("%s",&ma[i][1]);
    for( int i = r ; i >= 1 ; i-- ) for( int j = 1 ; j <= c ; j++ ) if( ma[i][j] == 'J' ) jelly[i].emplace_back( j );
    int st = 1;
    for( int i = r ; i >= 1 ; i-- ) {
        //printf("%d %d\n",st,ans);
        if( i != 1 ) ans += 1;
        if( ( r - i ) % 2 == 0 ) {
            if( jelly[i].size() != 0 ) {
                int x = jelly[i].size()-1;
                ans += jelly[i][x] - st;
                st = jelly[i][x];
            }
            int y = jelly[i-1].size();
            if( y >= 1 && i != 1 ) {
                if( st < jelly[i-1][y-1] ) {
                   ans += jelly[i-1][y-1] - st;
                    st = jelly[i-1][y-1];
                }
            }
        }
        else {
            if( jelly[i].size() != 0 ) {
                ans += st - jelly[i][0];
                st = jelly[i][0];
            }
            int y = jelly[i-1].size();
            if( y >= 1 && i != 1 ) {
                if( st > jelly[i-1][0] ) {
                   ans += st - jelly[i-1][0];
                    st = jelly[i-1][0];
                }
            }
        }
    }
    for( int i = 1 ; i <= r ; i++ ) {
        if( jelly[i].size() != 0 ) break;
        else ans--;111111111
    }
    printf("%d",ans);
    return 0;
}