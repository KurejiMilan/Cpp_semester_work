#include <iostream>
using namespace std;

class time
{
    int hours,minutes,seconds;
      public:
          time();
          time(int,int,int);
          void display ();
          void gettime();
          time operator +(time x)
              {
                  time i;
                  i.seconds=seconds+x.seconds;
                  i.minutes=(minutes+x.minutes)+(i.seconds/60);
                  i.hours=(hours+x.hours)+(i.minutes/60);
                     if(i.hours>24)
                     {
                         i.hours-=24;
                     }

                     if(i.minutes>60)
                     {
                         i.minutes-=60;
                     }
                     if(i.seconds>60)
                     {
                         i.seconds-=60;
                     }
                     return i;
              }
          time operator -(time x)
              {
                 time i;
                  i.seconds=seconds-x.seconds;
                  i.minutes=minutes-x.minutes;
                  i.hours=hours-x.hours;
                  if(i.seconds<0)
                    i.seconds*=-1;
                   if(i.hours<0)
                    i.hours*=-1;
                   if(i.minutes<0)
                    i.minutes*=-1;
              return i;
              }
          bool operator > (time y)
          {
              seconds=(hours*3600)+(minutes*60)+seconds;
              y.seconds=(y.hours*3600)+(y.minutes*60)+y.seconds;
              if(seconds>y.seconds)
                return true;
              else
                return false;
          }

};

int main()
{
    time x,y(3,45,12),z;
     x.display();
     cout<<"\n";
     y.display();
     cout<<"\n";
     cout<<"Enter the first.";
     x.gettime();
     cout<<"Enter the second.";
     y.gettime();
     z=x+y;
     cout<<"\nthe added time is\n";
     z.display();
     z=x-y;
     cout<<"\nthe subtracted time is\n";
     z.display();

          if(x>y)
            cout<<"\n1st time is greater than 2nd time.";
          else
            cout<<"\n2nd time is greater than 1st time.";

    return 0;
}

       time::time()
         {
            hours=0;
            minutes=0;
            seconds=0;
         }
        time::time(int x,int y,int z)
        {
             hours=x;
            minutes=y;
            seconds=z;
        }

        void time::display()
        {
            cout<<hours<<":"<<minutes<<":"<<seconds;
        }

        void time::gettime()
        {
            cout<<"\nEnter time in hours:minutes:seconds format=\n";
            cin>>hours;
            cout<<":";
            cin>>minutes;
            cout<<":";
            cin>>seconds;
        }
