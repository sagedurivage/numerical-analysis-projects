#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using namespace std;

// function definition
double f(double x) {
    return 0.0;
}

// differentiation
double df(double x) {
    return 0.0;
}

// newton's method
double newtonMethod(double x0, double tol, double true_root) {
    int iter = 0;

    // track time
    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

    cout << left << setw(3) << "n" << setw(12) << "x0" << setw(15) << "f(x0)" << setw(15) << "Absolute Error" << "\n";

    while (abs(x0 - true_root) > tol) {
        // output first 5 iteration details
        if (iter < 5) {
            cout << left << setw(3) << iter << setw(12) << x0 << setw(15) << f(x0) << setw(15) << abs(x0 - true_root) << "\n";
        }

        // update x
        x0 = x0 - f(x0) / df(x0);

        iter++;
    }

    chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();
    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Time taken: " << duration.count() << " microseconds\n";
    return x0;
}

int main() {
    // initial point
    double x0 = 0.0;

    // error tolerance
    double tolerance = 1e-6;

    // true root for absolute error calculation
    double true_root = 0.0;

    // apply newton's method
    double root = newtonMethod(x0, tolerance, true_root);

    cout << "Approximate root: " << setprecision(6) << fixed << root << "\n";

    return 0;
}

/*
1.b) Report:

Parameters:
f = exp(sin(x)) + pow(x, 4) - 2 * pow(x, 3) - pow(x, 2) - 1
df = cos(x) * exp(sin(x)) + 4 * pow(x, 3) - 6 * pow(x, 2) - 2 * x
x0 = -2.0
true_root = -0.714889460738844
x0 = -0.43
true_root = 2.345483689913113
x0 = 3.0
true_root = 2.345483689913113

Initial point x0 = -2
n  x0          f(x0)          Absolute Error 
0  -2          27.4028        1.28511        
1  -1.47472    8.33889        0.759827       
2  -1.11046    2.43432        0.395566       
3  -0.878032   0.640482       0.163143       
4  -0.75676    0.125354       0.0418704      
Time taken: 122 microseconds
Approximate root: -0.714889

Initial point x0 = -0.43
n  x0          f(x0)          Absolute Error 
0  -0.43       -0.332592      2.77548        
1  10.0695     8137.17        7.72405        
2  7.71439     2565.64        5.3689         
3  5.96222     803.953        3.61673        
4  4.6723      250.107        2.32682        
Time taken: 119 microseconds
Approximate root: 2.345484
Remark: A choice of initial point so close to the local minimum of x = -0.435
    gives a tangent line that intersects far out of our range [-2, 3] of roots
    at x = 10.0695... before allowing the subsequent tangents to trend back
    toward the right-most root in our range. This is illustrated in the
    attached graph.

Initial point x0 = 3
n  x0          f(x0)          Absolute Error 
0  3           18.1516        0.654516       
1  2.61264     4.75611        0.267159       
2  2.41216     0.913601       0.0666808      
3  2.35107     0.0702865      0.00558547     
4  2.34553     0.000546479    4.37693e-05    
Time taken: 114 microseconds
Approximate root: 2.345484

Reflection: Each convergence took less time than the previous, though all
    relatively similar with a range of just 8 microseconds. The slowest to
    converge was the first, with an initial point of x = -2. It seems that a
    choice of an initial point that intersects with the function at such a
    steep slope will give a subsequent tangent that intersects the x-axis very
    close to the initial choice. As the slope of our function shallows closer
    to the root as it approaches the local minimum, the tangent lines hasten
    toward the root along the x-axis.
*/