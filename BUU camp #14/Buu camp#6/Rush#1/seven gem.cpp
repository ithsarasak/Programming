#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, bi, ti, di, gem;
};
queue<qq> q;
int n, m, cou;
char ma[210][210];
int cnt[210][210];
int dis[210][210][1<<7][10];
int walk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}, si, sj;
int nowi, nowj, nowbi, nowti, nowdi, nowgem, nexi, nexj, nexbi, nexti, nexdi, nexgem;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%s",ma[i] + 1 );
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            if( ma[i][j] == 'S' ){
                si = i;
                sj = j;
                ma[i][j] = '.';
            }
            if( ma[i][j] == 'G' ){
                cnt[i][j] = cou;
                cou++;
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1; j <= m ; j++ ){
            for( int k = 0 ; k < ( 1 << 7 ) ; k++ ){
                for( int l = 0 ; l < 6 ; l++ ){
                    dis[i][j][k][l] = 1 << 30;
                }
            }
        }
    }
    q.push({si,sj,0,0,0,0});
    while( !q.empty() ){
        nowi = q.front().x;
        nowj = q.front().y;
        nowbi = q.front().bi;
        nowti = q.front().ti;
        nowdi = q.front().di;
        nowgem = q.front().gem;
        q.pop();
        if( nowbi == ( 1 << 7 ) - 1 ){
            printf("%d",nowdi);
            return 0;
        }
        if( isdigit( ma[nowi][nowj] ) && ( nowgem >= ma[nowi][nowj]-'0' ) && nowdi + 1 < dis[nowi][nowj][nowbi][(nowti+1)%6] ){
            dis[nowi][nowj][nowbi][(nowti+1)%6] = nowdi + 1;
            q.push({nowi,nowj,nowbi,(nowti+1)%6,nowdi+1,nowgem});
        }
        if( !isdigit( ma[nowi][nowj]) && nowdi + 1 < dis[nowi][nowj][nowbi][(nowti+1)%6] ){
            dis[nowi][nowj][nowbi][(nowti+1)%6] = nowdi + 1;
            q.push({nowi,nowj,nowbi,(nowti+1)%6,nowdi+1,nowgem});
        }
        for( int i = 0 ; i < 4 ; i++ ){
            nexi = nowi + walk[i][0];
            nexj = nowj + walk[i][1];
            nexbi = nowbi;
            nexti = (nowti+1)%6;
            nexdi = nowdi + 1;
            nexgem = nowgem;
            if( nexi < 1 || nexj < 1 || nexi > n || nexj > m || ma[nexi][nexj] == '#' )continue;
            if( ma[nexi][nexj] == 'G' && !( nexbi & ( 1 << cnt[nexi][nexj] ) ) ){
                nexgem++;
                nexbi |= ( 1 << cnt[nexi][nexj] );
            }
            if( isdigit( ma[nexi][nexj] ) && ( nexgem >= ma[nexi][nexj]-'0' || nexti == ma[nexi][nexj]-'1' ) && nexdi < dis[nexi][nexj][nexbi][nexti] ){
                dis[nexi][nexj][nexbi][nexti] = nexdi;
                q.push({ nexi, nexj, nexbi, nexti, nexdi, nexgem });
            }
            else if( !isdigit( ma[nexi][nexj] ) && nexdi < dis[nexi][nexj][nexbi][nexti] ){
                dis[nexi][nexj][nexbi][nexti] = nexdi;
                q.push({ nexi, nexj, nexbi, nexti, nexdi, nexgem });
            }
        }
    }
    printf("-1");
    return 0;
}
