#include <iostream>
#include <cstdlib> 		// for rand and srand
#include <ctime>			// to seed

using namespace std;

void sort_bb(int* vec, int dim);   // sort vec
void vecPrint(int*  vec, int dim); // print a vector

int main(int argc, char* argv[])
{
  int  dim = 25;
  int* vec1;
  vec1 = new int[dim];		// allocate 
  
  // Randomly fill the vector
  srand(time(NULL));
  for(int i=0; i<dim; i++)
    {
      vec1[i] = rand()%20;
    }
  
  vecPrint(vec1, dim);
  
  sort_bb(vec1, dim);

  vecPrint(vec1, dim);
  delete[] vec1;

  return 0;
}

void vecPrint(int* vec, int dim)
{
  for(int i=0; i<dim; i++)
    {
      cout << vec[i] << "  ";
    }
  cout << "\n";
}

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
