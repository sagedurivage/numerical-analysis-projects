#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function definition
double f(double x) {
    return 0.0;
}

// fixed-point method
double fixedPoint(double x0, double tol, double true_root) {
    double x_curr = x0;
    int iter = 0;

    cout << left << setw(3) << "n" << setw(12) << "x_curr" << setw(15) << "f(x_curr)" << setw(15) << "Absolute Error" << "\n";

    while (abs(x_curr - true_root) > tol) {
        double fx_curr = f(x_curr);

        // output first 5 iteration details
        if (iter < 5) {
            cout << left << setw(3) << iter << setw(12) << x_curr << setw(15) << fx_curr << setw(15) << abs(x_curr - true_root) << "\n";
        }

        // update x
        x_curr = 0.5 * sin(x_curr) + 1;

        iter++;
    }

    return x_curr;
}

int main() {
    // initial point
    double x0 = 0.0;

    // error tolerance
    double tolerance = 1e-6;

    // true root for absolute error calculation
    double true_root = 0.0;

    // apply fixed-point method
    double root = fixedPoint(x0, tolerance, true_root);

    cout << "Approximate root: " << setprecision(6) << fixed << root << "\n";

    return 0;
}

/*
2.b) Report:

Parameters:
f = x - 0.5 * sin(x) - 1
g = 0.5 * sin(x) + 1
x0 = 0.5
true_root = 1.498701133517848

Initial point x0 = 0.5
n  x_curr      f(x_curr)      Absolute Error 
0  0.5         -0.739713      0.998701       
1  1.23971     -0.233133      0.258988       
2  1.47285     -0.024758      0.0258558      
3  1.4976      -0.00105798    0.00109782     
4  1.49866     -3.84046e-05   3.98398e-05    
Approximate root: 1.498701
Remark: With this choice of g(x), the method converges.
*/