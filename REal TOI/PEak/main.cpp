#include<bits/stdc++.h>
int n, k, i, j, peak[5000010], high[5000010], high2[5000010], count1;
int compare( const void *a , const void *b ){
    return ( *( int *)a - *( int *)b );
}
int compare2( const void *a , const void *b ){
    return ( *( int *)b - *( int *)a );
}
int main()
{
    scanf("%d %d",&n,&k);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&peak[i]);
    }
    for( i = 0  ; i < n ; i++ ){
        if( i == 0 && peak[i] > peak[ i + 1 ]){
            high[count1] = peak[i];
            count1++;
        }
        else if( i == n - 1 && peak[i] > peak[i - 1] ){
            high[count1] = peak[i];
            count1++;
        }
        else if( peak[i] > peak[i - 1] && peak[i] > peak[ i + 1 ] ){
            high[count1] = peak[i];
            count1++;
        }
    }
    if( count1 == 0 ){
        printf("-1");
        return 0;
    }
    qsort( high , count1 , sizeof( int ) , compare );
    high2[0] = high[0];
    int count2 = 1;
    for( i = 1 ; i < count1 ; i++ ){
        if( high[i] != high[i - 1] ){
            high2[count2] = high[i];
            count2++;
        }
    }
    if( count2 < k ){
        qsort( high2 , count2 , sizeof( int ) , compare );
    }
    else{
        qsort( high2 , count2 , sizeof( int ) , compare2 );
    }
    for( i = 0 ; i < count2 && k > 0 ; i++ ,k-- ){
        printf("%d\n",high2[i]);
    }
    return 0;
}
