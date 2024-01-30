#include <iostream>
#include <vector>

using namespace std;

/* coeff[]: array of coefficients from polynomial of form
            coeff[0]x^(n - 1) + coeff[1]x^(n - 2) + ... + coeff[n - 1]x^(n - n)
   n: number of coefficients in the polynomial (size of the array)
   x: value at which the polynomial is being evaluated at
*/
int horners(int coeff[], int n, int x)
{
   // initialize to first coefficient in array
   int sum = coeff[0];

   for (unsigned i = 1; i < n; ++i)
   {
      /* polynomial evaluated in form
         (((...(((coeff[0] * x) + coeff[1]) * x) + ... coeff[n - 2]) * x) + coeff[n - 1])
      */
      sum = (sum * x) + coeff[i];
   }

   return sum;
}

int main()
{
   // Evaluate p(x) = x^5 − 3x^3 − 4x^2 + 10, at x = 2
   int coeff[] = {1, 0, -3, -4, 0, 10};
   int n = sizeof(coeff) / sizeof(coeff[0]);    // total bytes / bytes of first element = size of array
   int x = 2;

   cout << "p(" << x << ") = " << horners(coeff, n, x) << endl;

   return 0;
}