#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 1e5 + 10;
int n;
int coin[N][2];
vector<long> b[2], emp[2];
long ans;
int main()
{
    scanf("%d",&n);
    for( int i = 0, x, y ; i < 2*n ; i++ ) {
        scanf("%d %d",&x,&y);
        if( x < 1 ) ans += 1 - x, x = 1;
        if( x > n ) ans += x - n, x = n;
        if( y < 1 ) ans += 1 - y, y = 1;
        if( y > 2 ) ans += y - 2, y = 2;
        coin[--x][--y]++;
    }
    for( int i = 0 ; i < n ; i++ ) for( int j = 0 ; j < 2 ; j++ ) if( !coin[i][j] ) emp[j].emplace_back( i );
    sort( emp[0].begin(), emp[0].end(), greater<int>() ), sort( emp[1].begin(), emp[1].end(), greater<int>() );
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < 2 ; j++ ) if( !b[j].empty() ) {
            if( coin[i][j] == 0 ) {
                ans += i - b[j].back();
                b[j].pop_back(), emp[j].pop_back();
                coin[i][j]++;
            }
            if( !coin[i][j^1] && !b[j].empty() && b[j^1].empty() ) {
                ans += i - b[j].back() + 1;
                b[j].pop_back(), emp[j^1].pop_back();
                coin[i][j^1]++;
            }
        }
        for( int j = 0 ; j < 2 ; j++ ) {
            while( coin[i][j] > 1 ) {
                if( !emp[j].empty() && emp[j].back() <= i ) {
                    ans += i - emp[j].back();
                    emp[j].pop_back();
                }
                else if( !emp[j^1].empty() && emp[1^j].back() <= i ) {
                    if( coin[i][j^1] > 1 ) {
                        coin[i][j^1]--;
                        ans += i - emp[j^1].back();
                        emp[j^1].pop_back();
                        continue ;
                    }
                    ans += i - emp[j^1].back() + 1;
                    emp[j^1].pop_back();
                }
                else b[j].emplace_back( i );
                coin[i][j]--;
            }
        }
    } 
    printf("%lld",ans);
    return 0;
}