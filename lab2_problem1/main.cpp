#include <iostream>

using namespace std;

class number2;
class number1
{
    int num1;
    public:
    number1()
     {

     }
    number1(int );
     friend void change(number1&,number2&);


};

class number2
{
    int num2;
    public:
     number2()
     {

     }
     number2(int);
     friend void change(number1&,number2&);

};



int main()
{
      number1 x(2);
      number2 y(3);
      change(x,y);
    return 0;
}
void change(number1 &a,number2 &b)
{
    int j;
    j=a.num1;
    a.num1=b.num2;
    b.num2=j;
    cout<<"\ndata member of first class after swapping is "<<a.num1;
    cout<<"\ndata member of second class after swapping is "<<b.num2;
}

   number1::number1(int x)
    {

     num1=x;
     cout<<"the class 1 data member is "<<num1;

    }
  number2::number2(int y)
     {
         num2=y;
         cout<<"\nthe class 2 data member is "<<num2;

     }
