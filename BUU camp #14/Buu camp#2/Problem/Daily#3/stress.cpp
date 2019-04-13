#include<bits/stdc++.h>

using namespace std;
int mod = 1000000007, q;
int s1, s2, mfr[2010][2010], mfu[2010][2010];
int free( int one, int two )
{
    if( one < 0 || two < 0 ) return 0;
    if( mfr[one][two] != -1 ) return mfr[one][two];
    if( one == 0 && two == 0 ) return mfr[one][two] = 1;
    if( one <= two ) return mfr[one][two] = 0;
    return mfr[one][two] = ( free( one - 1, two ) + free( one, two - 1 ) ) % mod;
}
int ful( int one, int two )
{
    if( one < 0 || two < 0 ) return 0;
    if( mfu[one][two] != -1 ) return mfu[one][two];
    if( one == 0 && two == 0 ) return mfu[one][two] = 1;
    if( one > two && two != s2 ) return mfu[one][two] = 0;
    return mfu[one][two] = ( ful( one - 1, two ) + ful( one, two - 1 ) ) % mod;
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        memset( mfr, -1, sizeof mfr );
        memset( mfu, -1, sizeof mfu );
        scanf("%d-%d",&s1,&s2);
        printf("%d ",free( s1, s2 ));
        printf("%d\n",ful( s1, s2 ));
    }
    return 0;
}
