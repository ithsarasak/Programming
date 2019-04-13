#include<bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
    bool operator<( const point &k )const{
        if( x != k.x ){
            return x < k.x;
        }
        else{
            return y > k.y;
        }
    }
}bomb[1000010], temp;
struct point2{
    int x1,y1;
    bool operator<( const point2 &k )const{
        if( x1 != k.x1 ){
            return x1 < k.x1;
        }
        else{
            return y1 < k.y1;
        }
    }
}ans[1000010];
int n, i, j,count1;
stack< point > s;
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d %d",&bomb[i].x,&bomb[i].y);
    }
    sort( bomb , bomb + n );
    s.push( bomb[0] );
    for( i = 1 ; i < n ; i++ ){
        temp = s.top();
        while( bomb[i].y > temp.y && !s.empty() ){
            s.pop();
            if( !s.empty() )
                temp = s.top();
        }
        s.push( bomb[i] );
    }
    while( !s.empty() ){
        temp = s.top();
        ans[count1].x1 = temp.x;
        ans[count1].y1 = temp.y;
        s.pop();
        count1++;
    }
    sort( ans , ans + count1 );
    for( i = 0 ; i < count1 ; i++ ){
        printf("%d %d\n",ans[i].x1,ans[i].y1);
    }
    return 0;
}
