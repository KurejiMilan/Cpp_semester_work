#include <iostream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
bool check_password(char *);
int main()
{
   char password[30];
   cout<<"Enter password having at least 8 letters and 2 special character."<<endl;
   re:
   cin>>password;
   if(check_password(password)==false)
    goto re;
//salting part
    int length_of_password=strlen(password);
    char Hashcode[length_of_password+7]="12#";
     strcat(Hashcode,password);
     strcat(Hashcode,"*34");

  cout<<"accepted password="<<Hashcode<<endl;

      length_of_password=strlen(Hashcode)+1;
     for(int i=0;i<length_of_password;i++)
     {
         Hashcode[i]=(Hashcode[i]<<1);
     }
     cout<<Hashcode;
    return 0;
}

bool check_password(char *password)
{
   int length_of_password=strlen(password);
         if(length_of_password<8)
           {
              cout<<"password must be 8 letters long.Re-enter the password.\n";
              getch();
              system("cls");
              return false;
           }

    else
     {
           int symb_count=0;
      for(int i=0;i<(length_of_password+1);i++)
       {
        if(password[i]=='!')
            ++symb_count;
        if(password[i]=='@')
            ++symb_count;
        if(password[i]=='#')
            ++symb_count;
        if(password[i]=='$')
            ++symb_count;
        if(password[i]=='%')
            ++symb_count;
        if(password[i]=='^')
            ++symb_count;
        if(password[i]=='&')
            ++symb_count;
        if(password[i]=='*')
            ++symb_count;
        if(password[i]=='_')
            ++symb_count;
        if(password[i]=='~')
            ++symb_count;
        if(password[i]=='|')
            ++symb_count;
        if(password[i]=='\\')
            ++symb_count;
        if(password[i]=='/')
            ++symb_count;
    }
    if(symb_count<2)
       {
        cout<<"Password must include 2 or more Special character.RE-ENTER the password"<<endl;
        return false;
       }
     else
        return true;
  }
}
