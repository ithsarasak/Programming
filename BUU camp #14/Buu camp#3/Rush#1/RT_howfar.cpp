#include<bits/stdc++.h>

using namespace std;
unordered_map<int,int> l, r;
int num[1000010], n;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        if( l[num[i]] == 0 && num[0] != num[i] ){
            l[num[i]] = i;
        }
        if( i > r[num[i]] ){
            r[num[i]] = i;
        }
    }
    sort( num, num + n );
    int ans = 0;
    for( int i = 0 ; i < n ; i++ ){
        ans = max( ans, max( abs( i - l[num[i]] ), abs( i - r[num[i]] )));
        if( num[i] != num[i+1] ){
            printf("%d %d\n",num[i],ans);
            ans = 0;
        }
    }
    return 0;
}
