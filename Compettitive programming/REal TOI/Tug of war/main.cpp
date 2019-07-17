#include<bits/stdc++.h>
using namespace std;
int student[2010], dara[2010], i, j, n;
long long sum;
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&student[i]);
    }
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&dara[i]);
    }
    sort( student , student + n );
    sort( dara , dara + n );
    for( i = 0 ; i < n ; i++ ){
        int temp = student[i] - dara[i];
        if( temp < 0 ){
            temp *= -1;
        }
        sum += ( long long )temp;
    }
    printf("%lld",sum);
    return 0;
}
