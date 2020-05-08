#include <iostream>

using namespace std;
class store
{
    int largest,sm;
    public:
        void process(int,int,int);
};
int main()
{   store a;
    int x,y,z;
    cout<<"enter three numbers\n";
    cin>>x>>y>>z;
    a.process(x,y,z);
    return 0;
}

void store::process(int x,int y,int z)
{
    if(x>y)
    {
        if(x>z)
        {
            largest=x;
        }
        if(y>z)
        {
            sm=z;
        }
        else
            sm=y;
    }
    else if(y>z)
    {
        largest=y;
        if(z>x)
        sm=x;
        else
         sm=z;
    }
    else
    {
     largest=z;3413
     if(y>z)
      sm=z;
     else
      sm=y;
    }
    cout<<"\nthe largest number is "<<largest<<" the smallest number is "<<sm;
}

