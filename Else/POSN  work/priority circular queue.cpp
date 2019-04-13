#include<bits/stdc++.h>

using namespace std;

struct node{
    int data, prinum;
    bool operator<( const node &k )const{
        return k.prinum < prinum;
    }
};

priority_queue< node > q;
int c;
int main()
{
    while( 1 ){
        printf("1.Enqueue 2.Dequeue 3.Show 4.Size 5.Exit\n");
        scanf("%d",&c);
        if( c == 1 ){
            if( q.size() == 4 ){
                printf("Queue Overflow!\n");
            }
            else{
                int tpri, tdata;
                printf("Priority number : ");
                scanf("%d",&tpri);
                printf("Data : ");
                scanf("%d",&tdata);
                q.push({ tdata , tpri });
            }
        }
        else if( c == 2 ){
            if( q.empty() ){
                printf("Queue Underflow!\n");
            }
            else{
                q.pop();
            }
        }
        else if( c == 3 ){
            if( q.empty() ){
                printf("Priority queue is empty.\n");
            }
            else{
                priority_queue< node > temp = q;
                while( !temp.empty() ){
                    printf("%d ",temp.top().data);
                    temp.pop();
                }
                printf("\n");
            }
        }
        else if( c == 4 ){
            printf("Size : %d\n",q.size());
        }
        else{
            break;
        }
    }
    return 0;
}
