#include <bits/stdc++.h>
#define iii tuple<int, int, int, string>
using namespace std;

int wx[4] = { 1, 0, -1, 0 }, wy[4] = { 0, -1, 0, 1 };
string mark[4][4];
queue<iii> q;

char cc( int i ) {
    if( i == 0 ) return 'E';
    if( i == 1 ) return 'S';
    if( i == 2 ) return 'W';
    else return 'N';
}

int check( int x, int y ) {
    if( x > 4 || x < -4 || y > 4 || y < -4 ) return 0;
    else return 1;
}

int main()
{
    q.emplace( 0, 0, 1, "" );
    while( !q.empty() ) {
        int a, b, c;
        string s;
        tie( a, b, c, s ) = q.front(); q.pop();
        mark[a+4][b+4] = s ;
        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = a + wx[i] * (1<<c);
            int ny = b + wy[i] * (1<<c);
            if( check( nx, ny ) && mark[nx][ny] == "" ) q.emplace( nx, ny, c+1, s+cc( i ) );
        }
    }
    int t;
    scanf("%d",&t);
    for( int i =1  ; i <= t ; i++ ){
        int a, b;
        scanf("%d %d",&a,&b);
        if( mark[a+4][b+4] != "" )  cout << "Case #" << i << ": " << mark [a][b] << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}