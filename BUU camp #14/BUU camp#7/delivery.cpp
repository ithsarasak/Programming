#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
};
struct qq{
    int no, lv;
}te;
queue<qq> q;
vector<ee> e;
vector<int> g[200200];
int sp[15][200200];
int k, l, qe;
int main()
{
    memset( sp, 127, sizeof sp );
    scanf("%d %d %d",&k,&l,&qe);
    for( int i = 1 ; i <= (1<<(k-1))-1 ; i++ ){
        g[2*i].push_back(i);
        g[2*i+1].push_back(i);
        g[i].push_back(2*i);
        g[i].push_back(2*i+1);
        g[2*i+(1<<k)].push_back(i+(1<<k));
        g[2*i+(1<<k)+1].push_back(i+(1<<k));
        g[i+(1<<k)].push_back(2*i+(1<<k));
        g[i+(1<<k)].push_back(2*i+(1<<k)+1);
    }
    for( int i = 0 ; i < l ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g[t].push_back( f );
        e.push_back({ f, t });
    }
    for( int i = 0 ; i < l ; i++ ){
        q.push({ e[i].f, 0 });
        sp[i][e[i].f] = 0;
        while( !q.empty() ){
            te = q.front();
            q.pop();
            for( int j = 0 ; j < g[te.no].size() ; j++ ){
                if( sp[i][g[te.no][j]] > te.lv + 1 ){
                    sp[i][g[te.no][j]] = te.lv + 1;
                    q.push({ g[te.no][j], te.lv + 1 });
                }
            }
        }
    }
    while( qe-- ){
        int f, t;
        scanf("%d %d",&f,&t);
        if( f > t )swap( f, t );
        int mi = 1e9;
        for( int i = 0 ; i < l ; i++ ){
            mi = min( mi, sp[i][f] + sp[i][t] );
        }
        if( f < ( 1 << k ) && t > ( 1 << k ) ){
            printf("%d\n",mi);
        }
        else{
            if( f > ( 1 << k ) && t > ( 1 << k ) ){
                f -= ( 1 << k );
                t -= ( 1 << k );
            }
            int cou = 0;
            while( f != t ){
                if( f > t )f /= 2;
                else       t /= 2;
                cou++;
            }
            printf("%d\n",min( mi, cou ));
        }
    }
    return 0;
}
