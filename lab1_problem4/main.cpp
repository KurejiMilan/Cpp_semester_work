#include <iostream>

using namespace std;

class medStore
{
    int st_qun,or_qun;
     public:
     void proces_input(int x,int y)
     {
         st_qun=x;
         or_qun=y;
          if(or_qun>st_qun)
       {
         cout<<"\nNot enough quantity available in store.\n";
       }
       else if(or_qun>16)
         {
             if(st_qun>40)
             {
                cout<<"\nYour order is accepted\n";
             }
             else
             {
               cout<<"\nYour can't order more than 16 items currently.\n";
             }
         }
        else
        {
            cout<<"\nYour order is accepted\n";
        }
     }
};

int main()
{
    medStore m;
    int store_quantity,order_quantity;
    cout<<"enter the amount of medicine available in store.\n";
    cin>>store_quantity;
    cout<<"\nenter the amount of medicines you want to purchase\n";
    cin>>order_quantity;
     m.proces_input(store_quantity,order_quantity);
    return 0;
}
