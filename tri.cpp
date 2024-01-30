#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// representation of a tridiagonal matrix
struct Tridiagonal {
   // lower diagonal
   vector<double> a;
   // main diagonal
   vector<double> b;
   // upper diagonal
   vector<double> c;
   // right-hand side from system: Ax = d
   vector<double> d;
};

// using naive Gaussian from class
void tri(Tridiagonal& matrix, int n, int& compCost) {
   // forward elimination
   for (int i = 1; i < n; i++) {
      double multiplier = matrix.a[i] / matrix.b[i - 1];
      matrix.b[i] -= multiplier * matrix.c[i - 1];
      matrix.d[i] -= multiplier * matrix.d[i - 1];

      // count 2 multiplications
      compCost += 2;
   }

   // backward substitution
   matrix.d[n - 1] /= matrix.b[n - 1];

   // count 1 division
   compCost += 1;

   for (int i = n - 2; i >= 0; i--) {
      matrix.d[i] = (matrix.d[i] - matrix.c[i] * matrix.d[i + 1]) / matrix.b[i];

      // count 1 multiplication & 1 division
      compCost += 2;
   }
}

int main() {
   const int n = 100;
   int compCost = 0;

   // initialize system
   Tridiagonal matrix;
   // lower diagonal: 99 elements, all initialized to -1
   matrix.a.resize(n - 1, -1);
   // main diagonal: 100 elements, all initialized to 4
   matrix.b.resize(n, 4);
   // upper diagonal: 99 elements, all initialized to -1
   matrix.c.resize(n - 1, -1);
   // right-hand side: 100 elements, first & last element initialized to -20, elements 2-99 initialized to 40
   matrix.d.resize(n, 0);
   matrix.d[0] = matrix.d[99] = -20;
   for (int i = 1; i < n - 1; i++) {
      matrix.d[i] = 1;
   }

   // solve system
   tri(matrix, n, compCost);

   // output solution
   cout << "\nSolution:" << endl;
   for (int i = 0; i < n; i++) {
      cout << "x" << i + 1 << " = " << fixed << setprecision(2) << matrix.d[i] << endl;
   }

   // output computational cost
   cout << "\nComputational Cost: " << compCost << " long operations" << endl << endl;

   return 0;
}

/*
Terminal Output:

Solution:
x1 = -5.26
x2 = -1.04
x3 = 0.09
x4 = 0.39
x5 = 0.47
x6 = 0.49
x7 = 0.50
x8 = 0.50
x9 = 0.50
x10 = 0.50
x11 = 0.50
x12 = 0.50
x13 = 0.50
x14 = 0.50
x15 = 0.50
x16 = 0.50
x17 = 0.50
x18 = 0.50
x19 = 0.50
x20 = 0.50
x21 = 0.50
x22 = 0.50
x23 = 0.50
x24 = 0.50
x25 = 0.50
x26 = 0.50
x27 = 0.50
x28 = 0.50
x29 = 0.50
x30 = 0.50
x31 = 0.50
x32 = 0.50
x33 = 0.50
x34 = 0.50
x35 = 0.50
x36 = 0.50
x37 = 0.50
x38 = 0.50
x39 = 0.50
x40 = 0.50
x41 = 0.50
x42 = 0.50
x43 = 0.50
x44 = 0.50
x45 = 0.50
x46 = 0.50
x47 = 0.50
x48 = 0.50
x49 = 0.50
x50 = 0.50
x51 = 0.50
x52 = 0.50
x53 = 0.50
x54 = 0.50
x55 = 0.50
x56 = 0.50
x57 = 0.50
x58 = 0.50
x59 = 0.50
x60 = 0.50
x61 = 0.50
x62 = 0.50
x63 = 0.50
x64 = 0.50
x65 = 0.50
x66 = 0.50
x67 = 0.50
x68 = 0.50
x69 = 0.50
x70 = 0.50
x71 = 0.50
x72 = 0.50
x73 = 0.50
x74 = 0.50
x75 = 0.50
x76 = 0.50
x77 = 0.50
x78 = 0.50
x79 = 0.50
x80 = 0.50
x81 = 0.50
x82 = 0.50
x83 = 0.50
x84 = 0.50
x85 = 0.50
x86 = 0.50
x87 = 0.50
x88 = 0.50
x89 = 0.50
x90 = 0.50
x91 = 0.50
x92 = 0.50
x93 = 0.50
x94 = 0.50
x95 = 0.49
x96 = 0.47
x97 = 0.39
x98 = 0.11
x99 = -0.97
x100 = -5.00

Computational Cost: 397

*/