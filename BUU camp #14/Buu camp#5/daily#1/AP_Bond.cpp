#include<bits/stdc++.h>

using namespace std;
struct wi{
    int s, k;
    bool operator<( const wi &g )const{
        if( s == g.s ) return k < g.k;
        else return s > g.s;
    }
}all[100010];
int q, n;
vector<int> lis;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d %d",&all[i].s,&all[i].k);
        }
        sort( all, all + n );
        lis.push_back( all[0].k );
        for( int i = 1 ; i < n ; i++ ){
            if( all[i].k >= lis.back() ){
                lis.push_back( all[i].k );
            }
            else{
                int idx = upper_bound( lis.begin(), lis.end(), all[i].k ) - lis.begin();
                lis[idx] = all[i].k;
            }
        }
        printf("%d\n",lis.size());
        lis.clear();
    }
    return 0;
}
/*
1
5
1 1
1 2
1 3
1 4
1 5
*/
