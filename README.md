## Linear Systems Calculator
A collection of algorithms that are used for solving systems of linear equations

### 1. **Gaussian Elimination**
   - Transforms a matrix into row echelon form (or reduced row echelon form) by applying a sequence of row operations, making it easier to solve for unknowns using backward substitution.
   - **Steps**:
     - Forward elimination: Reduce the system to upper triangular form.
     - Backward substitution: Solve the system from the last equation upwards.
   - **Application**: Solving linear systems, finding the inverse of a matrix, and determining matrix rank.

### 2. **Thomas Algorithm / Tridiagonal Matrix Algorithm (TDMA)**
   - A simplified version of Gaussian elimination, for tridiagonal systems of linear equations--having non-zero elements only on the main diagonal and the diagonals directly above and below it.
   - **Steps**:
     - Forward elimination: Similar to Gaussian elimination but with fewer operations due to the tridiagonal nature.
     - Backward substitution: Solve the system as in Gaussian elimination.
   - **Application**: Efficiently solving linear systems arising in finite difference methods, heat conduction problems, or fluid dynamics.

### 3. **Bisection Method**
   - Repeatedly divides an interval in half and selects the subinterval in which the root must lie, based on the Intermediate Value Theorem.
   - **Steps**:
     - Choose two points $a$ and $b$ such that $f(a)f(b) < 0$, meaning the root lies between them.
     - Calculate the midpoint $c =$ $\frac{(a+b)}{2}$, and evaluate $f(c)$.
     - Narrow the interval to $[a, c]$ or $[c, b]$ depending on the sign of $f(c)$, and repeat until the root is approximated.
   - **Application**: Finding roots of nonlinear equations, particularly when the function is continuous and the root is known to lie in a specific interval.

### 4. **Gaussian Quadrature**
   - Approximates the definite integral of a function by evaluating the function at specific points (Gauss points) and then weighting the function values.
   - **Steps**:
     - Select appropriate points and weights based on the order of the polynomial.
     - Evaluate the function at these points and sum the weighted function values to get the integral approximation.
   - **Application**: Numerical integration, especially when high accuracy is needed and the function to be integrated is smooth.

### 5. **Gauss-Seidel Method**
   - Unlike Gaussian elimination, Gauss-Seidel doesn’t directly reduce the system but iteratively improves an initial guess until convergence.
   - **Steps**:
     - Start with an initial guess for the solution vector.
     - Update each variable in the system using values from the previous iteration.
     - Repeat until the difference between successive approximations is below a given tolerance.
   - **Application**: Solving large, sparse linear systems often encountered in finite element analysis and computational fluid dynamics (CFD).

