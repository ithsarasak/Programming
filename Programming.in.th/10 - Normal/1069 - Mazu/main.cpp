#include<stdio.h>
#include<stack>

using namespace std;

stack<char> mazu;
int amount, i, size;
char ch, before;

int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf(" %c",&ch);
        //printf("%c",ch);

        if( size == 0 ){
            //printf("%d\n",size);
            before = ch;
            mazu.push(ch);
            size++;
            //printf("%d\n",size);
            //printf("%c %c",before,mazu.top());
        }
        else if( size != 0 ){
            if( ch == before ){
                mazu.pop();
                size -= 1;
                if( size != 0 ){
                    before = mazu.top();
                }
            }
            else{
                mazu.push(ch);
                before = mazu.top();
                size++;
            }
        }
        //printf("%c %c",before,mazu.top());
        ///printf("%d\n",size);
    }
    if( size == 0 ){
        printf("0\nempty");
    }
    else{
        printf("%d\n",size);
        while( !mazu.empty() ){
            printf("%c",mazu.top());
            mazu.pop();
        }
    }
}
