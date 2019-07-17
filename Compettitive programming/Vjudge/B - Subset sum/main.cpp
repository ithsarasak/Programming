#include<bits/stdc++.h>
long long i, j, a, n, b, num[40], sum1[150000], sum2[150000], size1, size2,ans, lowbound = 0, upbound;
int compare( const void *a , const void *b ){
    return ( *( int *)a - *( int *)b );
}
int compare2( const void *a , const void *b ){
    return ( *( int *)b - *( int *)a );
}
int main()
{
    scanf("%lld %lld %lld",&n,&a,&b);
    for( i = 0 ; i < n ; i++ ){
        scanf("%lld",&num[i]);
    }
    for(int i = 0 ; i < (1<< ( n / 2 ) );i++){
        int sum = 0 ;
        for(int j = 0 ; j < ( n / 2 ) ; j ++){
            if((1<<j)&i)sum += num[j];
        }
        sum1[i] = sum;
        size1++;
    }
    for(int i = 0 ; i < (1<<  ( n - ( n / 2 ) ) );i++){
        int sum = 0 ;
        for(int j = 0 ; j < ( n - ( n / 2 ) ) ; j ++){
            if((1<<j)&i)sum += num[j + n / 2];
        }
        sum2[i] = sum;
        size2++;
    }
    qsort( sum1 , size1 , sizeof( long long ) , compare2 );
    qsort( sum2 , size2 , sizeof( long long ) , compare );
    /*for( i = 0 ; i < size1 ; i++ ){
        printf("%d ",sum1[i]);
    }
    printf("\n");
    for( i = 0 ; i < size2 ; i++ ){
        printf("%d ",sum2[i]);
    }
    printf("\n");*/
    for( i = 0 ; i < size2 ; i++ ){
        if( sum1[0] + sum2[i] >= a ){
            lowbound = i;
            break;
        }
    }
    for( i = lowbound ; i < size2 ; i++ ){
        if( sum1[0] + sum2[i] <= b ){
            upbound = i;
        }
        else{
            break;
        }
    }
    ans += upbound - lowbound + 1;
    for( i = 1 ; i < size1 ; i++ ){
        if( sum1[i] + sum2[lowbound] < a ){
            for( j = lowbound ; j < size2 ; j++ ){
                if( sum1[i] + sum2[j] >= a ){
                    lowbound = j;
                    break;
                }
            }
        }
        if( sum1[i] + sum2[upbound] < b ){
            for( j = upbound ; j < size2 ; j++ ){
                if( sum1[i] + sum2[j] <= b ){
                    upbound = j;
                }
                else{
                    break;
                }
            }
        }
        if( sum1[i] + sum2[upbound] <= b && sum1[i] + sum2[lowbound] >= a ){
            ans += upbound - lowbound + 1;
        }
        //printf("%d %d\n",pos1,pos2);
    }
    printf("%lld",ans);
    return 0;
}
