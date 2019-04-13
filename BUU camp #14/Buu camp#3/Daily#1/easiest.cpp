#include<bits/stdc++.h>

using namespace std;
priority_queue<int> q;
int o, n;
char p;
int main()
{
    scanf("%d",&o);
    while( o-- ){
        scanf(" %c",&p);
        if( p == 'A' ){
            scanf("%d",&n);
            q.push( -1*n );
        }
        else{
            if( q.empty() ) printf("-1\n");
            else{
                printf("%d\n",q.top()*-1);
                q.pop();
            }
        }
    }
    return 0;
}
