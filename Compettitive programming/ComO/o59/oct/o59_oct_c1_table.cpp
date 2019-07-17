#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, t, va, type;
    bool operator<( const qq &k )const{
        return va > k.va;
    }
}now;
priority_queue<qq> q;
int r, c, qe;
int ta[330][5050], ro[330], ti[330][5050], tim[330];
int main()
{
    scanf("%d %d %d",&r,&c,&qe);
    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            q.push({ i, j, 1, 0, 1 });
        }
    }
    for( int z = 1 ; z <= qe ; z++ ){
        int op;
        scanf("%d",&op);
        if( op == 1 ){
             int a, b, c;
             scanf("%d %d %d",&a,&b,&c);
             ta[a][b] = c;
             ti[a][b] = z;
             q.push({ a, b, z, c, op });
        }
        else if( op == 2 ){
            int a, b;
            scanf("%d %d",&a,&b);
            ro[a] = b;
            tim[a] = z;
            q.push({ a, 0, z, b, op });
        }
        else if( op == 3 ){
            int a, b;
            scanf("%d %d",&a,&b);
            if( ti[a][b] > tim[a] )printf("%d\n",ta[a][b]);
            else printf("%d\n",ro[a]);
        }
        else{
            while( !q.empty() ){
                now = q.top();
                if( now.type == 1 ){
                    if( now.va != ta[now.x][now.y] || tim[now.x] > now.t )q.pop();
                    else{
                        printf("%d\n",now.va);
                        break;
                    }
                }
                else{
                    if( tim[now.x] != now.t ){
                        q.pop();
                        continue;
                    }
                    int ch = 0;
                    for( int i = 1 ; i <= c ; i++ ){
                        ch = 0;
                        if( ti[now.x][i] < now.t ){
                            printf("%d\n",now.va);
                            ch = 1;
                            break;
                        }
                    }
                    if( ch ) break;
                    else q.pop();
                }
            }
        }
    }
    return 0;
}


