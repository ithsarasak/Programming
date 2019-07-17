#include<stdio.h>
#include<algorithm>

using namespace std;

struct worm{
    long long destroy, electric;
    double worth;
    bool operator<( const worm &t )const{
        if( worth > t.worth ){
            return  true;
        }
        else{
            return false;
        }
    }
}worms[100100],ans;
int allworm, i, j;
long long temp1,temp2;
double temp3;
int main()
{
    scanf("%d",&allworm);
    for( i = 0 ; i < allworm ; i++ ){
        scanf("%lld %lld",&worms[i].destroy,&worms[i].electric);
        worms[i].worth = ( double )worms[i].destroy / worms[i].electric;
    }
    sort( worms , worms + allworm );
    /*for( i = 0 ; i < allworm ; i++ ){
        printf("%lld %lld %lf\n",worms[i].destroy,worms[i].electric,worms[i].worth);
    }*/
    ans = worms[0];
    temp1 += worms[0].destroy;
    temp2 += worms[0].electric;
    for( i = 1 ; i < allworm ; i++ ){
        temp1 += worms[i].destroy;
        if( temp2 < worms[i].electric ){
            temp2 = worms[i].electric;
        }
        temp3 = ( double )temp1 / temp2;
        if( temp3 > ans.worth ){
            ans.destroy = temp1;
            ans.electric = temp2;
            ans.worth = temp3;
        }
    }
    printf("%lld %lld",ans.destroy,ans.electric);
    return 0;
}
