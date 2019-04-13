#include<stdio.h>
char phone[8][5] = {"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}, word[1000];
int amount, i, size, k, start, time, cx, cy;
int main()
{
    scanf("%d",&amount);
    scanf("%d %d",&start,&time);

    if( start == 7 || start == 9 ){
        word[size] = phone[start-2][(time-1)%4];
        size++;
    }
    else if( start != 1 ){
        word[size] = phone[start-2][(time-1)%3];
        size++;
    }

    for( i = 0 ; i < amount - 1 ; i++ )
    {
        scanf("%d %d %d",&cx,&cy,&time);

        if( start == 1 || start == 2 || start == 3 ){
            start += cx;
            if( start < 1 ){
                start = 1;
            }
            else if( start > 3 ){
                start = 3;
            }

            if( start == 1 )
            {
                start += ( 3 * cy );
                if( start < 1 )
                {
                    start = 1;
                }
            }
            else if( start == 2 )
            {
                start += ( 3 * cy );
                if( start < 2 )
                {
                    start = 2;
                }
            }
            else if( start == 3 )
            {
                start += ( 3 * cy );
                if( start <= 3 )
                {
                    start = 3;
                }
            }
        }
        else if( start == 4 || start == 5 || start == 6 ){
                start += cx;
            if( start < 4 ){
                start = 4;
            }
            else if( start > 6 ){
                start = 6;
            }

            if( start == 4 )
            {
                start += ( 3 * cy );
                if( start < 1 )
                {
                    start = 1;
                }
                else if( start > 7 )
                {
                    start = 7;
                }
            }
            else if( start == 5 )
            {
                start += ( 3 * cy );
                if( start < 2 )
                {
                    start = 2;
                }
                else if( start > 8 )
                {
                    start = 8;
                }
            }
            else if( start == 6 )
            {
                start += ( 3 * cy );
                if( start < 3 )
                {
                    start = 3;
                }
                else if( start > 9 )
                {
                    start = 9;
                }
            }
        }
        else if( start == 7 || start == 8 || start == 9 ){
                start += cx;
            if( start < 7 ){
                start = 7;
            }
            else if( start > 9 ){
                start = 9;
            }

            if( start == 7 )
            {
                start += ( 3 * cy );
                if( start > 7 )
                {
                    start = 7;
                }
            }
            else if( start == 8 )
            {
                start += ( 3 * cy );
                if( start > 8 )
                {
                    start = 8;
                }
            }
            else if( start == 9 )
            {
                start += ( 3 * cy );
                if( start > 9 )
                {
                    start = 9;
                }
            }
        }
        //printf("%d\n",start);
        if( start == 1 ){
            for( k = 0 ; k < time ; k++ )
            {
                if( size != 0 ){
                    size--;
                }
            }
        }
        else if( start == 7 || start == 9 ){
            word[size] = phone[start-2][(time-1)%4];
            size++;
        }
        else{
            word[size] = phone[start-2][(time-1)%3];
            size++;
        }
    }
    if( size == 0 ){
        printf("null");
    }
    else{
        printf("%s",word);
    }
}
