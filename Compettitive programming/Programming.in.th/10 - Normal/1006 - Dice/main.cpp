#include<stdio.h>
#include<string.h>
int amount, i, j, k;
int main()
{
    int sol[10];
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        char turn[1001];

        scanf("%s",turn);
        int up = 1, down = 6, forwards = 2, backward = 5, right = 4, left = 3, t;

        int len = strlen( turn );

        for( j = 0 ; j < len ; j++ )
        {
            if( turn[j] == 'F')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = down;
                //printf("t : %d\n",t);
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                down = forwards;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                forwards = up;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                up = backward;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                backward = t;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n\n",up,down,forwards,backward,right,left);
            }
            else if( turn[j] == 'B')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = down;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                down = backward;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                backward = up;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                up = forwards;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                forwards = t;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n\n",up,down,forwards,backward,right,left);
            }
            else if( turn[j] == 'L')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = up;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                up = right;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                right = down;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                down = left;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                left = t;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n\n",up,down,forwards,backward,right,left);
            }
            else if( turn[j] == 'R')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = up;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                up = left;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                left = down;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                down = right;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                right = t;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n\n",up,down,forwards,backward,right,left);
            }
            else if( turn[j] == 'C')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = forwards;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                forwards = right;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                right = backward;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                backward = left;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                left = t;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
            }
            else if( turn[j] == 'D')
            {
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                t = forwards;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                forwards = left;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                left = backward;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                backward = right;
                //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
                right = t;
               //printf("up: %d  down : %d forward : %d backward : %d right : %d left : %d\n",up,down,forwards,backward,right,left);
            }
        }
        sol[k] = forwards;
        k++;
    }
    for( i = 0 ; i < k ; i++ )
    {
        printf("%d ",sol[i]);
    }
    return 0;
}
