#include <iostream>
using namespace std;
typedef struct customer
{
        char first_name[50];
        char last_name[50];
        int age;
        char phone_no[50];
}customer;
int main()
{
        int n;
        cin>>n;
        customer *cus;
        cus = (customer *)malloc(sizeof(customer) * n);
        for(int i=0; i<n; i++)
                cin>>cus[i].first_name>>cus[i].last_name>>cus[i].age>>cus[i].phone_no;
}
