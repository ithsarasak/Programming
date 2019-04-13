#include<bits/stdc++.h>

using namespace std;
struct card{
    int fr, ba;
}allcard[1010];
int n, m;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i ++ ){
        scanf("%d %d",&allcard[i].fr,&allcard[i].ba);
    }
    while( m-- ){
        int num;
        scanf("%d",&num);
        for( int i = 0 ; i < n ; i++ ){
            if( allcard[i].fr <= num ){
                swap( allcard[i].fr , allcard[i].ba );
            }
        }
    }
    for( int i = 0 ; i < n ; i++ ){
        printf("%d\n",allcard[i].fr);
    }
    return 0;
}
