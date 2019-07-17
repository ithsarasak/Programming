#include<bits/stdc++.h>

using namespace std;
int n, m;
int fen[1000100], fen2[1000100];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = i ; j <= n ; j += ( j & -j ) ){
            fen[j] += 1;
        }
    }
    while( m-- ){
        char ch;
        scanf(" %c",&ch);
        if( ch == 'd' ){
            int pos;
            scanf("%d",&pos);
            pos++;
            int l = 1, r = n;
            while( l < r ){
                int mid = ( l + r ) / 2;
                int sum = 0;
                for( int i = mid ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
                if( sum >= pos )r = mid;
                else l = mid + 1;
            }
            int sum = 0;
            for( int i = l ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
            if( pos != sum ){
                for( int j = l ; j <= n ; j += ( j & -j ) )fen2[j] -= 1;
            }
            for( int i = l ; i <= n ; i += ( i & -i ) ){
                fen[i] -= 1;
            }
        }
        else if( ch == 'g' ){
            int pos;
            scanf("%d",&pos);
            pos++;
            int l = 1, r = n;
            while( l < r ){
                int mid = ( l + r ) / 2;
                int sum = 0;
                for( int i = mid ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
                if( sum >= pos )r = mid;
                else l = mid + 1;
            }
            int sum = 0;
            for( int i = l ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
            if( sum == pos )l++;
            for( int j = l ; l <= n ; l += ( l & -l ) ){
                fen[j] += 1;
                fen2[j] += 1;
            }
        }
        else{
            int f, t;
            scanf("%d %d",&f,&t);
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for( int i = f ; i > 0 ; i -= ( i & -i ) )sum1 += fen[i];
            for( int i = t ; i > 0 ; i -= ( i & -i ) )sum2 += fen[i];
            for( int i = t ; i > 0 ; i -= ( i & -i ) )sum3 += fen2[i];
            for( int i = f ; i > 0 ; i -= ( i & -i ) )sum3 -= fen2[i];
            int ttt = sum2 - sum1 - 1, ttt2 = t - f - 1;
            printf("%d\n",ttt2-ttt+2*sum3);
        }
    }
    return 0;
}
