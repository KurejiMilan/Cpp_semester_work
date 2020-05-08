#include<iostream>
#include<stdlib.h>
#include<conio.h> //getch function is defined with in this library
using namespace std;

class account
{
   private:
   char account_holder_name[25];
   char password[25];
   float bank_balance;

   public:
    void put_user_info();

    void get_user_info();

    void deposit();

    void withdrawl();

};


int main()
   {   account y;
       int x;
       cout<<"welcome to banking system." ;
       cout<<"\n ";
       top:
       cout<<"Which operation do you want to perform \n";
       cout<<"Press \n";
       cout<<"1.To put account holder info. \n";
       cout<<"2.To get account holder info. \n";
       cout<<"3.To deposit cash. \n";
       cout<<"4.To withdrawn cash. \n";
       cout<<"5.Exit. \n";

      cin>>x;


              if(x==1)
               {
                  y.put_user_info();
                  system("cls");
                  goto top;
               }
              else if(x==2)
              {
                  y.get_user_info();
                  system("cls");
                  goto top;
              }
              else if(x==3)
               {
                    y.deposit();
                    system("cls");
                    goto top;
               }
              else if(x==4)
             {
                 y.withdrawl();
                 system("cls");
                 goto top;
             }
              else if (x==5)
                goto out;
              else
               {
                    cout<<"Invalid Input.";
                    getch();
                    system("cls");
                    goto top;
               }

        out:
        system("cls");
        cout<<"Thank you for using the services";
        return 0;
   }

       inline void account::put_user_info()
       { system("cls");
         cout<<"enter the account holder name \n";
         cin>>account_holder_name;
         cout<<"\n enter the password \n";
         cin>>password;
         cout<<"\n enter the total balance \n";
         cin>>bank_balance;
         cout<<"\n procedure complete.";
       }
       inline void account::get_user_info()
       {   system("cls");
           cout<<"Account holder name "<<account_holder_name <<" current balance"<<bank_balance;
         getch();
       }
       inline void account::deposit()
       {
           system("cls");
           float x;
           cout<<"Enter the amount to be deposited ";
           cin>>x;
             bank_balance=bank_balance+x;
            cout<<"\n the amount deposited "<<x<<"\n";
            cout<<"total amount on the account "<<bank_balance;
            getch();
       }
       inline void account::withdrawl()
       {
           system("cls");
           float x;
           cout<<"\n Enter the amount to be withdrawn ";
           cin>>x;
             if(x>bank_balance)
             {
                 cout<<"\n not enough bank balance ";
                 cout<<"\n you are "<<x-bank_balance<< " short";
             }
             else
             {
                 bank_balance-=x;
                 cout<<"\n your current bank balance "<<bank_balance;
             }
                getch();
       }


