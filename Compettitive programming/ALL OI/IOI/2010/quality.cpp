//#include "quality.h"
#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e3+5;

int sum[N][N], n, c, r, h, w;
pii pos[N*N];


bool chk( int mid, int rec[3001][3001] ) {
    for( int i = 1 ; i <= r ; i++ ) {
        for( int j = 1 ; j <= c ; j++ ) {
            if( rec[i-1][j-1] < mid ) sum[i][j] = -1;
            else if( rec[i-1][j-1] > mid ) sum[i][j] = 1;
            else sum[i][j] = 0;
        }
    }
    for( int i = 1 ; i <= r ; i++ )
        for( int j = 1 ; j <= c ; j++ )
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    for( int i = h ; i <= r ; i++ ) 
        for( int j = w ; j <= c ; j++ ) 
            if( sum[i][j] - sum[i-h][j] - sum[i][j-w] + sum[i-h][j-w] <= 0  ) return true;
        
    
    return false;
}

int rectangle( int R, int C, int H, int W, int rec[3001][3001] ) {
    r = R, c = C, w = W, h = H;
    n = r*c;
    for( int i = 0 ; i < r ; i++ ) for( int j = 0 ; j < c ; j++ ) pos[rec[i][j]] = pii( i+1, j+1 );
    int l = 1, r = n;
    while( l < r ) {
        int m = l + r >> 1;
        if( chk( m, rec ) ) r = m;
        else l = m + 1;
    }
	return l;
}
int rrr[3001][3001];
int main()
{
    int r, c, h, w;
    scanf("%d %d %d %d",&r,&c,&h,&w);
    for( int i = 0 ; i < r ; i++ ) for( int j = 0 ; j < c ; j++ ) scanf("%d",&rrr[i][j]);
    printf("%d",rectangle( r, c, h, w, rrr ) );
}