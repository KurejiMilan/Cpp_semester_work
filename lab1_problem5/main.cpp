#include <iostream>
#include<cstdlib>
#include<conio.h>
#define SIZE 50
using namespace std;

class employee
{
   char employeename[40];
   char employeenum[40];
   float basic;
   float da;
   float it;
   float net_salary;
 public:
        void getinfo();
        void showinfo(int);
        void calculate();
        void showresult();
};

int main()
{
    employee x[SIZE];
    int i,j;
    cout<<"enter the number of employee\n";
    cin>>i;
      for(j=0;j<i;j++)
           {
                x[j].getinfo();
           }
      for(j=0;j<i;j++)
           {
                x[j].showinfo(j);
           }
      for(j=0;j<i;j++)
           {
                x[j].calculate();
           }
      for(j=0;j<i;j++)
           {
                x[j].showresult();
           }
    return 0;
}
       inline void employee::getinfo()
             {
                 cout<<"\nEnter the employee number=";
                 cin>>employeenum;
                 cout<<"\nEnter the employee name=";
                 cin>>employeename;
                 cout<<"\nEnter the basic salary=";
                 cin>>basic;
                 getch();
                 system("cls");
             }
       inline void employee::showinfo(int g)
             {
                cout<<"the information of employee no."<<++g;
                cout<<"\n1.Employee number="<<employeenum<<"\n2.Employee name="<<employeename<<"\n3.Basic salary="<<basic<<endl;
                getch();
             }
       inline void employee::calculate()
             {
                 da=(40.0/100)*basic;
                 float gross=da+basic;
                 it=(30.0/100)*gross;
                 net_salary=gross-it;
             }
        inline void employee::showresult( )
             {
                 cout<<"\nthe net income of employee "<<employeename<<" is="<<net_salary;
             }
