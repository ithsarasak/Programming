#include<bits/stdc++.h>

using namespace std;
int ma[1010][1010], sp[1010];
int n, m, k;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            scanf("%d",&ma[i][j]);
        }
    }
    for( int i = n - 1 ; i > 0 ; i-- ){
        for( int j = 0 ; j < m ; j++ ){
            if( !ma[i][j] )sp[i]++;
        }
        sp[i]+=sp[i+1];
    }
    for( int i = n - 1 ; i > 0 ; i-- ){
        int sum = 0;
        for( int j = 0 ; j < m ; j++ ){
            if( j < k ){
                sum += ma[i][j];
                if( j == k-1 ){
                    if( sum <= sp[i+1] ){
                        printf("%d",i+1);
                        return 0;
                    }
                }
            }
            else{
                sum += ma[i][j] - ma[i][j-k];
                if( sum <= sp[i+1] ){
                    printf("%d",i+1);
                    return 0;
                }
            }
        }
    }
    return 0;
}
