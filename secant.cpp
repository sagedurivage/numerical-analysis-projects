#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function definition
double f(double x) {
    return 0.0;
}

// differentiation
double df(double x) {
    return 0.0;
}

// secant method
double secantMethod(double x0, double x1, double tol, double true_root) {
    double x_curr = x1;
    double x_prev = x0;
    int iter = 0;

    cout << left << setw(3) << "n" << setw(12) << "x_curr" << setw(15) << "f(x_curr)" << setw(15) << "Absolute Error" << "\n";

    while (abs(x_curr - true_root) > tol) {
        double fx_curr = f(x_curr);
        double fx_prev = f(x_prev);

        // output first 5 iteration details
        if (iter < 5) {
            cout << left << setw(3) << iter << setw(12) << x_curr << setw(15) << fx_curr << setw(15) << abs(x_curr - true_root) << "\n";
        }

        // update x
        double x_next = x_curr - (fx_curr * (x_curr - x_prev)) / (fx_curr - fx_prev);
        x_prev = x_curr;
        x_curr = x_next;

        iter++;
    }

    return x_curr;
}

int main() {
    // initial point
    double x0 = 0.0;
    // newton's method
    double x1 = x0 - f(x0) / df(x0);

    // error tolerance
    double tolerance = 1e-6;

    // true root for absolute error calculation
    double true_root = 0.0;

    // apply secant method
    double root = secantMethod(x0, x1, tolerance, true_root);

    cout << "Approximate root: " << setprecision(6) << fixed << root << "\n";

    return 0;
}

/*
2.a) Report:

Parameters:
f = x - 0.5 * sin(x) - 1
df = -0.5 * cos(x) + 1
x0 = 0.5
true_root = 1.498701133517848

Initial point x0 = 0.5
n  x_curr      f(x_curr)      Absolute Error 
0  1.81807     0.333279       0.31937        
1  1.40867     -0.0847747     0.0900328      
2  1.49169     -0.00674767    0.0070125      
3  1.49887     0.000160982    0.00016699     
Approximate root: 1.498701
*/