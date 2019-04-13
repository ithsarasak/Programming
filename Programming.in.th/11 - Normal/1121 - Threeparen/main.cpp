#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

int n, i, len, j;
char op[100010];
stack<char> paren;
void clear( )
{
    while( !paren.empty() ){
        paren.pop();
    }
}
int main()
{
    scanf("%d",&n);

    for( i = 0 ; i < n ; i++ ){
        int check = 1;
        scanf("%s",op);

        len = strlen( op );
        for( j = 0 ; j < len ; j++ ){
            if( op[j] == '(' || op[j] == '[' || op[j] == '{' ){
                paren.push( op[j] );
            }
            else if( op[j] == ')' ){
                if( paren.empty() ){
                    printf("no\n");
                    check = 0;
                    break;
                }
                else if( paren.top() != '(' ){
                    printf("no\n");
                    check = 0;
                    break;
                }
                else{
                    paren.pop();
                }
            }
            else if( op[j] == ']' ){
                if( paren.empty() ){
                    printf("no\n");
                    check = 0;
                    break;
                }
               else if( paren.top() != '[' ){
                    printf("no\n");
                    check = 0;
                    break;
                }
                else{
                    paren.pop();
                }
            }
            else if( op[j] == '}' ){
                if( paren.empty() ){
                    printf("no\n");
                    check = 0;
                    break;
                }
                else if( paren.top() != '{' ){
                    printf("no\n");
                    check = 0;
                    break;
                }
                else{
                    paren.pop();
                }
            }
        }
        if( paren.empty() && check ){
            printf("yes\n");
        }
        else if( check != 0 ){
            printf("no\n");
        }
        clear();
    }
}
