#include<bits/stdc++.h>

using namespace std;
int n;
int num[100100];
char ans[100100];
queue<int> q;
vector<int> g[100100];
int ind[100100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = i + num[i] ; j <= n ; j += num[i] ){
            if( num[j] > num[i] ){
                g[j].push_back( i );
                ind[i]++;
            }
        }
        for( int j = i - num[i] ; j > 0 ; j -= num[i] ){
            if( num[j] > num[i] ){
                g[j].push_back( i );
                ind[i]++;
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ )ans[i] = 'B';
    for( int i = 1 ; i <= n ; i++ ){
        if( ind[i] == 0 )q.push( i );
    }
    while( !q.empty() ){
        int t = q.front();
        q.pop();
        for( int i = 0 ; i < g[t].size() ; i++ ){
            ind[g[t][i]]--;
            if( ans[t] == 'B' )ans[g[t][i]] = 'A';
            if( ind[g[t][i]] == 0 ){
                q.push( g[t][i] );
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ )cout << ans[i];
    return 0;
}
