#include <iostream>

using namespace std;

class Nepali_currency
{
   float rupees;

   public:
       //float get_rupess();
       void get_rs();
       operator float ()
       {
           return rupees/98.51;
       }
};

/*class US_currency
{
    float dolor;

    public:
    US_currency(){}
    US_currency(Nepali_currency);
    void show();
};*/

int main()
{
    Nepali_currency a;
    float dollor;
    a.get_rs();
    dollor=a;
    cout<<"The equivalent money in dolor is$="<<dollor;
    return 0;
}
/*float Nepali_currency::get_rupess()
{
    return rupees;
}*/
void Nepali_currency::get_rs()
{
    cout<<"Enter Nepali currency=";
    cin>>rupees;
}
/*US_currency::US_currency(Nepali_currency x)
{
        dolor=x.get_rupess()/98.51;
}
    void US_currency::show()
    {
        cout<<"\nThe US currency is=$"<<dolor;
    }*/
