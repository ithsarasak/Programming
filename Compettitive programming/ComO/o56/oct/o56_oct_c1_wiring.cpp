#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, p;
}t;
int tt;
int n;
int num1[100100], num2[100100], mark[100100];
vector<int> g[100100];
queue<qq> q;
int main()
{
    scanf("%d",&tt);
    while( tt-- ){
        scanf("%d",&n);
        for( int i = 0 ; i <= 100000 ; i++ )g[i].clear();
        memset( mark, 0, sizeof mark );
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&num1[i]);
        }
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&num2[i]);
        }
        for( int i = 0 ; i < n ; i++ ){
            if( num1[i] != 0 && num2[i] != 0 ){
                g[num1[i]].push_back( num2[i] );
            }
        }
        int ch = 0, cnt = 1;
        for( int i = 1 ; i <= n ; i++ ){
            if( !mark[i] ){
                q.push({ i, -1 });
                while( !q.empty() ){
                    t = q.front();
                    q.pop();
                    //printf("%d ",t.no);
                    mark[t.no] = cnt;
                    for( int i = 0 ; i < g[t.no].size() ; i++ ){
                        if( mark[g[t.no][i]] == cnt && g[t.no][i] != t.no ){
                            ch = 1;
                            break;
                        }
                        else if( mark[g[t.no][i]] == 0 )q.push({ g[t.no][i], t.no });
                    }
                    if( ch )break;
                }
                cnt++;
                //printf("\n");
                if( ch )break;
            }
        }
        if( ch )printf("NO\n");
        else printf("YES\n");
    }
}
