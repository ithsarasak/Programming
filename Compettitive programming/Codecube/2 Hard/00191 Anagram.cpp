#include<bits/stdc++.h>

using namespace std;
long long va[30];
int mx;
char s1[2100], s2[2100];
vector<long long> v;
int main()
{
    va[0] = 2003;
    for( int i = 1 ; i < 26 ; i++ ){
        va[i] = va[i-1] * 2003;
    }
    scanf("%s",&s1[1]);
    scanf("%s",&s2[1]);
    int len1 = strlen( &s1[1] );
    int len2 = strlen( &s2[1] );
    for( int i = 1 ; i <= len1 ; i++ ){
        long long sum = 0;
        for( int j = i ; j <= len1 ; j++ ){
            sum += va[s1[j]-'A'];
            v.push_back( sum );
        }
    }
    sort( v.begin(), v.end() );
    for( int i = 1 ; i <= len2 ; i++ ){
        long long sum = 0;
        for( int j = i ; j <= len2 ; j++ ){
            sum += va[s2[j]-'A'];
            int idx = lower_bound( v.begin(), v.end(), sum ) - v.begin();
            if( v[idx] == sum ){
                mx = max( mx, j - i + 1 );
            }
        }
    }
    printf("%d",mx);
    return 0;
}

