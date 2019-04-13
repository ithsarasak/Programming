#include<bits/stdc++.h>

using namespace std;
struct po{
    int idx, va;
    bool operator<( const po &k )const{
        return idx < k.idx;
    }
};
vector<po> eve;
int n;
int f, t, sum;
long long mo;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&f,&t);
        eve.push_back({ f , 1 });
        eve.push_back({ t + 1 , -1 });
    }
    sort( eve.begin(), eve.end() );
    /*for( int i = 0 ; i < eve.size() ; i++ ){
        printf("%d %d\n",eve[i].idx,eve[i].va);
    }*/
    for( int i = 0 ; i < eve.size() - 1 ; i++ ){
        sum += eve[i].va;
        mo += ( long long )( max( 0,( sum - 1 ) ) ) * ( long long )( eve[i+1].idx - eve[i].idx );
    }
    printf("%lld",mo);
    return 0;
}
