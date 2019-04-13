#include<bits/stdc++.h>

using namespace std;
struct pe{
    int po, na;
    bool operator<( const pe &k )const{
        return po < k.po;
    }
}all[50010], f, b;
int n, ans = 1e9, cnt, cn;
deque<pe> q;
unordered_map<int,int> mark, mm;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&all[i].po,&all[i].na);
        mm[all[i].na]++;
    }
    sort( all, all + n );
    q.push_back({ all[0].po, all[0].na });
    mark[all[0].na]++;
    for( int i = 1 ; i < n ; i++ ){
        q.push_back({ all[i].po, all[i].na });
        mark[all[i].na]++;
        while( mark[all[i-q.size()+1].na] > 1 ){
            //printf("%d %d %d %d\n",mark[all[i-q.size()+1].na],all[i-q.size()+1].na,all[i-q.size()+1].po,i);
            mark[all[i-q.size()+1].na]--;
            q.pop_front();
        }
        if( mark.size() == mm.size() ){
            f = q.front();
            b = q.back();
            //printf("%d %d %d\n",i,f.po,b.po);
            ans = min( ans, b.po - f.po + 1 );
        }

    }
    printf("%d",ans);
    return 0;
}
/*
6
20 1
15 9
16 1
5 1
12 5
10 1
*/
