#include<bits/stdc++.h>

using namespace std;
char a[300010];
long long buc[27]={0}, co, mic[27][300010], mb[27];
vector< int > so;
int main()
{
    scanf(" %s",&a[1]);
    int len = strlen( &a[1] );
    //printf("%d\n",len);
    for( int i = 1 ; i <= len ; i++ ){
        //printf("%lld ",buc[a[i] -'a']);
        if( buc[a[i]-'a'] == 0 ){
            buc[a[i]-'a'] = 1;
            co++;
        }
    }
    //printf("%d\n",co);
    for( int j = 1 ; j <= len ; j++ ){
        //memset( mb, 0, sizeof mb );
        mb[a[j] -'a'] = j;
        so.push_back( 0 );
        for( int k = 0 ; k < 26 ; k++ ){
            if( mb[k] != 0 ){
                so.push_back( mb[k] );
            }
        }
        sort( so.begin() , so.end() , greater<int>() );
        for( int k = 0 ; k < so.size() - 1 ; k++ ){
            mic[k+1][j] = mic[k+1][j-1] + so[k] - so[k+1];
        }
        so.clear();
    }
    printf("%lld\n",co);
    for( int i = 0 ; i < co ; i++ ){
        printf("%lld\n",mic[i + 1][len] );
    }
    return 0;
}
