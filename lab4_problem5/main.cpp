#include <iostream>

using namespace std;

class Inverntory
{
    int quant;
    int recorder;
    double price;
    char *descrip;
    public:
    Inverntory(int q,int r,double p,char *d);
    ~Inverntory(){}
    void print();
};

class Auto:public Inverntory
{
    char *manufacturer;
    public:
    Auto(int q,int r,double p,char *d,char *man);
    ~Auto(){}
    void print();
};

class Trasmission:public Inverntory
{
    char *vendor;
    public:
    Trasmission(int q,int r,double p,char *d,char *ven);
    ~Trasmission(){}
    void print();
};

int main()
{
    char des[30]="this is a beautiful car",man[8]="Toyota",des2[20]="inventoried",venn[10]="Aztec Inc";
    Auto car(5,2,15545.91,des,man);
    car.print();
    Trasmission trass(25,10,1789.98,des2,venn);
    trass.print();
    return 0;
}

Inverntory::Inverntory(int q,int r,double p,char *d)
{
    quant=q;
    recorder=r;
    price=p;
    descrip=d;
}
Auto::Auto(int q,int r,double p,char *d,char *man):Inverntory(q,r,p,d)
{
    manufacturer=man;
}
Trasmission::Trasmission(int q,int r,double p,char *d,char *ven):Inverntory(q,r,p,d)
{
    vendor=ven;
}

void Inverntory::print()
{
    cout<<"\nquantity ="<<quant<<"\nrecorder ="<<recorder<<"\nprice ="<<price<<"\ndescription ="<<descrip;
}
void Auto::print()
{
    Inverntory::print();
    cout<<"\nManufacturer ="<<manufacturer;
}
void Trasmission::print()
{
    Inverntory::print();
    cout<<"\nvendor ="<<vendor;
}
