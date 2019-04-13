#include<bits/stdc++.h>

using namespace std;

int rai[1001], n, sum, currentsum, group, tempp;
vector< int > ans;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i ++ ){
        scanf("%d",&rai[i]);
        sum += rai[i];
    }
    scanf("%d",&group);
    //printf("%d\n",sum);
    tempp = sum / group;
    //printf("%d\n",sum);
    for( int i = 0 ; i < n ; i++ ){
        currentsum += rai[i];
        int temp = tempp - currentsum;
        if( temp < 0 ){
            temp *= -1;
        }
        int temp2 = currentsum + rai[i + 1] - tempp;
        if( temp2 < 0 ){
            temp2 *= -1;
        }
        if( temp < temp2 ){
            ans.push_back( currentsum );
            sum -= currentsum;
            currentsum = 0;
            tempp = sum / ( group - 1 );
        }
    }
    ans.push_back( currentsum );
    int sum2 = 0;
    for( int i = 0 ; i < ans.size() ; ){
        for( int j = 0 ; j < n ; j++ ){
            sum2 += rai[j];
            printf("%d ",rai[j]);
            if( sum2 == ans[i] ){
                printf("= %d\n",ans[i]);
                sum2 = 0;
                i++;
            }
        }
    }
    return 0;
}
