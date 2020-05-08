#include <iostream>
#include<cstdlib>
#include<conio.h>
#include<cstring>
#define SIZE 50
using namespace std;


class employee
{
    char empid[30];
    char empname[30];
    char designation[30];
    static int manager;
    static int engineer;

public:
      void getemp(int);
      void check();
    static void countm()
      {
          ++manager;
      }
   static void counte()
      {
          ++engineer;
      }
   static int geteng()
      {
          return engineer;
      }
   static int getman()
      {
          return manager;
      }
};
int employee::manager;
int employee::engineer;



int main()
{
    employee x[SIZE];
      cout<<"Enter the total number of employee\n";
      int i;
      cin>>i;
          for(int j=0;j<i;j++)
          {
             x[j].getemp(j);
          }
          for(int k=0;k<i;k++)
          {    cout<<"this is check loop";
              x[k].check();
          }
          int engnum=employee::geteng();
          int mannum=employee::getman();
          int empnum=i-(engnum+mannum);
      cout<<"\nthe number of manager is="<<mannum<<"\nthe number of engineer is="<<engnum<<"\nand the number of employee="<<empnum<<"\n";

    return 0;
}

inline void employee::getemp(int y)
   {

       cout<<"Enter the employee ID=";
       cin>>empid;
       cout<<"\nEnter the employee name=";
       cin>>empname;
       cout<<"\nEnter the designation of employee no."<<++y;
       cin>>designation;
       getch();
       system("cls");
   }
inline void employee::check()
{
    if (strcmp(designation,"manager")==0)
    {
        employee::countm();

    }
    if (strcmp(designation,"engineer")==0)
    {
        employee::counte();
    }
}
