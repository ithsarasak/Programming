#include<bits/stdc++.h>

using namespace std;
int n, m, ans;
string w, f;
int main()
{
    scanf("%d %d",&n,&m);
    cin >> w;
    cin >> f;
    //printf("%s",w);
    for( int i = 0 ; i < n ; i++ ){
        //printf("w[%d] : %c f[%d] : %c\n",i,w[i],c,f[c]);
        string ch = w.substr( i, m );
        //cout << ch << endl;
        if( ch == f ){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
