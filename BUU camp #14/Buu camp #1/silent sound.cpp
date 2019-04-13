#include<bits/stdc++.h>

using namespace std;
int n, m, c;
int sound[1000010];
deque< int > ma, mi;
int main()
{
    scanf("%d %d %d",&n,&m,&c);
    int ch = 0;
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&sound[i]);
        while( !ma.empty() && sound[ma.back()] <= sound[i] ){
            ma.pop_back();
        }
        while( !ma.empty() && ma.front() <= i - m ){
            ma.pop_front();
        }
        while( !mi.empty() && sound[mi.back()] >= sound[i] ){
            mi.pop_back();
        }
        while( !mi.empty() && mi.front() <= i - m ){
            mi.pop_front();
        }
        ma.push_back( i );
        mi.push_back( i );
        if( sound[ma.front()] - sound[mi.front()] <= c && i >= m ){
            printf("%d\n",i - m + 1);
            ch = 1;
        }
    }
    if( !ch ){
        printf("NONE");
        return 0;
    }
    return 0;
}
