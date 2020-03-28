#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
struct node {
    char d;
    int sz;
    node *par[25];
    node() { }
    node( char d ) : d( d ) { for( int i = 0 ; i <= 19 ; i++ ) par[i] = nullptr; }
};

int ptr;
node* s[N];

void Init() {
    ptr = 0;
    s[0] = nullptr;
}
void TypeLetter( char a ) {
    ++ptr;
    s[ptr] = new node( a );
    s[ptr]->sz = s[ptr-1] ? s[ptr-1]->sz + 1 : 1;
    s[ptr]->par[0] = s[ptr-1];
    for( int i = 1 ; i <= 19 ; i++ ) if( s[ptr]->par[i-1] )
        s[ptr]->par[i] = s[ptr]->par[i-1]->par[i-1];
}
void UndoCommands( int u ) {
    s[++ptr] = s[ptr - u];
}

char GetLetter( int p ) {
    int pos = s[ptr]->sz - p - 1;
    node *now = s[ptr];
    for( int i = 19 ; i >= 0 ; i-- ) if( pos >> i & 1 ) now = now -> par[i];
    return now->d;
}