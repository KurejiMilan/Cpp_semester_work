#include <iostream>

using namespace std;

class publication
{
    protected:
    char title[20];
    float price;
public:
    void getdata();
    void showdata();

};
class book:public publication
{
    int page_count;
    public:
    void getdata();
    void showdata();
};
class tape:public publication
{
    float playing_time;
    public:
    void getdata();
    void showdata();
};
int main()
{
    book a;
    tape b;
    a.getdata();
    b.getdata();
    a.showdata();
    b.showdata();
    return 0;
}
    void publication::getdata()
    {
        cout<<"\nEnter the Title=";
        cin>>title;
        cout<<"\nEnter the price=";
        cin>>price;
    }
    void publication::showdata()
    {
        cout<<"\nThe title is ="<<title<<" and the price="<<price;
    }
    void book::getdata()
    {
        publication::getdata();
        cout<<"\nEnter the total number of pages in the book=";
        cin>>page_count;
    }
    void book::showdata()
    {
        publication::showdata();
        cout<<"\nthe page count of "<<title<<" is ="<<page_count;
    }
    void tape::getdata()
    {
        publication::getdata();
        cout<<"\nEnter the playing time of the tape=";
        cin>>playing_time;
    }
    void tape::showdata()
    {
        publication::showdata();
        cout<<"\nthe playing time of "<<title<<" is ="<<playing_time;
    }
