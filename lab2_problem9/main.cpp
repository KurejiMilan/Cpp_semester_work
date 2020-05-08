#include <iostream>
#define M 7
#define N 7
using namespace std;

class MATRIX
{
    int mat[M][N],r,c;

public:

    MATRIX(){}
    MATRIX (int,int);

    void matrix_in();
    void matrix_out();
    MATRIX operator +(MATRIX b)
    {  int x=r;
        int y=c;
        MATRIX z(x,y);
        {
           for(int i=0;i<r;i++)
           {
               for(int j=0;j<c;j++)
               {
                   z.mat[i][j]=mat[i][j]+b.mat[i][j];
               }
           }
       }
       return z;
    }
  ~MATRIX()
  {

  }
};


int main()
{
    int x,y;

    cout<<"Enter the size of rows and columns\n";
    cin>>x>>y;

    MATRIX a(x,y),b(x,y),c(x,y);
    cout<<"\nEnter the first Matrix\n";
    a.matrix_in();
    a.matrix_out();
    cout<<"\nEnter the second Matrix\n";
    b.matrix_in();
    b.matrix_out();
    cout<<"\nThe sum of two matrix is=\n";
    c=a+b;
    c.matrix_out();

    return 0;
}

    MATRIX::MATRIX(int x,int y)
     {
         r=x;
         c=y;
     }
   void MATRIX::matrix_in()
       {
           for(int i=0;i<r;i++)
           {
               for(int j=0;j<c;j++)
               {
                   cin>>mat[i][j];
               }cout<<"\n";
           }
       }
   void MATRIX::matrix_out()
    {
           for(int i=0;i<r;i++)
           {
               for(int j=0;j<c;j++)
               {
                   cout<<mat[i][j]<<"\t";
               }
               cout<<"\n";
           }
    }
