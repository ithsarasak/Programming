#include<bits/stdc++.h>

using namespace std;
struct nu{
    int va, idx;
    bool operator<( const nu &k )const{
        return va < k.va;
    }
}num[20010];
struct qq{
    int a, b, po,num,type;
    bool operator<( const qq &k )const{
        return po < k.po;
    }
}q[500010];
struct que{
    int f, t;
}qu[200010];
int n, qqq, fw[20010];

int ans[200200];
int main()
{
    scanf("%d %d",&n,&qqq);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i].va);
        num[i].idx = i;
    }
    sort( num + 1, num + n + 1 );
    for( int i = 1 ; i <= qqq ; i++ ){
        int a, b, s, e;
        scanf("%d %d %d %d",&a,&b,&s,&e);
        q[2*i-1].a = a;
        q[2*i-1].b = b;
        q[2*i-1].po = s-1;
        q[2*i].a = a;
        q[2*i].b = b;
        q[2*i].po = e;
        q[2*i].type=1;
        q[2*i-1].type=2;
        q[2*i].num=q[2*i-1].num=i;
    }
    sort( q + 1, q + 2*qqq + 1 );
    int j = 1;
    for( int i = 1 ; i <= 2*qqq ; i++ ){
        while( num[j].va <= q[i].po && j <= n ){
            for( int k = num[j].idx ; k <= n ; k += k & -k ){
                fw[k] += 1;
            }
            j++;
        }
        int sum1 = 0, sum2 = 0;
        for( int k = q[i].a - 1 ; k > 0 ; k -= k & -k ){
            sum1 += fw[k];
        }
        for( int k = q[i].b ; k > 0 ; k -= k & -k ){
            sum2 += fw[k];
        }
        if(q[i].type==1) ans[q[i].num] += sum2 - sum1;
        else ans[q[i].num] -= sum2 - sum1;
    }
    for( int i = 1 ; i <= qqq ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
