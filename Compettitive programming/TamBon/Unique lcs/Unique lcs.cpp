#include<bits/stdc++.h>

using namespace std;

int t, i, l, n, len1, len2, list1[300010], posi[300010], s, first, last , middle;
struct lists{
    int val, pos;
    bool operator<( const lists &k ){
        return val < k.val;
    }
}list2[300010];
vector< int > lis;
int main()
{
    scanf("%d",&t);
    for( l = 0 ; l < t ; l++ ){
        s = 0;
        lis.clear();
        scanf("%d %d %d",&n,&len1,&len2);
        for( i = 0 ; i < len1 ; i++ ){
            scanf("%d",&list1[i]);
        }
        for( i = 0 ; i < len2 ; i++ ){
            scanf("%d",&list2[i].val);
            list2[i].pos = i;
        }
        sort( list2 , list2 + len2 );
        for( i = 0 ; i < len1 ; i++ ){
            int num = list1[i];
            first = 0, last = len2 - 1;
            middle = ( first + last ) / 2;
            while( first <= last ){
                if( list2[middle].val == num ){
                    //printf("%d/n",num);
                    posi[s] = list2[middle].pos;
                    s++;
                    break;
                }
                if( list2[middle].val < num ){
                    first = middle + 1;
                }
                else{
                    last = middle - 1;
                }
                middle = ( first + last ) / 2;
            }
        }
        /*for( i = 0 ; i < s ; i++ ){
            printf("%d ",posi[i]);
        }
        printf("\n");*/
        for( i = 0 ; i < s ; i++ ){
            if( lis.empty() ){
                //printf("%d ",posi[i]);
                lis.push_back( posi[i] );
            }
            else if( posi[i] < lis[0] ){
                lis[0] = posi[i];
            }
            else if( posi[i] > lis[lis.size() - 1] ){
                lis.push_back( posi[i] );
            }
            else{
                first = 0, last = lis.size() - 1;
                middle = ( first + last ) / 2;
                while( first <= last ){
                    if( first + 1 == last ){
                        break;
                    }
                    if( lis[middle] < posi[i] ){
                        first = middle + 1;
                    }
                    else if( lis[middle] > posi[i] ){
                        last = middle - 1;
                    }
                }
                lis[last] = posi[s];
            }
            //printf("%d\n",lis[0]);
        }
        /*for( i = 0 ; i < lis.size() ; i++ ){
            printf("%d ",lis[i]);
        }*/
        printf("%d\n",lis.size());
    }
    return 0;
}
