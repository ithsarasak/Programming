#include<bits/stdc++.h>

using namespace std;

list< string > allname;
list< string >::iterator it;
string name;
int check;
int main()
{
    while( 1 ){
        printf("1.add 2.delete 3.size 4.show 5.find 6.exit\n");
        int c;
        cin >> c;
        if( c == 1 ){
            cout << "Add : ";
            cin >> name;
            allname.push_back( name );
            allname.sort();
            cout << "Addition Complete" << endl;
        }
        else if( c == 2 ){
            if( allname.size() == 0 ){
                cout << "No element to delete" << endl;
            }
            else{
                cout << "Delete : ";
                cin >> name;
                check = 0;
                list< string >::iterator findIter = find( allname.begin(), allname.end(), name );
                if( findIter != allname.end() ){
                    allname.remove( name );
                    check = 1;
                    cout << "Deletion Complete" << endl;
                }
                if( check == 0 ){
                    printf("No element to delete\n");
                }
            }
        }
        else if( c == 3 ){
            cout << "size = " << allname.size() << endl;
        }
        else if( c == 4 ){
            if( allname.size() != 0 ){
                for( it = allname.begin() ; it != allname.end() ; it++ ){
                    cout << *it << " " ;
                }
                cout << endl;
            }
            else{
                cout << "The list is empty :(" ;
            }
        }
        else if( c == 5 ){
            cout << "Find : ";
            cin >> name;
            list< string >::iterator findIter = find( allname.begin(), allname.end(), name );
            if( findIter != allname.end() ){
                cout << "Element Found!" << endl ;
            }
            else{
                cout << "Element Not Found" << endl;
            }
        }
        else{
            break;
        }
    }

    if( allname.size() != 0 ){
        cout << "The list contains : ";
        for( it = allname.begin() ; it != allname.end() ; it++ ){
            cout << *it << " " ;
        }
    }
    else{
        cout << "The list is empty  :(" ;
    }
    return 0;
}
