////////////////////////////////////////////////////////////
// Objective: Prove that if an imaginary part is added to a
// Hermitian matrix, then the inverse preserve some sort of symmetry
// for off-diagonal elements.
//
//                  Author: Amin Ahmadi
//                    Dec 17, 2016
//
// I've convinced myself there is not meaningful
// realtion between the symmetric elements of retarded and advanced
// Green's function even for a 1D chain, not bother to go to 2D to
// compile: g++ test_hermitian.cpp -larmadillo
/////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>		// setprecision
#include <armadillo>
#include <cstdlib> 		// srand, rand
// #include <complex>

using namespace std;
using namespace arma;
// using namespace std::complex_literals;

int main(int argc, char* argv[]){

  // defining Pauli's matrices:
  const cx_mat sigx = { {0.0,1.0+0i},
			{1.0+0i,0.0} };
  const cx_mat sigy = { {0.0,-1.0i},
   			{1.0i,0.0} };
  const cx_mat sigz = { {1.0,0.0i},
  			{0.0i,-1.0} };
  const cx_mat sig0 = { {1.0,0.0i},
  			{0.0i,1.0} };
  
  const int dim_lat = 50;	// lattice spacial dimension, chain length
  const int dim = 2 * dim_lat;	// 2 shows the spin state

  
  
  cx_mat B(dim,dim); B.zeros(); // Hamiltonian of a chain
  double aux =0.0;
  B(0,0, size(sig0)) = sigz; 	// The magnetic site
  for (int i=1; i<dim_lat; i++){
    B(2*i,2*i, size(sig0)) = sig0;        // on-site energy and Zeeman impurities
    aux = rand()/(10.0*RAND_MAX);
    B(2*i,2*(i-1), size(sig0)) = 0.1*sigx + aux*sigy + sigz;    // hoping amplitude, scattered by sigma_x 
    B(2*(i-1),2*i, size(sig0)) = B(2*i,2*(i-1), size(sig0)).t();
  }
  // add self energy to the last site
  B(2*(dim_lat-1), 2*(dim_lat-1), size(sig0)) = (0.0+1.0i)*sig0;
  
  // B(dim-2, dim-2, size(sig0)).print("B = ");

  cx_mat A = inv(B);

  // A(dim-4,dim-2, size(sig0)).print("Ac()= ");
  // A(dim-2,dim-4, size(sig0)).print("Ar()= ");
  
  ( A(dim-2,dim-4, size(sig0)).t() - A(dim-4,dim-2, size(sig0)) ).print("Adiff = ");

  // imag(B).print("B = ");
  A(0, dim-2, size(sig0)).print("AN0 = ");
  A(dim-2, 0, size(sig0)).print("A0N = ");
  A(dim-2, dim-2, size(sig0)).print("ANN = ");
  A(0, 0, size(sig0)).print("A00 = ");

  return 0;
}
// I've convinced myself there is no meaningful relation beween
// retarded and advanced Green's function
