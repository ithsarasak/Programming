#include<bits/stdc++.h>

using namespace std;
int n, f, t;
int mark[1000010];
vector< long long > num, prime;
void genprime()
{
    for( int i = 2 ; i <= 1e6 ; i++ ){
        if( !mark[i] ){
            prime.push_back( i );
            mark[i] = 1;
            for( int j = 2*i ; j <= 1e6 ; j += i ){
                mark[j] = 1;
            }
        }
    }
    for( int i = 0 ; i < prime.size() ; i++ ){
        long long t = prime[i]*prime[i];
        while( t <= 1e12 ){
            num.push_back( t );
            t *= prime[i];
        }
    }
    sort( num.begin(), num.end() );
}
int main()
{
    genprime();
    scanf("%d",&n);
    /*for( auto i = num.begin() ; i != num.end() ; i++ ){
        printf("%d ",*i);
    }
    printf("\n");*/
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&f,&t);
        int idx1 = lower_bound( num.begin(), num.end(), t ) - num.begin();
        int idx2 = lower_bound( num.begin(), num.end(), f ) - num.begin();
        printf("%d\n",idx1-idx2+1);
    }
    return 0;
}
