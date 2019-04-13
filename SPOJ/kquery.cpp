#include<bits/stdc++.h>

using namespace std;
struct vv{
    int t, k, idx, ty;
    bool operator<( const vv &o )const{
        return t < o.t;
    }
};
vector<vv> que;
int n, q;
int key[30100], num[30100];
int fen[30100], ans[200100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        key[i] = num[i];
    }
    sort( key + 1, key + 1 + n );
    for( int i = 1 ; i <= n ; i++ ){
        int idx = lower_bound( key + 1, key + 1 + n, num[i] ) - key;
        num[i] = idx;
    }
    scanf("%d",&q);
    for( int i = 0 ; i < q ; i++ ){
        int f, t, k;
        scanf("%d %d %d",&f,&t,&k);
        int idx = upper_bound( key + 1, key + 1 + n, k ) - key;
        idx--;
        que.push_back({ t, idx, i, 1 });
        que.push_back({ f - 1, idx, i, 2 });
    }
    sort( que.begin(), que.end() );
    int j = 1;
    for( int i = 0 ; i < que.size() ; i++ ){
        while( j <= que[i].t ){
            for( int l = num[j] ; l <= n ; l += ( l & -l ) ){
                fen[l] += 1;
            }
            j++;
        }
        int sum1 = 0, sum2 = 0;
        for( int l = n ; l > 0 ; l -= ( l & -l ) ){
            sum1 += fen[l];
        }
        for( int l = que[i].k ; l > 0 ; l -= ( l & -l) ){
            sum2 += fen[l];
        }
        if( que[i].ty == 1 )ans[que[i].idx] += sum1 - sum2;
        else ans[que[i].idx] -= sum1 - sum2;
    }
    for( int i = 0 ; i < q ; i++ )printf("%d\n",ans[i]);
    return 0;
}
