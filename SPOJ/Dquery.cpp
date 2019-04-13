#include<bits/stdc++.h>

using namespace std;
struct vv{
    int f, t, idx;
    bool operator<( const vv &x )const{
        return t < x.t;
    }
};
vector<vv> que;
int n, q, j = 1;
int mark[1000100];
int fen[30100];
int num[30100], ans[200100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    scanf("%d",&q);
    for( int i = 0 ; i < q ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        que.push_back({ f, t, i });
    }
    sort( que.begin(), que.end() );
    for( int i = 0 ; i < que.size() ; i++ ){
        while( j <= que[i].t ){
            if( mark[num[j]] == 0 )mark[num[j]] = j;
            else{
                for( int k = mark[num[j]] ; k <= n ; k += ( k & -k ) ){
                    fen[k] += 1;
                }
                mark[num[j]] = j;
            }
            j++;
        }
        int sum1 = 0, sum2 = 0;
        for( int k = que[i].t ; k > 0 ; k -= ( k & -k ) ){
            sum1 += fen[k];
        }
        for( int k = que[i].f - 1 ; k > 0 ; k -= ( k & -k ) ){
            sum2 += fen[k];
        }
        ans[que[i].idx] = ( que[i].t - que[i].f + 1 ) - ( sum1 - sum2 );
    }
    for( int i = 0 ; i < q ; i++ ){
        printf("%d\n",ans[i]);
    }
    return 0;
}
