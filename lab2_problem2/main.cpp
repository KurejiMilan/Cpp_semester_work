#include <iostream>

using namespace std;
class NR_cur;
class US_cur
{
    float usmoney;
    public:

    /*friend void getmoney(US_cur &,NR_cur &);
    friend bool operator > (US_cur,NR_cur);
    friend bool operator < (US_cur,NR_cur);*/
    friend NR_cur;
    void getmoney(NR_cur&);
    bool operator > (NR_cur);
    bool operator < (NR_cur);
};

class NR_cur
{
    float nepalmoney;
    public:
        friend US_cur;
     /*friend void getmoney(US_cur &,NR_cur &);
    friend bool operator > (US_cur,NR_cur);
    friend bool operator < (US_cur,NR_cur);*/
};

int main()
{
    US_cur x;
    NR_cur y;
    x.getmoney(y);
    if(x>y)
        cout<<"\nUS currency is more than Nepali currency.";
    else if(x<y)
        cout<<"\nNepali currency is more than US currency.";
    else
        cout<<"\nboth the currency is equal.";
    return 0;
}


        void US_cur::getmoney(NR_cur &y)
            {
                cout<<"enter the money in US currency\n";
                cin>>usmoney;
                //cout<<usmoney;
                cout<<"\nenter the money in Nepali currency\n";
                cin>>y.nepalmoney;

            }
      bool US_cur::operator >(NR_cur j)
      {
          j.nepalmoney=j.nepalmoney/101.36;
          //cout<<j.nepalmoney<<"\n";
          //cout<<i.usmoney;
          if(usmoney>j.nepalmoney)
          {
              return true;
          }
          else
              return false;
      }
     bool US_cur::operator <(NR_cur l)
     {
         l.nepalmoney=l.nepalmoney/101.36;
         if(usmoney<l.nepalmoney)
          {
              return true;
          }
          else
              return false;
     }
