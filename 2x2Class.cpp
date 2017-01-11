#include <iostream>
#include <iomanip>		// setprecision

using namespace std;

class Matrix2x2
{
private:
  double mtx[2][2];
public:
  // Overriden constructor
  // Matrix2x2();
  Matrix2x2(const Matrix2x2& otherMatrix);
  Matrix2x2(double x00, double x01, double x10, double x11);
  // Methods
  void MtxPrint();
  double det();
  Matrix2x2 inv();
  // operators
  Matrix2x2& operator=(const Matrix2x2& z); // assignment operator
  Matrix2x2 operator-() const;	// unary operator
  // binary operator
  Matrix2x2 operator+(const Matrix2x2 z) const;
  Matrix2x2 operator-(const Matrix2x2 z) const;
  ~Matrix2x2(){};
};


Matrix2x2::Matrix2x2(double x00=0.0, double x01=0.0, double x10=0.0, double x11=0.0)
{
  mtx[0][0] = x00;
  mtx[0][1] = x01;
  mtx[1][0] = x10;
  mtx[1][1] = x11;
}

Matrix2x2::Matrix2x2(const Matrix2x2& otherMarix)
{
  mtx[0][0] = otherMarix.mtx[0][0];
  mtx[0][1] = otherMarix.mtx[0][1];
  mtx[1][0] = otherMarix.mtx[1][0];
  mtx[1][1] = otherMarix.mtx[1][1];
}

void Matrix2x2::MtxPrint(){
  int dim = 2;
  for(int i=0; i<dim; i++)
  {
    for(int j=0; j<dim; j++)
    {
      std::cout << setprecision(3);
      std::cout << mtx[i][j] << "  " ;
    }
    std::cout << "\n";
  }
}

double Matrix2x2::det()
{
  return mtx[0][0]*mtx[1][1] - mtx[0][1]*mtx[1][0];
}

Matrix2x2 Matrix2x2::inv()
{
  Matrix2x2 invMtx;
  if (det() != 0)
  {
    invMtx.mtx[0][0] =  mtx[1][1]/det();
    invMtx.mtx[0][1] = -mtx[0][1]/det();
    invMtx.mtx[1][0] = -mtx[1][0]/det();
    invMtx.mtx[1][1] =  mtx[0][0]/det();
  }
  else
  {
    cout << "Error, the Matrix does not have inverse \n";
    invMtx.mtx[0][0] = 0.0 ;
    invMtx.mtx[0][1] = 0.0 ;
    invMtx.mtx[1][0] = 0.0 ;
    invMtx.mtx[1][1] = 0.0 ;
  }
  return invMtx;
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
  mtx[0][0] = z.mtx[0][0];
  mtx[0][1] = z.mtx[0][1];
  mtx[1][0] = z.mtx[1][0];
  mtx[1][1] = z.mtx[1][1];

  return *this;
}

Matrix2x2 Matrix2x2::operator-() const
{
  Matrix2x2 w;
  w.mtx[0][0] = -mtx[0][0];
  w.mtx[0][1] = -mtx[0][1];
  w.mtx[1][0] = -mtx[1][0];
  w.mtx[1][1] = -mtx[1][1];

  return w;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 z) const
{
  Matrix2x2 w;
  w.mtx[0][0] = mtx[0][0] + z.mtx[0][0];
  w.mtx[0][1] = mtx[0][1] + z.mtx[0][1];
  w.mtx[1][0] = mtx[1][0] + z.mtx[1][0];
  w.mtx[1][1] = mtx[1][1] + z.mtx[1][1];

  return w;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 z) const
{
  Matrix2x2 w;
  // w.mtx[0][0] = mtx[0][0] - z.mtx[0][0];
  // w.mtx[0][1] = mtx[0][1] - z.mtx[0][1];
  // w.mtx[1][0] = mtx[1][0] - z.mtx[1][0];
  // w.mtx[1][1] = mtx[1][1] - z.mtx[1][1];
  w = *this + (-z);		// nice :-)
  return w;
}
  
// ************************************************************
// ************************************************************
int main(int argc, char* argv[])
{
  Matrix2x2 M(1,2,3,4);

  
  Matrix2x2 H;

    
  M.MtxPrint();
  H.MtxPrint();

  H = -M;
  H.MtxPrint();
  
  cout << "Matrix M is \n";
  cout << M.det() << endl;

  Matrix2x2 Z(4,5,6,7);

  Z.MtxPrint();

  H = M + Z;

  H.MtxPrint();

  H = M - Z;

  H.MtxPrint();
  // cout << "Matrix H is \n";
  // H.MtxPrint();

  Matrix2x2 I;
  I = M.inv();

  cout << "Inverse is \n";
  I.MtxPrint();
  return 0;
}
