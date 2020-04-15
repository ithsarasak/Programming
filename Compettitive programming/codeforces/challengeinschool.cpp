#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 3e3 + 10;
int n, k, tim[N], mx;
char s[N];
queue<iii> q;
vector<int> ti[3000010];
int main()
{
    scanf("%d %d",&n,&k);
    scanf("%s",&s[1]);
    for( int i = 1 ; i <= n ; i++ ) {
        if( s[i] == 'R' && s[i+1] == 'L' ) {
            int x = max( tim[i], tim[i+1] );
            tim[i] = tim[i+1] = x + 1;
            ti[tim[i]].emplace_back( i );
            s[i] = 'L', s[i+1] = 'R';
            //printf("%d")
            q.emplace( i-1, i, -1 ), q.emplace( i+1, i+2, 1 );
            break;
        } 
    }
    while( !q.empty() ) {
        int a, b, c;
        tie( a, b, c ) = q.front(); q.pop();
        //printf("%d %d %d\n",a,b,c);
        if( a == 0 || b == n + 1 ) continue ;
        if( s[a] == 'R' && s[b] == 'L' ) {
            int x = max( tim[a], tim[b] );
            tim[a] = tim[b] = x + 1;
            mx = max( mx, tim[a] );
            s[a] = 'L', s[b] = 'R';
            ti[tim[a]].emplace_back( a );
            q.emplace( a-1, a, -1 ), q.emplace( b, b+1, 1 );
        }
        else if( c == -1 ) q.emplace( a-1, a, -1 );
        else q.emplace( a, a+1, 1 );
    }
    if( mx > k ) return printf("-1");
    for( int i = 1 ; i <= mx ; i++ ) {
        int sz = ti[i].size();
        printf("%d ",sz);
        for( int i : ti[i] ) printf("%d ",i);
        printf("\n");
    }
    return 0;
}