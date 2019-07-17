#include<bits/stdc++.h>

int q[10000];
int fron = -1, rear = -1, c, data;
int main()
{
    while( 1 ){
        printf("1.Enqueue 2.Dequeue 3.Show 4.Exit\n");
        scanf("%d",&c);
        if( c == 1 ){
            if( ( fron == 0 && rear == 4 ) || ( fron == rear + 1 ) ){
                printf("Queue overflow!\n");
            }
            else{
                if( rear == 4 && fron != 0 ){
                        rear = -1;
                }
                q[++rear] = data;
                if( fron == -1 ){
                        fron = 0;
                }
            }
        }
        else if( c == 2 ){
            if( fron == -1 && rear == -1 ){
                printf("No element to dequeue\n");
            }
            else{
                fron++;
                if( fron == 5 ){
                    fron = 0;
                }
                if( fron - 1 == rear ){
                    fron = rear = -1;
                }
            }
        }
        else if( c == 3 ){
            if( fron == -1 ){
                printf("No element in queue\n");
            }
            else{
                int i = fron;
                printf("Queue : ");
                if( fron <= rear ) {
                        while( i <= rear )
                            printf("%d ",q[i++]);
                }
                else{
                    while( i <= 4 )
                        printf("%d", q[i++]);
                    i = 0;
                    while( i <= rear )
                        printf("%d",q[i++]);
                }
            }
        }
        else{
            break;
        }
    }
    return 0;
}
