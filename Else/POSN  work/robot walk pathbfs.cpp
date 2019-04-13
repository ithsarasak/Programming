#include<bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
}t;
queue< point > q;
int l, h, c;
int main()
{
    scanf("%d %d",&l,&h);
    q.push({ 0, 0 });
    while( !q.empty() ){
        t = q.front();
        q.pop();
        if( t.x == l && t.y == h ){
            c++;
        }
        else{
            if( t.x + 1 <= l ){
                q.push({ t.x + 1 , t.y });
            }
            if( t.y + 1 <= h ){
                q.push({ t.x , t.y + 1 });
            }
        }
    }
    printf("%d",c);
    return 0;
}
