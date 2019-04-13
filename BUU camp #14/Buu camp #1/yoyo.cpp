#include<bits/stdc++.h>

using namespace std;

int fenwick[500001], n, m;
string t;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        cin >> t;
        if( t == "Yoyo" ){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            if( b > c ){
                swap( b , c );
            }
            for( int i = b ; i <= n ; i += ( i & -i ) ){
                fenwick[i] += a;
            }
            for( int i = c + 1 ; i <= n ; i += ( i & -i ) ){
                fenwick[i] -= a;
            }
        }
        else{
            int sum = 0;
            int ask;
            scanf("%d",&ask);
            for( int i = ask ; i > 0 ; i -= ( i & -i ) ){
                sum += fenwick[i];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
