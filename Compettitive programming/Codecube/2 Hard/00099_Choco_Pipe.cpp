#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 50;
struct qq {
    int i, j, w, type;
    bool operator<( const qq &o ) const {
        return w > o.w;
    }
};
int dist[N][N][4], n, m, costa, costb, costc;
char str[N][N];
int dir[]={ -1, 1, 0, 0 };
int dic[]={ 0, 0, -1, 1 };
priority_queue<qq> q;

int main()
{
    scanf("%d %d %d %d %d %d",&costa,&costb,&costc,&m,&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf(" %s",str[i]+1);
        for(int j = 1 ; j <= m ; j++ ) for( int k = 0 ; k < 4 ; k++ ) dist[i][j][k]=2e9;
    }
    q.push({ n, 0, 0, 3 });
    while( !q.empty() ) {
        int nowi=q.top().i, nowj=q.top().j, noww=q.top().w, nowtype=q.top().type; q.pop();
        for( int k = 0 ; k < 4 ; k++ ) {
            if( k / 2 == nowtype / 2 && k != nowtype ) continue;
            int nexti = nowi + dir[nowtype], nextj = nowj + dic[nowtype];
            if( nexti <= 0 || nextj <= 0 || nexti > n || nextj > m )    continue;
            int nowcost = 0 + ( str[nexti][nextj] =='X' ) * costc;
            if( k / 2 != nowtype / 2 ){
                if( noww + costb + nowcost < dist[nexti][nextj][k] ) {
                    dist[nexti][nextj][k] = costb + nowcost + noww;
                    q.push({ nexti, nextj, noww + costb + nowcost, k });
                }
            }
            else {
                if( noww + costa + nowcost < dist[nexti][nextj][k] ) {
                    dist[nexti][nextj][k] = noww + costa + nowcost;
                    q.push({ nexti, nextj, noww + costa + nowcost, k });
                }
            }
        }
    }
    printf("%d\n",dist[1][m][3]);
    return 0;
}
