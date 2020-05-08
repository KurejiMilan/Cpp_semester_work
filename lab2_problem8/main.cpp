#include <iostream>
#define MAX 100
using namespace std;

class garage
{
    int entry_no,hourin,minutesin,secondsin,yearin,monthin,dayin,hourout,minutesout,secondsout,yearout,monthout,dayout;
     static int cars_no;

   public:
        void operator ++()
             {
                 ++cars_no;
             }
        void operator --()
             {
                --cars_no;
             }
             void check_in(int);
             int check_out(int);
             float calculate();
             void print(float);
             bool check_entry(int);
};
   int garage::cars_no=0;
int main()
{
    garage x[MAX];
    int i=0,a,entry_no;
    top:
    cout<<"Enter\n'1' for car check in\n'2'for car check out\n'3'to end the program.\n";
    cin>>a;

       switch(a)
         {
         case 1:

            cout<<"\nEnter the entry no of the car=";
              new_entry:
            cin>>entry_no;
           for(int k=0;k<i;k++)
           {
               if(x[k].check_entry(entry_no)==false)
               {
                   cout<<"\nThe entry number already exits.Use new entry number=";
                   goto new_entry;
               }
           }
           ++x[i];
           x[i].check_in(entry_no);
           i++;
           break;
         case 2:
             int y;
             cout<<"\n Enter the entry no of vehicle";
             cin>>y;
            for (int j=0;j<i;j++)
            {
                int r=x[j].check_out(y);
                if(r==1)
                   {
                       --x[j];
                       float cost=x[j].calculate();
                       x[j].print(cost);
                       goto top;
                   }
            }
            cout<<"\nWrong Entry no";
            break;
         case 3:
             goto exit;
         default:
            cout<<"\nInvalid input";
            goto top;
         }
         goto top;
    exit:
    return 0;
}

             void garage::check_in(int x)
             {
                entry_no=x;
                cout<<"\nEnter the check in date of the vehicle in day-month-year format\n";
                cin>>dayin>>monthin>>yearin;
                cout<<"\nEnter the check in time of the vehicle in hour:minutes:seconds format\n";
                cin>>hourin>>minutesin>>secondsin;
                cout<<"\nThe total no of cars="<<cars_no;
             }
             int garage::check_out(int x)
             {
                 if(x!=entry_no)
                    return 0;
                 else
                {
                 cout<<"\nEnter the check out date in day-month-year format\n";
                 cin>>dayout>>monthout>>yearout;
                 cout<<"\nEnter the check out time in hours:minutes:seconds format\n";
                 cin>>hourout>>minutesout>>secondsout;
                 return 1;
                 }

             }
             float garage::calculate()
             {
                 float cost;
                 int x=(yearin*365)+(monthin*30)+dayin;
                 int y=(yearout*365)+(monthout*30)+dayout;
                 float z=(hourin*60)+minutesin+(secondsin/60.0);
                 float a=(hourout*60)+minutesout+(secondsout/60.0);

                   if((y-x)>1)
                   {
                    cost=(y-x)*80;
                    return cost;
                   }

                   else if((a-z)>3)
                   {
                       cost=(((a-z-3)*0.50)+2);
                       return cost;

                   }
                   else
                    return 2;
             }
             void garage::print(float cost)
             {
               cout<<"\nEntry no="<<entry_no;
               cout<<"\nCheck In date="<<dayin<<"-"<<monthin<<"-"<<yearin;
               cout<<"\nCheck Out date="<<dayout<<"-"<<monthout<<"-"<<yearout;
               cout<<"\nCost of parking=$"<<cost;
               cout<<"\ntotal no of vehicle="<<cars_no;
             }

             bool garage::check_entry(int checkVal)
             {
                 if(checkVal==entry_no)
                    return false;
                 else
                    return true;
             }
