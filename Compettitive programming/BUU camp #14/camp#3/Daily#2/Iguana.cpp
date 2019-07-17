#include<bits/stdc++.h>

using namespace std;
struct eve{
    int po, va;
    bool operator<( const eve &k )const{
        if( po == k.po ) return va < k.va;
        else return po < k.po;
    }
};
vector<eve> all;
int n, m, sum, tap = 0, color;
char ch;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        all.push_back({ f, 1 });
        all.push_back({ t+1, -1 });
    }
    scanf(" %c",&ch);
    if( ch == 'R' )color = 0;
    else if( ch == 'G' )color = 1;
    else color = 2;
    all.push_back({ 1, 0 });
    all.push_back({ n+1, 0 });
    sort( all.begin(), all.end() );
    for( int i = 0 ; i < all.size()-1 ; i++ ){
        sum += all[i].va;
        int num = all[i+1].po - all[i].po;
        tap += ((color-((sum+3)%3)+3)%3)*num;
    }
    printf("%d",tap);
    return 0;
}
