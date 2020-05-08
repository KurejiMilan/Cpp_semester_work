#include <iostream>
#include<cmath>
#include<conio.h>
#include<cstdlib>
#define PI 3.1413
using namespace std;

class shape
{
    float area;
    public:
        void circle()
        {
             float r;
              cout<<"\nenter the radius of Circle\n";
              cin>>r;
              area=PI*pow(r,2);
              cout<<"\nthe area of the circle is="<<area;
        }
        void rectangle()
        {
             float l,b;
              cout<<"\nenter the length and breath of the rectangle\n";
              cin>>l>>b;
              area=l*b;
              cout<<"\nthe area of rectangle is="<<area;
        }
        void square()
        {
             float x;
              cout<<"\nenter the length of side of a square\n";
              cin>>x;
              area=pow(x,2);
              cout<<"\nthe area of square is="<<area;

        }
        void triangle()
        {
            float h,br;
               cout<<"\nenter the height and breadth of a triangle\n";
               cin>>h>>br;
               area=0.5*h*br;
               cout<<"\nthe are of triangle is="<<area;
        }
};

int main()
{
   shape sh;
   char a;
   top:
   cout<<"Enter character\n1.'c' to calculate the area of Circle\n2.'r' to calculate the area of Rectangle\n3.'s' to calculate the area of Triangle \n4.'t' to calculate the area of triangle \n5.'e' to end the program \n";
   cin>>a;

       switch(a)
       {
        case 'c':
         sh.circle();
              break;

        case 'r':
           sh.rectangle();
              break;

        case 's':
            sh.square();
              break;

        case 't':
             sh.triangle();
               break;
        case 'e':
             goto exit;

        default:
        cout<<"\nyou have enter undefined key.Try another key";
        getch();
        system("cls");
        goto top;
       }

       exit:
return 0;
}
