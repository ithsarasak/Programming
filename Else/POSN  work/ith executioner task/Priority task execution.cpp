#include<bits/stdc++.h>

using namespace std;

struct node{
    int prinum, time;
    char taskID[2];
    bool operator<( const node &k )const{
        return k.prinum < prinum;
    }
}temp;

priority_queue< node > work;
queue< node > inqueue;
int n, r, co;
int main()
{
    scanf("%d %d",&n,&r);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",temp.taskID);
        scanf("%d %d",&temp.prinum,&temp.time);
        if( i >= 4 ){
            inqueue.push( temp );
        }
        else{
            work.push( temp );
        }
    }
    for( int i = 0 ; i < r ; i++ ){
        if( !work.empty() ){
            temp = work.top();
            work.pop();
            if( temp.time > 2 ){
                temp.time -= 2 ;
                temp.prinum++;
                work.push( temp );
            }
            else{
                if( !inqueue.empty() ){
                    temp = inqueue.front();
                    work.push( temp );
                    inqueue.pop();
                }
            }
        }
        else{
            printf("%d",i);
            return 0;
        }
    }
    printf("%d ",work.size());
    while( !work.empty() ){
        co++;
        temp = work.top();
        work.pop();
        if( temp.time > 2 ){
            temp.time -= 2 ;
            temp.prinum++;
            work.push( temp );
        }
    }

    printf("%d",co);
    return 0;
}
