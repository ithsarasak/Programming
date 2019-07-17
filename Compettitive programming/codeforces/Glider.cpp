#include<bits/stdc++.h>

using namespace std;
struct vv{
    int f, t;
};
int n, h, f, t, ans;
int sum[200100];
vector<vv> v;
int main()
{
    scanf("%d %d",&n,&h);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&f,&t);
        v.push_back({ f, t });
    }
    for( int i = 0 ; i < v.size() - 1 ; i++ ){
        sum[i+1] = sum[i] + v[i+1].f - v[i].t;
    }
    sum[n] = sum[n-1] + 1000000000 - v[n-1].t;
    /*for( int i = 1 ; i <= n ; i++ )cout << sum[i] << " ";
    cout << endl;*/
    if( h >= sum[n] ){
        h -= sum[n];
        printf("%d",h+1000000000-v[0].f);
        return 0;
    }
    for( int i = 0 ; i < v.size() ; i++ ){
        int l = i, r = n;
        while( l < r ){
            int mid = ( l + r + 1 ) / 2;
            if( sum[mid] - sum[i] < h ){
                l = mid;
            }
            else r = mid - 1;
        }
        //printf("%d %d %d %d\n",l,v[l].t,v[i].f,sum[l]);
        int tt = h;
        tt -= sum[l] - sum[i];
        ans = max( ans, v[l].t - v[i].f + tt );
    }
    printf("%d",ans);
    return 0;
}
