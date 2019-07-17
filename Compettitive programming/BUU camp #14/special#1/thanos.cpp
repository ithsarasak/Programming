#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
int r, c, ans = 1e9, l, re;
char ma[N][N];
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 0 ; i < r ; i++ ) scanf("%s",ma[i]);
    for( int j = 0 ; j < c ; j++ ) {
        int ta = -1, land = 1e9;
        for( int i = 0 ; i < r ; i++ ) {
            if( ma[i][j] == 'X' ) ta = max( ta, i );
            if( ma[i][j] == '#' ) land = min( land, i );
        }
        if( ta == -1 || land == 1e9 ) continue;
        if( ans > land - ta - 1 ) {
            ans = land - ta - 1;
            l = ta + 1, re = land - 1;
        }
    }
    //cout << l << " " << re << endl;
    int move = re - l + 1;
    for( int i = r - 1 ; i >= 0 ; i-- ) {
        for( int j = 0 ; j < c ; j++ ) {
            if( i - move < 0 ) ma[i][j] = '.';
            else if( ma[i][j] != '#' ) ma[i][j] = ma[i-move][j];
        }
    }
    for( int i = 0 ; i < r ; i++ ) printf("%s\n",ma[i]);
   return 0;
}