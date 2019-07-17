#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> g[300100];
int st[300100], lv[300100];
int mic[25][300100];
int lca( int a, int b )
{
    if( lv[a] > lv[b] )swap( a, b );
    for( int i = 20 ; i >= 0 ; i-- ){
        if( lv[mic[i][b]] < lv[a] )continue;
        b = mic[i][b];
    }
    if( a == b )return a;
    for( int i = 20 ; i >= 0 ; i-- ){
        if( mic[i][a] != mic[i][b] ){
            a = mic[i][a];
            b = mic[i][b];
        }
    }
    return mic[0][a];
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        char c;
        int no;
        scanf(" %c",&c);
        if( c == 'a' ){
            scanf("%d",&no);
            g[st[no]].push_back( i );
            st[i] = i;
            lv[i] = lv[st[no]] + 1;
            mic[0][i] = st[no];
            for( int k = 1 ; k <= 20 ; k++ ){
                mic[k][i] = mic[k-1][mic[k-1][i]];
            }
        }
        else if( c == 'b' ){
            scanf("%d",&no);
            st[i] = st[no];
            if( st[i] == 0 )printf("-1\n");
            else printf("%d\n",st[i]);
            st[i] = mic[0][st[no]];
        }
        else{
            int a, b;
            scanf("%d %d",&a,&b);
            st[i] = st[a];
            printf("%d\n",lv[lca( st[a], st[b] )]);
        }
    }
    return 0;
}
