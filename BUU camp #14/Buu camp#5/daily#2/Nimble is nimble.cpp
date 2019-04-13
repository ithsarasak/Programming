#include<bits/stdc++.h>

using namespace std;
long long n, m, ice[50][50], qm[50][50][50][50], mem[50][50][50][50];
long long mcm( int sti, int stj, int endi, int endj )
{
    if( mem[sti][stj][endi][endj] != -1 ) return mem[sti][stj][endi][endj];
    if( sti == endi && stj == endj ) return mem[sti][stj][endi][endj] = 0;
    long long mi = 1e10;
    for( int i = sti ; i < endi ; i++ ){
        mi = min( mi, qm[sti][stj][i][endj]+qm[i+1][stj][endi][endj]+mcm(sti,stj,i,endj)+mcm(i+1,stj,endi,endj));
    }
    for( int i = stj ; i < endj ; i++ ){
        mi = min( mi, qm[sti][stj][endi][i]+qm[sti][i+1][endi][endj]+mcm(sti,stj,endi,i)+mcm(sti,i+1,endi,endj));
    }
    return mem[sti][stj][endi][endj] = mi;
}
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            scanf("%lld",&ice[i][j]);
        }
    }
    for( int i = 0 ; i < 45 ; i++ ){
        for( int j = 0 ; j < 45 ; j++ ){
            for( int k = 0 ; k < 45 ; k++ ){
                for( int l = 0 ; l < 45 ; l++ ){
                    qm[i][j][k][l] = 1;
                    mem[i][j][k][l] = -1;
                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            for( int k = i ; k <= n ; k++ ){
                for( int l = j ; l <= m ; l++ ){
                    for( int a = i ; a <= k ; a++ ){
                        for( int b = j ; b <= l ; b++ ){
                            qm[i][j][k][l] *= ice[a][b];
                        }
                    }
                }
            }
        }
    }
    printf("%lld",mcm( 1, 1, n, m ));
    return 0;
}

