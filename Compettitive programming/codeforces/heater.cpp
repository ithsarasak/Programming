#include<bits/stdc++.h>

using namespace std;
int n, r, mi = 1e9;
vector<int> v1, v2, v3;
int main()
{
    scanf("%d %d",&n,&r);
    for( int i = 1 ; i <= n ; i++ ){
        int ch;
        scanf("%d",&ch);
        if( ch ){
            v1.push_back( i );
            v2.push_back( i - r + 1 );
        }
    }
    /*for( int i = 0 ; i < v1.size() ; i++ ){
        printf("%d %d\n",v1[i],v2[i]);
    }*/
    for( int i = 0 ; i < v1.size() ; i++ ){
        int cnt = 0, now = v1[i], ch = 0;
        if( now-r+1 > 1 )break;
        while( 1 ){
            cnt++;
            //printf("%d %d\n",now,cnt);
            if( now+r-1 >= n ){
                break;
            }
            int idx = upper_bound( v2.begin(), v2.end(), now + r ) - v2.begin();
            idx--;
            if( v1[idx] == now ){
                ch = 1;
                break;
            }
            else now = v1[idx];
        }
        if( !ch )mi = min( mi, cnt );
    }
    if( mi == 1e9 )printf("-1");
    else printf("%d\n",mi);
    return 0;
}
