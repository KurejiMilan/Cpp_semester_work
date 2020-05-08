
#include <iostream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#define MAX 50
using namespace std;

class garage
{
    protected:
    int hourin,minutesin,secondsin,yearin,monthin,dayin,hourout,minutesout,secondsout,yearout,monthout,dayout;
    bool occupied_flag;
    static int cars_no;

   public:
        garage(){}
        garage(bool passed_flag)
        {
          occupied_flag=passed_flag;
        }
        void operator ++()
             {
                 ++cars_no;
             }
        void operator --()
             {
                --cars_no;
             }
        bool check_flag_status();

};
int garage::cars_no=0;

class vehicle
{
    protected:
    char vehicle_no[10];
};

class costumer:public garage,public vehicle
{
      char name[30];
      char password[30];
         public:
             costumer(){}
             costumer(bool passing_flag):garage(passing_flag){}
             void check_in(char *,char *);
             int check_out(char *);
             float calculate();
             void print(float);
             bool check_entry(char *);
};

bool check_password(char *);

int main()

{
    costumer x[MAX](false);
    int i=0,a,limiter=i;
    char name[30];
    char password[30];

    top:

    cout<<"\n\tEnter\n'1' for car check in\n'2'for car check out\n'3'to end the program.\n";
    cin>>a;

       switch(a)
         {

         case 1:

            cout<<"\nEnter the name of user=";

            cin>>name;

             cout<<"\nEnter password having at least 8 letters,2 special character and 2 numbers."<<endl;
                   re:
             cin>>password;
                    if(check_password(password)==false)
                    goto re;

          //this part checks if the password already exists
           for(int k=0;k<i;k++)
           {
               if(x[k].check_entry(password)==false)
               {
                   cout<<"\nThe password already exits.Use new password=";
                   goto re;
               }
           }
         /*this parts checks for flag status if the place is empty it is used*/

           for(int j=0;j<limiter+1;j++)
           {
             if(x[j].check_flag_status()==false)
             {
              ++x[j];
              x[j].check_in(name,password);
              i++;
             }
           }
           break;

        case 2:

             /*cout<<"\Enter the name of costumer=";
             cin>>name;*/
             cout<<"\nEnter the password to CHECK OUT=";
             cin>>password;
            for (int j=0;j<i;j++)
            {
                int r=x[j].check_out(password);
                if(r==1)
                   {
                       --x[j];
                       float cost=x[j].calculate();
                       x[j].print(cost);
                       goto top;
                   }
            }
            cout<<"\nThe entered password doesn't matches with any password stored in Database."<<endl;
            break;

         case 3:
             goto exit;

         default:
            cout<<"\nInvalid input"<<endl;
            goto top;
         }
         limiter=i;
         goto top;
    exit:
    return 0;
}

     void costumer::check_in(char *u_name,char *u_pass)
             {
                strcpy(name,u_name);
                strcpy(password,u_pass);
                //cout<<password<<endl;
                cout<<"\nEnter the vehicle no=";
                cin>>vehicle_no;
                date:
                cout<<"\nEnter the check in date of the vehicle in day-month-year format\n";
                cin>>dayin>>monthin>>yearin;

                  if((yearin<2019)||(dayin>31)||(monthin>12)||(yearin<=0)||(dayin<=0)||(monthin<=0))
                  {
                      cout<<"\nInvalid input detected!Input parameters exceeded.";
                      goto date;
                  }
                time:
                cout<<"\nEnter the check in time of the vehicle in 24 hour:minutes:seconds format\n";
                cin>>hourin>>minutesin>>secondsin;

                  if((hourin>24)||(minutesin>59)||(secondsin>59)||(hourin<=0)||(minutesin<0)||(secondsin<0))
                  {
                      cout<<"\nInvalid input detected!Input parameters exceeded.";
                      goto time;
                  }
                cout<<"\nThe total no of vehicle inside the Parking Garage="<<cars_no<<endl;
                occupied_flag=true;
             }

     int costumer::check_out(char *passed_password)
             {
                 /*cout<<"password of database"<<password<<endl;
                 cout<<"passed password"<<passed_password<<endl;*/
                 if(strcmp(password,passed_password)!=0)
                    return 0;
                 else
                {
                 date:
                 cout<<"\nEnter the check out date in day-month-year format\n";
                 cin>>dayout>>monthout>>yearout;
                 if((yearout<2019)||(dayout>31)||(monthout>12)||(dayout<=0)||(monthout<=0)||(yearout<=0))
                  {
                      cout<<"\nInvalid input detected! Input parameters exceeded."<<endl;
                      goto date;
                  }
                  if((yearout<yearin)||((dayout<dayin)&&(monthout==monthin)&&(yearin==yearout))||((monthin>monthout)&&(yearin==yearout)))
                  {
                      cout<<"\nInvalid parameter.Check out date is less than check in date"<<endl;
                      goto date;
                  }
                  time:
                 cout<<"\nEnter the check out time in hours:minutes:seconds format\n";
                 cin>>hourout>>minutesout>>secondsout;
                 if((hourout>24)||(minutesout>59)||(secondsout>59)||(hourout<=0)||(minutesout<=-1)||(secondsout<=-1))
                  {
                      cout<<"\nInvalid input detected!Input parameters exceeded.";
                      goto time;
                  }

                  if((dayin==dayout)&&(monthin==monthout)&&(yearin==yearout))
                  {
        if((hourin>hourout)||((hourin==hourout)&&(minutesin>minutesout))||((hourin==hourout)&&(minutesin==minutesout)&&(secondsin>secondsout)))
                  {
                       cout<<"\nInvalid parameter.Check out time is less than check in time"<<endl;
                      goto time;
                  }
                }

                 return 1;
                 }

             }
     float costumer::calculate()
             {
                 float cost;
                 /*int x=(yearin*365)+(monthin*30)+dayin;
                 int y=(yearout*365)+(monthout*30)+dayout;*/
                 float x=(yearin*365*24)+(monthin*30*24)+(dayin*24)+(hourin)+(minutesin/60.0)+(secondsin/360.0);
                 float y=(yearout*365*24)+(monthout*30*24)+(dayout*24)+(hourout)+(minutesout/60.0)+(secondsout/360.0);
                 /*float z=(hourin)+(minutesin/60.0)+(secondsin/360.0);
                 float a=(hourout)+(minutesout/60.0)+(secondsout/360.0);*/
                   if(((y-x)>=24))
                   {
                    cost=((y-x)/24)*80;
                    return cost;
                   }

                   else if(((y-x)>3)&&((y-x)<24))
                   {
                       cost=(((y-x-3)*0.50)+2);
                       return cost;

                   }
                   else
                    return 2.00;
             }

    void costumer::print(float cost)
             {
                 char rad[5]="***";
               cout<<"\nCostumer name="<<name<<"\nvehicle no="<<vehicle_no;
               cout<<"\nCheck In date="<<dayin<<"-"<<monthin<<"-"<<yearin;
               cout<<"\nCheck Out date="<<dayout<<"-"<<monthout<<"-"<<yearout;
               cout<<"\nCost of parking=$"<<cost;
               cout<<"\ntotal no of vehicle inside Parking Garage="<<cars_no<<endl;
               strcpy(password,rad);
               occupied_flag=false;
             }

    bool costumer::check_entry(char *u_pass)
         {
                 if(strcmp(u_pass,password)==0)
                    return false;
                 else
                    return true;
         }
   //checking if the place is occupied or not
    bool garage::check_flag_status()
    {
        if(occupied_flag==false)
            return false;
        else
            return true;
    }

 //checking if the input password meets the required conditions
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
           int symb_count=0,num_count=0;
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
        if(password[i]=='1')
            ++num_count;
        if(password[i]=='2')
           ++num_count;
        if(password[i]=='3')
            ++num_count;
        if(password[i]=='4')
            ++num_count;
        if(password[i]=='5')
            ++num_count;
        if(password[i]=='6')
            ++num_count;
        if(password[i]=='7')
            ++num_count;
        if(password[i]=='8')
            ++num_count;
        if(password[i]=='9')
            ++num_count;
    }
    if(((symb_count<2)&&(num_count<2))||(symb_count<2)||(num_count<2))
       {
        cout<<"Password must include 2 or more Special character and numbers.\nRE-ENTER the password"<<endl;
        return false;
       }
     else
        return true;
  }
}
