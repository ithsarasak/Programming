#include<stdio.h>
#include<vector>
using namespace std;
int i, t, j, k;
int main()
{
    scanf("%d",&t);

    for( i = 0 ; i < t ; i++ ){
        int numstd, point[101], min = 120000;
        int dat[120001] = {0};
        int sum = 0;
        vector<int> vec;
        scanf("%d",&numstd);

        for( j = 0 ; j < numstd ; j ++ ){
            scanf("%d",&point[j]);
            sum += point[j];
        }
        for( j = 0 ; j < numstd ; j++ ){
            //printf("point[%d]  : %d\n",j,point[j]);
            if( j == 0 ){
                vec.push_back( -1 * point[j] );
                vec.push_back(  point[j] );
            }
            else if( j == numstd - 1 ){
                int help  = vec.size();
                for( k = 0 ; k < help ; k++ ){
                    dat[vec[k] - point[j] + sum] = 1;
                    dat[vec[k] + point[j] + sum] = 1;
                }
            }
            else{
                int help = vec.size();
                //printf("%d\n",help);
                for( k = 0 ; k < help ; k++ ){
                   // printf("%d\n",vec[k]);
                    vec.push_back( vec[k] - point[j] );
                    vec.push_back( vec[k] + point[j] );
                }
                for( k = 0 ; k  < help ; k++ ){
                    vec.erase( vec.begin() );
                }
            }
        }
        for( j = 0 ; j  <= sum + sum ; j++ ){
            if( dat[j] == 1 ){
                 //printf("%d %d\n",j,dat[j]);
                int pos = j;
                pos -= sum;
                if( pos < 0 ){
                    pos *= -1;
                    if( min > pos ){
                        min  = pos;
                    }
                }
                else{
                     //printf("%d %d\n",j,dat[j]);
                    if( min > pos ){
                        min  = pos;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",i + 1,min);
    }
    return 0;
}
