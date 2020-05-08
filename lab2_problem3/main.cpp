#include <iostream>

using namespace std;

class complex_num
{
    float real,img;
    public:
        void get_in();
        void put_out();
        complex_num operator +(complex_num e)
              {
                   complex_num a;
                   a.real=real+e.real;
                   a.img=img+e.img;
                   return a;
              }
        complex_num operator -(complex_num f)
              {
                   complex_num b;
                   b.real=real-f.real;
                   b.img=img-f.img;
                   return b;
              }
        complex_num operator *(complex_num g)
              {
                   complex_num c;
                   c.real=real*g.real;
                   c.img=img*g.img;
                   return c;
              }
        complex_num operator /(complex_num h)
              {
                   complex_num d;
                   d.real=real/h.real;
                   d.img=img/h.img;
                   return d;
              }
};

int main()
{
    complex_num x,y,z;
    cout<<"put the first complex number";
    x.get_in();
    cout<<"\nput the second complex number";
    y.get_in();
    cout<<"\nthe first complex number is=";
    x.put_out();
    cout<<"\nthe second complex number is=";
    y.put_out();

    top:
    cout<<"\nEnter\n1.'a' to add two complex number\n2.'s' to subtract two complex number\n3.'m' to multiply two complex number";
    cout<<"\n4.'d' to divide two complex numbers\n";

    char a;
    cin>>a;

    switch(a)
    {
    case 'a':
        z=x+y;
        break;
    case 's':
        z=x-y;
        break;
    case 'm':
        z=x*y;
        break;
    case 'd':
        z=x/y;
        break;
    default:
        cout<<"\nwrong entry try again";
        goto top;
    }

    cout<<"\nafter manipulating the complex number=";
    z.put_out();

    return 0;
}

      void complex_num::get_in()
      {
          cout<<"\nReal number=";
          cin>>real;
          cout<<"\nImaginary number=";
          cin>>img;
      }
      void complex_num::put_out()
      {
        cout<<real;
        if(img<0)
            {
                img*=-1;
                cout<<"-i"<<img;
            }
        else
            cout<<"+i"<<img;
      }
