#include<stdio.h>
#include<algorithm>

using namespace std;

struct pos{
    int x, y;
}ans[1000001], allbomb[1000001], temp[1000001];
int bomb, i, j, k, maxy, start, ends, num ,maxi;
bool compare( const pos &a, const pos &b ){
    return ( a.x > b.x );
}
bool compare2( const pos &a, const pos &b ){
    return ( a.x < b.x );
}
bool compare3( const pos &a, const pos &b ){
    return ( a.y > b.y );
}
int main()
{
    scanf("%d",&bomb);

    for( i = 0 ; i < bomb ; i++ ){
        scanf("%d %d",&allbomb[i].x,&allbomb[i].y);
    }
    sort( allbomb , allbomb + bomb , compare );
    /*for( i = 0 ; i < bomb ; i++ ){
        printf("%d %d\n",allbomb[i].x,allbomb[i].y);
    }*/

    ans[k] = allbomb[0];
    k++;
    maxy = ans[0].y;
    for( i = 1 ; i < bomb ; i++ ){
        if( allbomb[i].y >= maxy ){
            ans[k] = allbomb[i];
            k++;
            maxy = allbomb[i].y;
            maxi = i;
        }
        else if( allbomb[i].x == allbomb[maxi].x ){
            //printf("%d %d\n",allbomb[i].x,allbomb[i].y);
            bool check = false;
            for( j = 0 ; j < i ; j++ ){
                //printf("%d ",allbomb[j].y);
                if( allbomb[j].y > allbomb[i].y && allbomb[j].x != allbomb[i].x ){
                    check = true;
                }
                else if( allbomb[j].x == allbomb[i].x ){
                    break;
                }
            }
            //printf("\n");
            if( !check ){
                ans[k] = allbomb[i];
                k++;
            }
        }
    }
    sort( ans , ans + k , compare2 );
    temp[num] = ans[0];
    start = 0;
    ends = 0;
    num++;
    for( i = 1 ; i <= k ; i++ ){
        /*printf("ans.x : %d\n",ans[i].x);
        printf("temp.x : %d\n",temp[num-1].x);*/
        if( temp[num-1].x == ans[i].x ){
            temp[num] = ans[i];
            num++;
            if( num - 1 == 0 ){
                start = i;
            }
            if( ans[i].x != ans[i+1].x ){
                ends = i;
            }
        }
        else{
            sort( temp , temp + num , compare3 );
            for( j = start ; j <= ends ; j++ ){
                //printf("%d ",temp[j-start]);
                ans[j] = temp[j-start];
            }
            num = 0;
            temp[num] = ans[i];
            start = i;
            ends = i;
            num++;
            //printf("\n");
        }
    }
    for( i = 0 ; i < k ; i++ ){
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
