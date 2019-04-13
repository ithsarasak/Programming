#include<bits/stdc++.h>

using namespace std;
struct tem{
    int po, va;
    bool operator<( const tem &k )const{
        if( po == k.po )return va < k.va;
        else return po < k.po;
    }
};
struct mi{
    int f, t;
}m[2000010];
int q;
int n, x, y, z, sum1, sum2, deli, ans, te;
vector<tem> all;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %d %d %d",&n,&x,&y,&z);
        for( int i = 0 ; i < n ; i++ ){
            int f, t;
            scanf("%d %d",&m[i].f,&m[i].t);
            all.push_back({m[i].f,1});
            all.push_back({m[i].t+1,-1});
        }
        sort( all.begin(), all.end() );
        sum1 = 0, sum2 = 0;
        int s = all.size();
        ans = 0, te = 0;
        deli = 0;
        for( int i = 0 ; i < s ; i++ ){
            if( all[i].va == 1 ) sum1++;
            else sum2++;
            int dt = sum1-sum2;
            int tt = sum2*z + dt*y + (n-sum1)*x;
            deli = max( deli, tt );
        }
        printf("%d",deli);
        all.clear();
    }
    return 0;
}
