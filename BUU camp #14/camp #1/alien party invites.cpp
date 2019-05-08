#include<bits/stdc++.h>

using namespace std;

unordered_map< string , int > inv, check;
queue< string > q;
int n, m, counts, minsize = 9999999, c;
string temp;
string allname[40001];
int main()
{
    scanf("%d",&n);
    for( auto i = 0 ; i < n ; i++ ){
        cin >> temp;
        inv[temp] = 1;
    }
    scanf("%d",&m);
    for( auto i = 0 ; i < m ; i++ ){
        cin >> allname[i];
    }
    for( auto i = 0 ; i < m ; i++ ){
        if( inv[allname[i]] == 1 && check[allname[i]] == 0 ){
            check[allname[i]] = 1;
            counts++;
            c = 1;
        }
        if( c ){
            q.push( allname[i] );
        }
        if( counts == n ){
            minsize = q.size();
            break;
        }
    }
    for( auto i = minsize ; i < m ; i++ ){
        temp = q.front();
        if( inv[temp] ){
            check[temp] = 0;
            counts--;
            //cout <<"q.front " << temp << endl;
        }
        //cout << "count : " << counts << endl;
        q.pop();
        q.push( allname[i] );
        if( inv[allname[i]] == 1 && check[allname[i]] == 0 ){
            check[allname[i]] = 1;
            counts++;
            //cout <<"allname[i] " << allname[i] << endl;
        }
        //cout << "count : " << counts << endl;
        while( counts == n ){
            temp = q.front();
            if( inv[temp] ){
                check[temp] = 0;
                if( q.size() < minsize ){
                    minsize = q.size();
                }
                break;
            }
            q.pop();
        }
    }
    printf("%d",minsize);
    return 0;
}
