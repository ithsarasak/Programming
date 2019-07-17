#include<bits/stdc++.h>

using namespace std;

vector< int > lis;
int data[1000], n, path[1000], len, se[1000], s;
int main()
{
    for( int i = 0 ; i < 1000 ; i++ ){
        path[i] = -1;
    }
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&data[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        if( lis.empty() ){
            lis.push_back( i );
            len++;
        }
        else if( data[i] > data[lis.back()] ){
            path[i] = lis.back();
            lis.push_back( i );
            len++;
        }
        else if( data[i] < data[lis.front()] ){
            lis[0] = i;
        }
        else{
            int l = 0, r = lis.size() - 1;
            while( l <= r ){
                if( l + 1 == r ){
                    lis[r] = i;
                    path[i] = lis[l];
                    break;
                }
                int m = ( l + r ) / 2;
                if( data[i] <= data[lis[m]] ){
                    r = m;
                }
                else{
                    l = m;
                }
            }
        }
    }
    int pos = lis.back();
    while( path[pos] != -1 ){
        se[s] = data[pos];
        pos = path[pos];
        s++;
    }
    se[s] = data[pos];
    s++;
    printf("max length : %d\nsequence : ",len);
    for( int i = s - 1 ; i >= 0 ; i-- ){
        printf("%d ",se[i]);
    }
    return 0;
}
