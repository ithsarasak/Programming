#include<bits/stdc++.h>

using namespace std;

list< int > q;

int c;
int main()
{
    while( 1 ){
        printf("1.Enqueue 2.Dequeue 3.Show 4.Size 5.Exit\n");
        scanf("%d",&c);
        if( c == 1 ){
            if( q.size() == 5 ){
                printf("Queue Overflow!\n");
            }
            else{
                int t;
                scanf("%d",&t);
                q.push_back( t );
            }
        }
        else if( c == 2 ){
            if( q.empty() ){
                printf("No element to dequeue\n");
            }
            else{
                q.pop_front();
            }
        }
        else if( c == 3 ){
            if( q.empty() ){
                printf("No element in queue\n");
            }
            else{
                for( list< int >::iterator it = q.begin() ; it != q.end() ; it++ ){
                    printf("%d ",*it);
                }
                printf("\n");
            }
        }
        else if( c == 4 ){
            printf("size : %d\n",q.size());
        }
        else{
            break;
        }
    }
    return 0;
}
