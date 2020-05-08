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
class sales:public publication
{
protected:
    float sale_dollor[3];
public:
    void getdata();
    void putdata();
};
class book:public sales
{
    int page_count;
    public:
    void getdata();
    void showdata();
};
class tape:public sales
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
        sales::getdata();
        cout<<"\nEnter the total number of pages in the book=";
        cin>>page_count;
    }
    void book::showdata()
    {
        publication::showdata();
        putdata();
        cout<<"\nthe page count of "<<title<<" is ="<<page_count;
    }
    void tape::getdata()
    {
        publication::getdata();
        sales::getdata();
        cout<<"\nEnter the playing time of the tape=";
        cin>>playing_time;
    }
    void tape::showdata()
    {
        publication::showdata();
        putdata();
        cout<<"\nthe playing time of "<<title<<" is ="<<playing_time;
    }
    void sales::getdata()
    {
        cout<<"\nEnter the sales in dolor for 1st month\n";
        cin>>sale_dollor[0];
        cout<<"\nEnter the sales in dolor for 2nd month\n";
        cin>>sale_dollor[1];
        cout<<"\nEnter the sales in dolor for 3rd month\n";
        cin>>sale_dollor[2];
    }
    void sales::putdata()
    {
        cout<<"\nthe sales of 1st month is ="<<sale_dollor[0];
        cout<<"\nthe sales of 2nd month is ="<<sale_dollor[1];
        cout<<"\nthe sales of 3rd month is ="<<sale_dollor[2];
    }
