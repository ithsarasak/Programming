#include <iostream>
#include <stdio.h>

using namespace std;

int i,j;
int amount;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    cin >> amount;

    for( j = 0 ; j < amount ; j++ )
    {
        string word;
        string last;

        cin >> word ;

        //cout << word[0] << endl;

        int len = word.length();

        last = word[0];
        int k = 1;

    //cout << last[0] <<endl;
    //cout << last <<endl;

        for( i = 1 ; i < len ; i++ )
        {
            if( word[i] > last[k-1] && word[i] < last[0])
            {
                last = last + word[i];
                k++;
            }
            else if( word[i] < last[k-1] )
            {
                last = last + word[i];
                k++;
            }
            else if( word[i] > last[0] )
            {
                last = word[i] + last;
                k++;
            }
            else if( word[i] == last[0] )
            {
                last = word[i] + last;
                k++;
            }
            else
            {
                last = last + word[i];
                k++;
            }
        //cout << last << endl;
        }

    cout << "Case" << " " << "#" << j+1 << ":" << " " << last << endl;

    }

    return 0;
}
