#include<bits/stdc++.h>

using namespace std;
int prime[500010], mark[500010],sump[500500], s, t, n, mic[3][500010];
vector< int > fac[500500];
void genprime()
{
    int sq = sqrt( 500000 );
    for( int i = 2 ; i <= sq ; i++ ){
        if( !mark[i] ){
            prime[s] = i;
            s++;
            for( int j = i ; j <= sq ; j += i ){
                mark[j] = 1;
            }
        }
    }
    for(int i=2;i<=500000;i++){
        int temp=i;
        for(int j=0;j<s;j++){
            if(i%prime[j]==0){
                while(temp%prime[j]==0) temp/=prime[j];
                fac[i].push_back(prime[j]);
                sump[i]+=prime[j];
            }
        }
        if(temp!=1){
                fac[i].push_back(temp);
                sump[i]+=temp;
        }
    }
}
int play( int pl, int num )
{
    if( num == 0 ){
        if( pl == 1 ) return mic[pl][num] = 1;
        else return mic[pl][num] = 0;
    }
    if( mic[pl][num] != -1 ){
        return mic[pl][num];
    }
    int sumprime = 0;
    if( pl == 1 ){
        int ma = -1;
        for( int i = 0 ; i < fac[num].size() ; i++ ){
                ma = max( ma, play( 2, sump[num] - fac[num][i] ) );
        }
        return mic[pl][num] = ma;
    }
    else{
        int mi = 1e9;
        for( int i = 0 ; i < fac[num].size() ; i++ ){
                mi = min( mi, play( 1, sump[num] - fac[num][i] ) );
        }
        return mic[pl][num] = mi;
    }
}
int main()
{
    genprime();
    memset( mic, -1, sizeof mic );
    scanf("%d",&t);
    while( t-- ){
        scanf("%d",&n);
        if( n == 1 ){
            printf("2\n");
            continue ;
        }
        if( play( 1, n ) ){
            printf("1\n");
        }
        else{
            printf("2\n");
        }
    }
    return 0;
}
