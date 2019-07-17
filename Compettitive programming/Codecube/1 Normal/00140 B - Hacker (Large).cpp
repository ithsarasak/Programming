#include<bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    scanf("%d %d",&n,&m);
    int pr[n+10][m+10], mark[n+10];
    memset(pr,0,sizeof pr);
    memset(mark,0,sizeof mark);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            scanf("%d",&pr[i][j]);
        }
        sort( pr[i], pr[i] + m);
    }
    for( int j = 0 ; j < m ; j++ ){
        int mx = -1, po;
        for( int i = 0 ; i < n ; i++ ){
            if( mx < pr[i][j] ) mx=pr[i][j],po=i;
        }
        mark[po]++;
    }
    int mx = -1, pos;
    for( int i = 0 ; i < n ; i++ ) if(mx < mark[i]) mx=mark[i],pos=i;
    printf("%d",pos+1);
    return 0;
}
