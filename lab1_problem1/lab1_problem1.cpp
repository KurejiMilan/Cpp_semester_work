#include <iostream>

using namespace std;

class length
{
    int feet;
    int inches;

public:
    void get_distance();
    void show_distance();
    void add_distance(length,length);
    void show_added_distance();
};
int main()
{
    length x,y,z;
    x.get_distance();
    x.show_distance();
    y.get_distance();
    y.show_distance();

    z.add_distance(x,y);
    z.show_added_distance();
    return 0;
}

inline void length::get_distance()
{
    cout<<"\n Enter the distance in feet and inches \n";
    cin>>feet>>inches;
}

inline void length::show_distance()
{
    cout<<"\n the distance you have entered is "<<feet<<"feet and "<<inches<<"inches. \n";
}

inline void length::add_distance(length x,length y)
{
    int i;
    i=(x.inches+y.inches)/12;
    feet=x.feet+y.feet+i;
    if((x.inches+y.inches)>12)
    {
        inches=x.inches+y.inches)-12;
    }
    else
    inches= x.inches+y.inches;
}
inline void length::show_added_distance()
{
    cout<<"\n the added distance is "<<feet<<" feet and "<<inches<<" inches.";
}
