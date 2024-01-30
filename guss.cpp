#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// number of variables to solve for
const int N = 4;

void gaussianElimination(double matrix[N][N + 1]) {
   for (int i = 0; i < N; i++) {
      // partial pivoting
      int maxRow = i;
      for (int j = i + 1; j < N; j++) {
         if (abs(matrix[j][i]) > abs(matrix[maxRow][i])) {
               maxRow = j;
         }
      }

      // swap maxRow with current row
      for (int j = i; j <= N; j++) {
         double temp = matrix[i][j];
         matrix[i][j] = matrix[maxRow][j];
         matrix[maxRow][j] = temp;
      }

      // make main diagonal elements 1
      for (int j = i + 1; j < N; j++) {
         double factor = matrix[j][i] / matrix[i][i];
         for (int k = i; k <= N; k++) {
               matrix[j][k] -= factor * matrix[i][k];
         }
      }
   }

   // backward substitution
   for (int i = N - 1; i >= 0; i--) {
      for (int j = i + 1; j < N; j++) {
         matrix[i][N] -= matrix[i][j] * matrix[j][N];
      }
      matrix[i][N] /= matrix[i][i];
   }
}

int main() {
   // augmented matrix [A|b] for system: Ax = b
   double augmentedMatrix[N][N + 1] = {
      {0.4096, 0.1234, 0.3678, 0.2943, 0.4043},
      {0.2246, 0.3872, 0.4015, 0.1129, 0.1550},
      {0.3645, 0.1920, 0.3781, 0.0643, 0.4240},
      {0.1784, 0.4002, 0.2786, 0.3927, 0.2557}
   };

   gaussianElimination(augmentedMatrix);

   // output solution
   cout << "\nSolution:" << endl;
   for (int i = 0; i < N; i++) {
      cout << "x" << i + 1 << " = " << fixed << setprecision(4) << augmentedMatrix[i][N] << endl;
   }
   cout << endl;

   return 0;
}

/*
Terminal Output:

Solution:
x1 = 3.4606
x2 = 1.5610
x3 = -2.9342
x4 = -0.4301

*/
