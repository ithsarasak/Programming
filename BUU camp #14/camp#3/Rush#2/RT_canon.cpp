#include<bits/stdc++.h>

using namespace std;
struct ee{
    int po, va;
    bool operator<( const ee &g )const{
        if( po == g.po ) return va < g.va;
        else return po < g.po;
    }
};
int n, m, k, l;
int canon[1000010];
vector<ee> all;
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&canon[i]);
    }
    for( int i = 0 ; i < k ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            int p;
            scanf("%d",&p);
            int idx1 = lower_bound( canon, canon + n, max( 0, p-l ) )-canon;
            int idx2 = upper_bound( canon, canon + n, min( 9999999, p+l ) )-canon;
            //printf("%d %d\n",idx1,idx2);
            if( idx1 != idx2 ){
                all.push_back({ idx1, 1 });
                all.push_back({ idx2, -1 });
            }
        }
        sort( all.begin(), all.end() );
        int s = all.size();
        int sum = 0, num = 0;
        for( int j = 0 ; j < s - 1 ; j++ ){
            //printf("po : %d %d\n",all[j].po,j);
            sum += all[j].va;
            if( sum > 0 ){
                //printf("%d %d\n",all[j+1].po,all[j].po);
                num += all[j+1].po - all[j].po;
            }
        }
        printf("%d\n",num);
        all.clear();
    }
    return 0;
}
