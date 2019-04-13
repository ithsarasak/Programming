#include <iostream>
using namespace std;
typedef struct cust
{
        char first_name[50];
        char last_name[50];
        int age;
        char phone_no[50];
}customer;
int main()
{
        FILE *fp;
        fp = fopen("customer.txt","wb");
        int n;
        cin>>n;
        fwrite(&n,sizeof(n),1,fp);
        customer *cus;
        cus = (customer *)malloc(sizeof(customer) * n);
        for(int i=0; i<n; i++)
                cin>>cus[i].first_name>>cus[i].last_name>>cus[i].age>>cus[i].phone_no;
        fwrite(cus,sizeof(customer),n,fp);
        free(cus);
        fclose(fp);
}