### 6. **Newton-Raphson Method**
   - Uses the first derivative of real-valued functions to iteratively improve the estimate of a root.
   - **Steps**:
     - Start with an initial guess $x_0$.
     - Use the formula $x_{n+1} = x_n -$ $\frac{f(x_n)}{f'(x_n)}$ to update the estimate.
     - Repeat until the difference between successive approximations is sufficiently small.
   - **Application**: Finding roots of nonlinear equations, especially when high precision is needed.

### 7. **Secant Method**
   - Similar to the Newton-Raphson method but doesn't require the computation of the derivative. Instead, it approximates the derivative using two initial points.
   - **Steps**:
     - Start with two initial guesses, $x_0$ and $x_1$.
     - Use the formula $x_{n+1} = x_n -$ $\frac{f(x_n)(x_n - x_{n-1})}{f(x_n) - f(x_{n-1})}$ to update the estimate.
     - Repeat until the successive approximations converge to the root.
   - **Application**: Finding roots of nonlinear equations when the derivative is difficult or expensive to compute. It converges faster than the bisection method but may be less stable.

### 8. **LU Decomposition**
   - Decomposes a matrix $A$ into the product of a lower triangular matrix $L$ and an upper triangular matrix $U$.
   - **Steps**:
     - Factor the matrix $A = LU$.
     - Solve the system by first solving $Ly = b$ (forward substitution) and then $Ux = y$ (backward substitution).
   - **Application**: Efficiently solving multiple linear systems with the same coefficient matrix, useful in numerical simulations and PDEs.

### 9. **Fixed-Point Iteration**
   - Rewrites an equation $f(x) = 0$ in the form $x = g(x)$, and then iterates the equation $x_{n+1} = g(x_n)$ until convergence.
   - **Steps**:
     - Start with an initial guess $x_0$.
     - Compute successive approximations using $x_{n+1} = g(x_n)$.
     - Repeat until the difference between successive approximations is below a specified tolerance.
   - **Application**: Used for solving nonlinear equations, but requires the function $g(x)$ to be chosen such that the iterations converge.

### 10. **Polynomial Interpolation**
   - Estimates unknown values between known data points by fitting a polynomial through the known points. The polynomial is constructed such that it passes through all the given data points exactly.
   - **Types**:
     - **Lagrange Interpolation**: Constructs a polynomial by taking weighted sums of the basis polynomials.
     - **Newton’s Divided Difference Interpolation**: Uses divided differences to construct the polynomial incrementally, which is more efficient than Lagrange interpolation for large data sets.
   - **Application**: Used for fitting smooth curves to data points, numerical integration, and solving ordinary differential equations. However, high-degree polynomial interpolation can suffer from Runge’s phenomenon, where oscillations occur near the endpoints.

### Summary Table:

| Algorithm                | Application                                         | Type of Problem Addressed                  |
|--------------------------|-----------------------------------------------------|--------------------------------------------|
| **Gaussian Elimination**  | Solving systems of linear equations                 | Direct method, linear equations            |
| **Thomas Algorithm**      | Solving tridiagonal systems                         | Optimized for tridiagonal linear systems   |
| **Bisection Method**      | Finding roots of continuous functions               | Root-finding, iterative method             |
| **Gaussian Quadrature**   | Numerical integration                              | Approximation of definite integrals        |
| **Gauss-Seidel Method**   | Iterative solution of linear systems                | Iterative, linear equations                |
| **Newton-Raphson Method** | Finding roots using function derivatives            | Fast root-finding, iterative method        |
| **Secant Method**         | Finding roots without needing derivatives           | Iterative, root-finding                    |
| **LU Decomposition**      | Matrix factorization for linear systems             | Efficient for solving multiple systems     |
| **Fixed-Point Iteration** | Root-finding for nonlinear equations                | Iterative method                           |
| **Polynomial Interpolation** | Curve fitting, function approximation            | Interpolation, curve fitting               |


## Classic (Fourth-Order) Runge-Kutta Method (RK4):

The **fourth-order Runge-Kutta method (RK4)** approximates the solution of an ODE by averaging several slopes (evaluations of the derivative function $f(x, y)$ at different points within each step. The method is an improvement over simpler methods like Euler’s method.

- **Ordinary Differential Equations (ODEs)**: An ODE involves a function and its derivatives, and the goal is to find the function that satisfies the equation given some initial conditions. For example, $\frac{dy}{dx} = f(x, y)$ is a simple ODE where $y$ is the unknown function of $x$.
- **Initial Value Problem (IVP)**: Runge-Kutta methods are especially useful for solving IVPs, where the value of the solution is known at a specific point (the initial condition), and the goal is to compute the solution at subsequent points.
For solving $\frac{dy}{dx}$ $= f(x, y)$:

1. **Step Size**: Choose a step size $h$ (the interval between points where the solution is calculated).
   
2. **Intermediate Slopes**:
   - $k_1 = f(x_n, y_n)$ (slope at the beginning of the interval)
   - $k_2 = f(x_n + \frac{h}{2}, y_n + \frac{h}{2}k_1)$ (slope at the midpoint using $k_1$)
   - $k_3 = f(x_n + \frac{h}{2}, y_n + \frac{h}{2}k_2)$ (another midpoint slope using $k_2$)
   - $k_4 = f(x_n + h, y_n + hk_3)$ (slope at the end of the interval using $k_3$)

3. **Update Formula**: Use a weighted average of these slopes to compute the next value of $y$:
   
$$
  y_{n+1} = y_n + \frac{h}{6}(k_1 + 2k_2 + 2k_3 + k_4)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This formula gives a highly accurate estimate of $y_{n+1}$ without requiring a tiny step size.

- **Benefits**: The RK4 method is highly accurate and often a good choice when moderate accuracy is required without excessive computational cost. It has a **local truncation error** of order $O(h^5)$ and a **global error** of order $O(h^4)$, meaning it’s much more accurate than lower-order methods like Euler's method. It’s relatively stable for a wide range of problems, including stiff ODEs when used with a suitable step size.

### Generalization: Runge-Kutta Methods of Higher and Lower Order:
While RK4 is the most common, the Runge-Kutta family includes methods of various orders:

1. **RK1 (Euler’s Method)**: A simple first-order method, also known as **Euler's method**, where only one evaluation of the derivative is used to estimate the next point. This method has low accuracy.

$$
  y_{n+1} = y_n + h f(x_n, y_n)
$$

3. **RK2**: Also called the **midpoint method** or **Heun’s method**, this is a second-order method, which improves Euler’s method by using an average of two slopes:

$$
  y_{n+1} = y_n + \frac{h}{2}(k_1 + k_2)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;where $k_1$ is the slope at the beginning and $k_2$ is at the midpoint.

4. **Higher-Order Runge-Kutta**: There are fifth and even higher-order Runge-Kutta methods, which are even more accurate but also more computationally expensive.

### Adaptive Runge-Kutta Methods:
There are versions of Runge-Kutta methods, such as **Runge-Kutta-Fehlberg (RKF45)**, that adaptively adjust the step size $h$ to control the error and optimize the number of function evaluations. These are widely used in practice because they combine the efficiency of the RK method with automatic error control.

- **Runge-Kutta-Fehlberg Method (RKF45)**: It combines a fourth-order and fifth-order method to estimate the error at each step, adjusting the step size dynamically to maintain accuracy without wasting computational effort.


## Adams-Bashforth Formula:
The Adams-Bashforth method approximates the solution to an ODE of the form $\frac{dy}{dx}$ $= f(x, y)$ over a time interval by using an explicit formula based on previously computed values of $f(x, y)$.
- **Explicit Methods**: The Adams-Bashforth method is explicit, meaning that the next value of the solution can be computed directly from previous values, without the need to solve any equations implicitly (in contrast to implicit methods like Adams-Moulton).
- **Multistep Methods**: Multistep methods rely on values from multiple previous time steps, as opposed to single-step methods (like Runge-Kutta) that only use the information from the current step.
The general form of the Adams-Bashforth method is:

$$
y_{n+1} = y_n + h \sum_{i=0}^{k-1} b_i f(x_{n-i}, y_{n-i})
$$

where:
- $h$ is the step size.
- $f(x_n, y_n)$ is the function defining the ODE.
- $b_i$ are specific coefficients that depend on the number of steps $k$.

### Specific Versions of the Adams-Bashforth Method:

There are different orders of Adams-Bashforth methods, with each higher-order method using more previous points to achieve greater accuracy. The most common versions are:

1. **First-Order Adams-Bashforth (AB1)**: This is equivalent to **Euler’s method**.

$$
   y_{n+1} = y_n + h f(x_n, y_n)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It’s simple but has low accuracy.

2. **Second-Order Adams-Bashforth (AB2)**: This method uses two previous points.

$$
   y_{n+1} = y_n + h \left( \frac{3}{2} f(x_n, y_n) - \frac{1}{2} f(x_{n-1}, y_{n-1}) \right)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It improves on Euler’s method by including information from the previous step, resulting in better accuracy.

3. **Third-Order Adams-Bashforth (AB3)**: This method uses three previous points.

$$
   y_{n+1} = y_n + h \left( \frac{23}{12} f(x_n, y_n) - \frac{16}{12} f(x_{n-1}, y_{n-1}) + \frac{5}{12} f(x_{n-2}, y_{n-2}) \right)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It continues to improve accuracy but requires more previously computed points.

4. **Fourth-Order Adams-Bashforth (AB4)**: This uses four previous points.

$$
   y_{n+1} = y_n + h \left( \frac{55}{24} f(x_n, y_n) - \frac{59}{24} f(x_{n-1}, y_{n-1}) + \frac{37}{24} f(x_{n-2}, y_{n-2}) - \frac{9}{24} f(x_{n-3}, y_{n-3}) \right)
$$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It provides even more accuracy, but more function evaluations are required.

### Key Characteristics:

- **Order of Accuracy**: The Adams-Bashforth method is available in different orders, with the order indicating the method’s accuracy. The \(k\)-step Adams-Bashforth method is \(k\)-th order accurate.
  
- **Explicit Nature**: Since Adams-Bashforth methods are explicit, they are easy to implement and do not require solving a system of equations at each step (unlike implicit methods). However, they can suffer from stability issues, particularly for stiff equations.

- **Predictor-Corrector Methods**: In practice, Adams-Bashforth methods are often paired with **Adams-Moulton** methods (which are implicit) to form **predictor-corrector methods**. The Adams-Bashforth method predicts the solution, and the Adams-Moulton method refines the prediction by solving the implicit equation. This combination improves accuracy and stability.

### Starting the Adams-Bashforth Method:
Since the method requires multiple previous points (depending on the order), a separate method (usually **Runge-Kutta**) is used to compute the first few values. For example, to start a third-order Adams-Bashforth method, you need at least two previous values, which can be obtained using a method like Runge-Kutta for the initial steps.

### Stability of Adams-Bashforth Methods:
One downside of the Adams-Bashforth method is that it is not as stable as some other methods, such as **implicit methods**. For stiff problems (where the solution changes very rapidly), Adams-Bashforth can become unstable unless the step size is very small. To address this, Adams-Bashforth methods are often used in combination with implicit methods (like Adams-Moulton) or are applied only to problems that are not stiff.

#### Advantages:
- **Efficient**: Being explicit, the Adams-Bashforth method does not require solving nonlinear systems at each step, making it computationally efficient.
- **Higher Accuracy**: By using more points, higher-order methods provide more accurate solutions than simpler methods like Euler’s method or even lower-order Runge-Kutta methods.
- **Multistep Method**: By leveraging previously computed points, the method can reduce the number of function evaluations compared to single-step methods like Runge-Kutta.

#### Disadvantages:
- **Stability Issues**: It is less stable than implicit methods, particularly for stiff equations.
- **Requires Initial Values**: Since it’s a multistep method, a separate method is needed to generate the starting values.
  
