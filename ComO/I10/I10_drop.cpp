#include<bits/stdc++.h>

using namespace std;
int n, l, h, mark[5100];
int ma;
int main()
{
    scanf("%d %d %d",&h,&l,&n);
    h += l;
    for( int i = 0 ; i < n ; i++ ){
        int drop;
        scanf("%d",&drop);
        if( drop <= h && drop >= l ){
            mark[drop]++;
            ma = max( ma, mark[drop] );
        }
    }
    cout << ma;
}
