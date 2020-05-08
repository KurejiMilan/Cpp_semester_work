#include <iostream>

using namespace std;


class number
{
private:
    int data;
public:
    class neg
    {
         public:
    neg(){}
    ~neg(){}
      };
    number(){}
    void getdata()
    {
        cout<<"enter a number"<<endl;
    }
    void display()
    {
        if(0>data)
        throw neg
        else
        cout<<"th number is"<<data<<endl;
    }
};
int main()
{
    number x;
    x.getdata();
      try{
          x.display();
      }
      catch (number::neg){
          cout<<"ERROR! Negative number found";
      }
    return 0;
}
