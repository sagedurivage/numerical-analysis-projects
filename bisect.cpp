#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function definition
double f(double x) {
    return 0.0;
}

// bisection method
double bisection(double a, double b, double tol, double true_root) {
    double c = 0.0;
    int iter = 0;

    cout << left << setw(3) << "n" << setw(12) << "c" << setw(15) << "f(c)" << setw(15) << "Absolute Error" << "\n";
        
    // check if the root is found within the given tolerance
    while (abs(c - true_root) > tol) {
        // calculate midpoint
        c = (a + b) / 2;

        // output first 5 iteration details
        if (iter < 5) {
            cout << left << setw(3) << iter << setw(12) << c << setw(15) << f(c) << setw(15) << abs(c - true_root) << "\n";
        }

        // update interval [a, b]
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iter++;
    }
    // +/- correction
    if (true_root > 0) {
        c = (a + b) / 2;
    }

    cout << "Root within tolerance found after " << iter + 1 << " iterations.\n";
    return c;
}

int main() {
    // interval [a, b]
    double a = 0.0;
    double b = 0.0;

    // error tolerance
    double tolerance = 1e-6;

    // true root for absolute error calculation
    double true_root = 0.0;

    // apply bisection
    double root = bisection(a, b, tolerance, true_root);

    cout << "Approximate root: " << root << "\n";

    return 0;
}

/*
1.a) Report:

Parameters:
f = exp(sin(x)) + pow(x, 4) - 2 * pow(x, 3) - pow(x, 2) - 1
a = -2.0
b = -0.5
true_root = -0.714889460738844
a = 0.5
b = 2.0
true_root = 0.678512694194867

Interval [-2, -0.5]
n  c           f(c)           Absolute Error 
0  -1.25       4.17229        0.535111       
1  -0.875      0.624552       0.160111       
2  -0.6875     -0.0692062     0.0273895      
3  -0.78125    0.210372       0.0663605      
4  -0.734375   0.0552971      0.0194855      
Root within tolerance found after 20 iterations.
Approximate root: -0.714889

Interval [0.5, 2]
n  c           f(c)           Absolute Error 
0  1.25        -1.44426       0.571487       
1  0.875       -0.36482       0.196487       
2  0.6875      -0.0128738     0.00898731     
3  0.59375     0.102855       0.0847627      
4  0.640625    0.0501292      0.0378877      
Root within tolerance found after 20 iterations.
Approximate root: 0.678512
*/