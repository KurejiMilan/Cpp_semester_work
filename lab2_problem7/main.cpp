#include <iostream>

using namespace std;

class time
{
    int hours,minutes,seconds;

 public:
    friend istream & operator >> (istream &,time &);
    friend ostream & operator << (ostream ,time );

} ;

int main()
{
    time x;
    cout<<"Enter the time in hour minutes and seconds";
    cin>>x;
    cout<<"\nThe entered time is=";
    cout<<x;
    return 0;
}

     istream & operator >> (istream &input,time &x)
     {
         input>>x.hours>>x.minutes>>x.seconds;
         return input;

     }
     ostream & operator << (ostream & output,time &x)
     {
         output<<x.hours<<":"<<x.minutes<<":"<<x.seconds;
         return output;
     }
