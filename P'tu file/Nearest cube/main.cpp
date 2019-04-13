#include<stdio.h>
int cases, i;
int main()
{
    scanf("%d",&cases);
    for( i = 0 ; i < cases ; i++ ){
        long long num, start, end, mid, need;
        scanf("%lld",&num);
        start = 0;
        end = num;
        if( num == 1 ){
            printf("Case #%d: 1 0\n",i + 1);
        }
        else{
            while( 1 ){
                mid = ( start + end ) / 2;
                if(  ( mid + 1 ) > 2 * 1000000 ){
                    end = mid;
                }
                else{
                    if( ( mid * mid * mid < num && ( mid + 1 ) * ( mid + 1 ) * ( mid + 1 ) > num ) || ( mid * mid * mid ) == num ){
                        break;
                    }
                    else if( mid * mid * mid > num ){
                        end = mid;
                    }
                    else{
                        start = mid;
                    }
                }
            }
            if( num - ( mid * mid * mid ) < ( mid + 1 ) * ( mid + 1 ) * ( mid + 1 ) - num ){
                need = num - ( mid * mid * mid );
                printf("Case #%d: %lld %lld\n",i + 1,mid,need);
            }
            else{
                need = ( mid + 1 ) * ( mid + 1 ) * ( mid + 1 ) - num;
                printf("Case #%d: %lld %lld\n",i + 1,mid + 1,need);
            }
        }
    }
    return 0;
}
