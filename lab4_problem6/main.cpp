#include <iostream>

using namespace std;

class student
{
    int rn;
    char name[20];
    public:
    void getinfo();
    void putinfo();
};
class internal_exam:virtual public student
{
    protected:
    int m[7];
   public:
   void getinfo();
   void putinfo();
   float calc_avb();
};
class final_exam:virtual public student
{
   protected:
   int m[7];
   public:
   void getinfo();
   void putinfo();
   float calc_avb();
};
class avr_marks:public internal_exam,public final_exam
{
    float average;
    public:
        void getinfo();
        void putinfo();
        void calculate();
};
int main()
{
    avr_marks x;
    x.getinfo();
    x.calculate();
    x.putinfo();
    return 0;
}

   void student::getinfo()
   {
       cout<<"\nEnter the name and roll number of the student\n";
       cin>>name>>rn;
   }
   void student::putinfo()
   {
       cout<<"\nname ="<<name<<"\nroll number ="<<rn;
   }
   void internal_exam::getinfo()
   {
       int i;
        for(i=0;i<7;i++)
        {
            cout<<"\nEnter the marks obtained in internal exam in subject no."<<i+1<<"=";
            cin>>m[i];
        }
   }
   void internal_exam::putinfo()
   {
       cout<<"\n\tMarks obtained in internal exam";
       int i;
       for(i=0;i<7;i++)
       {
           cout<<"\nsubject no."<<i+1<<" is="<<m[i];
       }
   }
   void final_exam::getinfo()
   {
       int i;
        for(i=0;i<7;i++)
        {
            cout<<"\nEnter the marks obtained in external exam in subject no."<<i+1<<"=";
            cin>>m[i];
        }
   }
   void final_exam::putinfo()
   {
       cout<<"\n\tMarks obtained in final exam";
       int i;
       for(i=0;i<7;i++)
       {
           cout<<"\nsubject no."<<i+1<<" is "<<m[i];
       }
   }
   void avr_marks::getinfo()
   {
       student::getinfo();
       internal_exam::getinfo();
       final_exam::getinfo();
   }
   void avr_marks::calculate()
   {
        average=(internal_exam::calc_avb()+final_exam::calc_avb())/2;
   }
   void avr_marks::putinfo()
   {
       cout<<"\n\tobtained average marks=";
       cout<<average;
   }
    float internal_exam::calc_avb()
    {
        float total=0;
         for (int i=0;i<7;i++)
         {
             total+=m[i];
         }
         return (total/7);
    }
    float final_exam::calc_avb()
        {
        float total=0;
         for (int i=0;i<7;i++)
         {
             total+=m[i];
         }
         return (total/7);
    }
