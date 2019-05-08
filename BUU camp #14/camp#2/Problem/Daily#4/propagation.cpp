#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long t, st[200], n, m, t;
struct A{
    long long mat[200][200];
    A operator*(const A &o){
        A temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.mat[i][j] = 0;
                for(int k=0;k<n;k++){
                    temp.mat[i][j] += mat[i][k] * o.mat[k][j];
                    temp.mat[i][j] %= mod;
                    temp.mat[i][j] += mod;
                    temp.mat[i][j] %= mod;
                }
            }
        }
        return temp;
    }
};
A start, temp;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&t);
    for( int z = 1 ; z <= m ; z++ ){
        long long a, b;
        scanf("%d %d",&a,&b);
        start.mat[a][b] = 1;
        start.mat[b][a] = 1;
    }
    st[0] = 1;
    return 0;
}
