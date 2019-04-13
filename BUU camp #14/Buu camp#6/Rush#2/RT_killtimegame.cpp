#include<bits/stdc++.h>

using namespace std;
int q, pos, n, die, mpo;
int mark[5000010];
unordered_map<int,string> all;
int main()
{
    all[0] = "Dr.Peartt";
    all[1] = "Porn";
    all[2] = "Born";
    all[3] = "Nornt";
    all[4] = "Borss";
    all[5] = "Norn";
    all[6] = "Girg";
    all[7] = "Asira";
    scanf("%d",&q);
    while( q-- ){
        die = 0;
        mpo = 5000001;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&pos);
            mark[pos] = i;
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( mpo == 0 ){
                break;
            }
            else if( mark[i] >= mpo )continue;
            else{
                mpo = mark[i];
                die++;
            }
        }
        if( mpo == 0 ){
            cout << all[die%8] << endl;
        }
    }
}
