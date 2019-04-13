#include<bits/stdc++.h>

using namespace std;

int n, m, a, b, fenwick[750001], sum1, sum2, idx;
string t;
int main()
{
    scanf("%d %d",&n,&m);
    for( auto i = 0 ; i < m ; i++ ){
        cin >> t;
        //cout << t;
        scanf("%d %d",&a,&b);
        if( t == "Bury" ){
            while( b <= n ){
                //cout << idx;
                fenwick[b] += a;
                b += ( b & -b );
            }
        }
        else{
                sum1 = 0;
            while( b > 0 ){
                //cout << idx;
                sum1 += fenwick[b];
                b -= ( b & -b );
            }
            a--;
            while( a > 0 ){
                sum1 -= fenwick[a];
                a -= ( a & -a );
            }
            printf("%d\n",sum1);
        }
    }
    return 0;
}
