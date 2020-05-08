#include <iostream>

using namespace std;

class date
{
    int year,month,day;
    public:
    date(){}
    date(int a,int b,int c)
    {
        year=a;
        month=b;
        day=c;
        cout<<"year ="<<year<<" month ="<<month<<" day ="<<day<<endl;
    }
    ~date(){}
    void display();
    date get();
    void Set();
};
class  time
{
    int hour,minute,second;
public:
    time(){}
    time (int d,int e,int f)
    {
        hour=d;
        minute=e;
        second=f;
        cout<<"\nhour ="<<hour<<" minute ="<<minute<<" seconds ="<<second<<endl;
    }
    ~time(){}
    void display();
    time get();
    void Set();
};

class DateAndTime:public date,public time
{
  public:
      DateAndTime(int a,int b,int c, int d,int e,int f):date(a,b,c),time(d,e,f)
      {
          cout<<"\nThis is inside parameterized derived class constructor";
      }
      ~DateAndTime(){}
     void display();
};
int main()
{
    DateAndTime watch(2019,1,15,8,51,12);
    watch.date::Set();
    watch.time::Set();
    watch.display();
    return 0;
}
void date::Set()
{
    cout<<"\nEnter the year,month and day\n";
    cin>>year>>month>>day;
}
void time::Set()
{
    cout<<"\nEnter the hour,minutes and seconds\n";
    cin>>hour>>minute>>second;
}
void date::display()
{
    cout<<"\nDate is="<<year<<"-"<<month<<"-"<<day;
}
void time::display()
{
    cout<<"\ntime is="<<hour<<":"<<minute<<":"<<second;
}
void DateAndTime::display()
{
    date::display();
    time::display();
}
