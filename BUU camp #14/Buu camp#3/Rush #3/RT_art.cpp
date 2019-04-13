#include<bits/stdc++.h>

using namespace std;
struct fi{
    int po, h, co;
    bool operator<( const fi &k )const{
        if( po == k.po )return co < k.co;
        else return po < k.po;
    }
};
int fw[1000010];
int n, in, ans;
vector<fi> all;
int query( int num )
{
    int sum = 0;
    for( int i = num ; i > 0 ; i -= i & -i ){
        sum += fw[i];
    }
    return sum;
}
int main()
{
    scanf("%d %d",&n,&in);
    for( int i = 0 ; i < n ; i++ ){
        int f, h, t, co;
        scanf("%d %d %d %d",&f,&h,&t,&co);
        all.push_back({f, h, co});
        all.push_back({f+t, h, -1*co});
    }
    sort( all.begin(), all.end() );
    int ss = all.size();
    /*for( int i = 0 ; i < ss ; i++ ){
        printf("%d %d %d\n",all[i].po,all[i].h,all[i].co);
    }*/
    for( int i = 0 ; i < ss-1 ; i++ ){
        for( int j = 1 ; j <= 1e6 ; j += j & -j ){
            fw[j] += all[i].co;
            //printf("%d %d\n",j,fw[j]);
        }
        //printf("\n");
        for( int j = all[i].h+1 ; j <= 1e6 ; j += j & -j ){
            fw[j] += -1*all[i].co;
            //printf("%d %d\n",j,fw[j]);
        }
        //printf("\n");
            int l = 1, r = 1e6;
            while( l < r ){
                int m = ( l + r ) / 2;
                //printf("%d %d %d\n",l,r,query(m));
                if( query( m ) <= in ){
                    r = m;
                }
                else l = m + 1;
            }
            int lower = l;
            l = 1, r = 1e6;
           // printf("\n");
            while( l < r ){
                int m = ( l + r + 1 ) / 2;
                //printf("%d %d %d\n",l,r,query(m));
                if( query( m ) >= in ){
                    l = m;
                }
                else{
                    r = m - 1;
                }
            }
            //printf("\n");
            int upper = l;
            if( upper == lower && query(upper) == in )ans += all[i+1].po - all[i].po;
            else if( upper != lower ) ans += ( upper - lower+1 ) * (all[i+1].po - all[i].po);
    }
    printf("%d",ans);
    return 0;
}
/*
3 3
1 1 4 1
2 2 2 2
3 3 1 3
*/
