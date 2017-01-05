// ************************************************************
// Draw a histogram for given integer numbers
//               Amin Ahmadi
//               Jan 5 2017
// ************************************************************
#include <iostream>
#include <cstdlib>		// rand and srand
#include <ctime>			// initialize srand with time(NULL)
#include <cmath>

using namespace std;

void sort_bb(int* vec, int dim);

void vecPrint(int* vec, int dim);

void starPrint(int* vec, int dim);

int** histarray(int* vec, int dim); // return dimx2 array,

int main(int argc, char* argv[])
{
  int  dim = 30;
  int range = 10;		// range of number, MAX
  int* vec1;
  vec1 = new int[dim];

  // fill the vector with random numbers
  int Norm = 1000;
  for(int k=0; k<Norm; k++)
    {
      srand(time(NULL));		// seeding the random numbers
      for(int i=0; i<dim; i++)
	{
	  vec1[i] += rand() % range - int(range/2);
	}
    }

  for(int i=0; i<dim; i++)
    {
      vec1[i] /= Norm;
    }
  
  // vecPrint(vec1,dim);
  // starPrint(vec1,dim);
  sort_bb(vec1,dim);

  vecPrint(vec1,dim);
  starPrint(vec1,dim);
  
  delete[] vec1;


  return 0;
}
//********************************************************************

void vecPrint(int* vec, int dim)
{
  for(int i=0; i<dim; i++)
    {
      cout << vec[i] << "  ";
    }
  cout << "\n";
}
//************************************************************
void starPrint(int* vec, int dim)
{
  int  sum = 0;
  // for(int i=0; i<dim; i++)
  // {
  //   sum += vec[i];
  // }
  // double norm = 1./sum; 
  for(int i=1; i<dim; i++)
    {
      cout << "*";
      if(vec[i-1]!=vec[i])
	{
	  cout << "\n";
	}
    }
  cout << "\n";
}
// ************************************************************
void sort_bb(int* vec, int dim)
{

  for(int i=1; i<dim; i++)    
    {
      for(int j=i; j>0; j--)
	{
	  if (vec[j]>vec[j-1])
	    {
	      int aux = vec[j];
	      vec[j] = vec[j-1];
	      vec[j-1] = aux;
	    }
	}
    }
}	      
// ************************************************************
int** histarray(int* vec, int dim)
{
// return dimx2 array,
  int** histarr;
  histarr = new int* [2];
  histarr[0] = new int [dim];
  histarr[1] = new int [dim];

  for(int i=0; i<dim; i++){
    histarr[0][i] = i;
    histarr[1][i] = i;
  }

  return histarr;
}
