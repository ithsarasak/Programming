#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

const int N = 1e3;

int m ,n;
int a[N][N], r[N][N], c[N][N], mxro[N], mxco[N];
set<int> s;
unordered_map<int,vi > ma;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    scanf("%d %d",&m,&n);
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ;j < n ; j++ ){
            scanf("%d",&a[i][j]);
        }
    }
    for( int i = 0 ;i < m ; i++ ){
        s.clear();
        ma.clear();
        for(int j = 0;j < n;j++){ s.insert(a[i][j]); ma[a[i][j]].push_back(j); }
        mxro[i] = s.size();
        int cnt = 1;
        for(auto it = s.begin();it != s.end();it++)
        {
            for(int j = 0;j < ma[*it].size();j++)
                r[i][ma[*it][j]] = cnt;
            cnt++;
        }
    }

    for( int i = 0 ;i < n ; i++ ){
        s.clear();
        ma.clear();
        for( int j = 0 ; j < m ; j++ ){ 
            s.insert( a[j][i] ); 
            ma[a[j][i]].push_back( j );
        }
        mxco[i] = s.size();
        int cnt = 1;
        for( auto it = s.begin() ; it != s.end() ; it++ ){
            for( int j = 0 ; j < ma[*it].size() ; j++ ){
                c[ma[*it][j]][i] = cnt;
            }
            cnt++;
        }
    }
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            printf("%d ",max(mxro[i]+max(r[i][j],c[i][j])-r[i][j],mxco[j]+max(r[i][j],c[i][j])-c[i][j]) );
        }
        printf("\n");
    }
    return 0;
}
