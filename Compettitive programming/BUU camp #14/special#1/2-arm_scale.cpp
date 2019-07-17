#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
struct node {
    int f;
    char c;
    int t;
};
vector<node> query;
vector<int> g[N], g2[N];
int lv[N], lv2[N], n, k, v, par[N], in[N], in2[N];
queue<int> q;

int findroot( int num ) {
    if( par[num] == num ) return num;
    else return par[num] = findroot( par[num] );
}

int main()
{
    scanf("%d %d %d",&k,&n,&v);
    for( int i = 1 ; i <= n ; i++ ) par[i] = i;
    for( int i = 0, f, t ; i < v ; i++ ) {
        char c;
        scanf("%d %c%d",&f,&c,&t);
        if( c == '=' ) {
            int a = findroot( f ), b = findroot( t );
            if( a != b ) par[a] = b;
            // printf("a%d b%d\n",a,b);
        }
        query.push_back({ f, c, t });
    }
    if( k == 1 ) {
        for( int i = 1 ; i <= n ; i++ ) printf("K1\n");
        return 0;
    }
    for( int i = 0 ; i < v ; i++ ) {
        if( query[i].c == '=' ) continue ;
        int f = findroot( query[i].f ) , t = findroot( query[i].t );
        // cout << f << " " << t << endl;
        if( query[i].c == '<' ) swap( f, t );
        g[f].emplace_back( t );
        g2[t].emplace_back( f );
        // cout << i << " " << f << " " << t << endl;
        in[t]++, in2[f]++;
    }
    // for( int i = 1 ; i <= n ; i++ ) cout << findroot( i ) << " " << in[par[i]] << endl;
    for( int i = 1 ; i <= n ; i++ ) {
        int rt = findroot( i );
        if( in[rt] == 0 && rt == i ) q.push( rt ), lv[rt] = 1;
    }
    while( !q.empty() ) {
        int t = q.front();
        q.pop();
        // cout << t << endl;
        for( int i : g[t] ) {
            int rt = findroot( i );
            lv[rt] = max( lv[rt], lv[t] + 1 );
            if( --in[rt] == 0 ) q.push( rt );
        }
    }
    // for( int i = 1 ; i <= n ; i++ ) cout << lv[i] << " ";
    // cout << endl;
    for( int i = 1 ; i <= n ; i++ ) {
        int rt = findroot( i );
        if( in2[rt] == 0 && rt == i ) q.push( rt ), lv2[rt] = 1;
    }
    while( !q.empty() ) {
        int t = q.front();
        q.pop();
        for( int i : g2[t] ) {
            int rt = findroot( i );
            lv2[rt] = max( lv2[rt], lv2[t] + 1 );
            if( --in2[rt] == 0 ) q.push( rt );
        }
    }
    for( int i = 1 ; i <= n ; i++ ) {
        // cout << i << " " << par[i] << " " << lv[par[i]] << " " << lv2[par[i]] << endl;
        int rt = findroot( i );
        if( lv[rt] + lv2[rt] - 1 == k ) printf("K%d\n",lv2[rt]);
        else printf("?\n");
    }
    return 0;
}