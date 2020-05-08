#include <iostream>
#include<cstring>
using namespace std;

class STRING
{
    char *x;
    int length;

       public:

         STRING();
         STRING(char *);
         bool operator == (STRING j)
         {
             cout<<"\n"<<j.x;

                if(strcmp(x,j.x)==0)
                   {
                      return true;
                   }

                else
                return false;
         }
         void operator +(STRING b)
         {
             strcat(x,b.x);
             cout<<"\n"<<x;
         }
         ~STRING()
         {
             delete x;
         }
};

int main()
{
    char a[7]="hello";
    STRING x("nepal"),y(a),z("nepal"),s;
    s=x;
      if(x==s)
        cout<<"\nthe strings x have same length and same characters as y";
     else
        cout<<"\nthe strings x does not have same characters as y";
        y+x;
    return 0;
}

  STRING::STRING(){}
  STRING::STRING (char *a)
  {
      x=new char[strlen(a)+1];
      strcpy(x,a);
      cout<<"\nthe copied str is="<<x;
  }


