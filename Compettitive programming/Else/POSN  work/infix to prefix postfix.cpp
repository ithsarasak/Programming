#include<bits/stdc++.h>

using namespace std;

stack< char > op;
stack< char > check;
char eq[1000], temp[1000], temp2[1000];
vector< char > ans1;
int len, s;
int postfix( )
{
    for( int i = 0 ; i < len ; i++ ){
        if( eq[i] == '(' ){
            op.push( '(' );
        }
        else if( eq[i] == '^' ){
            op.push( '^' );
        }
        else if( eq[i] == '*' || eq[i] == '/' ){
            while( op.size()!= 0 && ( op.top() == '*' || op.top() == '/' || op.top() == '^' ) ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.push( eq[i] );
        }
        else if( eq[i] == '+' || eq[i] == '-' ){
            while( op.size()!= 0 && ( op.top() == '*' || op.top() == '/' || op.top() == '+' || op.top() == '-' || op.top() == '^' ) ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.push( eq[i] );
        }
        else if( eq[i] == ')' ){
            while( op.top() != '(' ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.pop();
        }
        else{
            ans1.push_back( eq[i] );
        }
        /*for( int i = 0 ; i < ans1.size() ; i++ ){
            printf("%c",ans1[i]);
        }
        printf("\n");*/
    }
    //printf("xD");
    while( !op.empty() ){
        char t = op.top();
        ans1.push_back( t );
        op.pop();
    }
    for( int i = 0 ; i < ans1.size() ; i++ ){
        printf("%c",ans1[i]);
    }
    ans1.clear();
    printf("\n");
}
int prefix()
{
    for( int i = 0 ; i < len ; i++ ){
        if( eq[len - i - 1] == ')' ){
            temp[i] = '(';
        }
        else if( eq[len -i - 1] == '(' ){
            temp[i] = ')';
        }
        else{
            temp[i] = eq[len - i - 1];
        }
    }
    //printf("xD");
    for( int i = 0 ; i < len ; i++ ){
        if( temp[i] == '(' ){
            op.push( '(' );
        }
        else if( temp[i] == '^' ){
            op.push( temp[i] );
        }
        else if( temp[i] == '*' || temp[i] == '/' ){
            while( op.size()!= 0 && ( op.top() == '^' ) ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.push( temp[i] );
        }
        else if( temp[i] == '+' || temp[i] == '-' ){
            while( op.size()!= 0 && ( op.top() == '*' || op.top() == '/' ) ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.push( temp[i] );
        }
        else if( temp[i] == ')' ){
            while( op.top() != '(' ){
                char t = op.top();
                ans1.push_back( t );
                op.pop();
            }
            op.pop();
        }
        else{
            ans1.push_back( temp[i] );
        }
        /*for( int i = 0 ; i < ans1.size() ; i++ ){
            printf("%c",ans1[i]);
        }
        printf("\n");*/
    }
    //printf("xD");
    while( !op.empty() ){
        char t = op.top();
        ans1.push_back( t );
        op.pop();
    }
    for( int i = ans1.size() - 1 ; i >=0 ; i-- ){
        printf("%c",ans1[i]);
    }
    ans1.clear();
    printf("\n");
}
int main()
{
    printf("Enter Infix : ");
    gets( eq );
    len = strlen( eq );
    for( int i = len - 1 ; i >= 0; i-- ){
        if( eq[i] == ')' || eq[i] =='}' || eq[i] == ']' ){
            check.push( eq[i] );
        }
        else if( eq[i] == '{' ){
            if( check.top() == '}' ){
                check.pop();
            }
            else{
                printf("Mismatched");
                return 0;
            }
        }
        else if( eq[i] == '(' ){
            if( check.top() == ')' ){
                check.pop();
            }
            else{
                printf("Mismatched");
                return 0;
            }
        }
        else if( eq[i] == '[' ){
            if( check.top() == ']' ){
                check.pop();
            }
            else{
                printf("Mismatched");
                return 0;
            }
        }
    }
    if( !check.empty() ){
        printf("Mismatched");
        return 0;
    }
    for( int i = 0 ; i < len ; i++ ){
        if( eq[i] =='}' || eq[i] == ']' ){
            eq[i] = ')';
        }
        else if( eq[i] =='{' || eq[i] == '[' ){
            eq[i] = '(';
        }
    }
    for( int i = 0 ; i < len ; i++ ){
        if( eq[i] != ' ' ){
            temp2[s] = eq[i];
            s++;
        }
    }
    /*for( int i = 0 ; i < s; i++ ){
        printf("%c",temp2[i]);
    }
    printf("\n");*/
    for( int i = 0 ; i < s ; i ++ ){
        if( temp2[i] == '+' || temp2[i] == '-' || temp2[i] == '*' || temp2[i] == '/' || temp2[i] == '^' ){
            if( i == 0 || i == s - 1 ){
                printf("Missing Operand");
                return 0;
            }
            else if( temp2[i - 1] == '(' || temp2[i - 1] == '+' || temp2[i - 1] == '-' || temp2[i - 1] == '*' || temp2[i - 1] == '/' || temp2[i - 1] == '^' ){
                printf("Missing Operand");
                return 0;
            }
            else if( temp2[i + 1] == ')' || temp2[i + 1] == '+' || temp2[i + 1] == '-' || temp2[i + 1] == '*' || temp2[i + 1] == '/' || temp2[i + 1] == '^' ){
                printf("Missing Operand");
                return 0;
            }
        }
        else if( temp2[i] == '(' ){
            if( temp2[i + 1] == ')' ){
                printf("Wrong expression");
                return 0;
            }
            if( i != 0 ){
                if( temp2[i - 1] != '+' && temp2[i - 1] != '-' && temp2[i - 1] != '*' && temp2[i - 1] != '/' && temp2[i - 1] != '^' ){
                    printf("Wrong expression");
                    return 0;
                }
            }
        }
    }
    printf("Postfix : ");
    postfix();
    printf("Prefix : ");
    prefix();
    return 0;
}
