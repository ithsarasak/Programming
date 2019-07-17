#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    long long x, y, r;
}circle[100000];
bool compare( const node &a , const node &b )
{
    return a.x > b.x;
}
long long i, j, amount;
long long counts;
int main()
{
    scanf("%lld",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf("%lld %lld %lld",&circle[i].x,&circle[i].y,&circle[i].r);
    }

    sort( circle , circle + amount , compare );

    /*for( i = 0 ; i < amount ; i++ ){
        printf("%d %d %d\n",circle[i].x,circle[i].y,circle[i].r);
    }*/

    for( i = 0 ; i < amount ; i++ ){
        for( j = i + 1 ; j < amount ; j++ ){
            long long temp1 = circle[i].x - circle[j].x;
            long long temp2 = circle[i].y - circle[j].y;
            long long temp3 = circle[i].r + circle[j].r;
            if( temp1 >= 20 ){
                break;
            }
            else{
                if( ( temp1 * temp1 ) + ( temp2 * temp2 ) < ( temp3 * temp3 ) ){
                    counts++;
                }
            }
        }
    }
    printf("%lld",counts);
}

