#include<bits/stdc++.h>

using namespace std;

int n, k, m, i, j, pos, check[500010];
char ans[500010];
struct signal{
    int s, e, p, how;
    bool operator<( const signal &t )const{
        return s < t.s;
    }
}allsig[500010];
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for( i = 0 ; i < k ; i++ ){
        scanf("%d %d",&allsig[i].s,&allsig[i].e);
        allsig[i].p = i + 1;
    }
    sort( allsig , allsig + k );
    ans[0] = 'Y';
    last = allsig[0].e;
    check[allsig[0].e]++;
    for( i = 1 ; i < k ; i++ ){

    }
}
