#include<bits/stdc++.h>

using namespace std;
struct y{
    int a, b;
}yan[50100];
vector<int> v;
int n, m;
int li[100100];
int fen[200100];
int ans = 0;
int main()
{
    v.push_back( 0 );
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&yan[i].a,&yan[i].b);
        yan[i].a++,yan[i].b++;
        v.push_back(yan[i].a);
        v.push_back(yan[i].b);
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&li[i]);
        li[i]++;
        v.push_back(li[i]);
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < m ; i++ ){
        li[i] = lower_bound( v.begin(), v.end(), li[i] ) - v.begin();
        for( int j = li[i] ; j <= 200000 ; j += ( j & -j ) )fen[j] += 1;
        //printf("li : %d\n",li[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        yan[i].a = lower_bound( v.begin(), v.end(), yan[i].a ) - v.begin();
        yan[i].b = lower_bound( v.begin(), v.end(), yan[i].b ) - v.begin();
        //printf("yan : %d %d\n",yan[i].a,yan[i].b);
        int sum1 = 0, sum2 = 0;
        for( int j = yan[i].b - 1 ; j > 0 ; j -= ( j & -j ) ){
            sum1 += fen[j];
            sum1 %= 2007;
        }
        for( int j = yan[i].a ; j > 0 ; j -= ( j & -j ) ){
            sum2 += fen[j];
            sum2 %= 2007;
        }
        ans += ( sum1 - sum2 + 2007 )% 2007;
        ans %= 2007;
    }
    printf("%d",ans);
}
