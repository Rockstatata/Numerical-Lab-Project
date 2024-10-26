# Numerical Methods Console Application

## Objective

The project is a console application created for the assignment of numerical methods. It involves the implementation of various algorithms to solve linear equations, non-linear equations, differential equations, and matrix inversion. The project aims at fostering collaborative development skills, consolidating the understanding of algorithmic principles, and ensuring effective project presentation.

## Features

The following are the numerical methods the application will cover:

### 1. Solutions to Linear Equations

#### a. Jacobi Iterative Method

- **Description**: The Jacobi method is an iterative algorithm for a system of linear equations. The method splits the matrix into the diagonal part and the rest and updates each variable using values computed in a previous iteration. This is especially effective in the case of diagonally dominant matrices.
- **Theoretical Background**: The Jacobi method converges according to the properties of the coefficient matrix. It is suitable for large systems for which direct methods may be prohibitively expensive.
- **File**: `jacobi.cpp`

#### b. Gauss-Seidel Iterative Method

- **Description**: The Gauss-Seidel method is an improvement with respect to the Jacobi method. It uses the most up-to-date values to compute the next approximation, hence it provides faster convergence.
- **Theoretical Background**: Like the Jacobi method, whether it converges or not depends on the characteristics of the matrix. Overall, Gauss-Seidel converges faster than Jacobi for well-conditioned systems.
- **File**: `gauss_seidel.cpp`

#### c. Gauss Elimination

- **Description**: This method transforms a system of linear equations to upper triangular form via a series of row transformations. A solution can then be propagated by back substitution.
- **Theoretical Background**: Gauss elimination is a direct method and it has a computational complexity that is usully \(O(n^3)\), where \(n\) is the number of equations.
- **File**: `Gauss_elimination.cpp`

#### d. Gauss-Jordan Elimination

- **Description**: This method simply extends Gauss elimination by transforming the matrix into RREF, allowing the solutions to be read directly without the need for back substitution.
- **Theoretical Background**: It is highly useful in finding inverse matrix and while solving systems which have infinite solutions.
- **File**: `gauss_jordan.cpp`

#### e. LU Factorization

Description: The program does the LU Factorization of the coefficient matrix into a product of a lower triangular matrix L and an upper triangular matrix U. It will solve the system of linear equations efficiently by solving first Ly = b and then Ux = y.
Theoretical Background The main advantage of LU Factorization is in solving multiple systems which have the same coefficient matrix but different constant terms.
File : `LUFactorization.cpp`

### 2. Solutions of Non-linear Equations

a. Bisection Method

- **Description**: A root-finding method that repeatedly bisects an interval and selects a subinterval where the root exists, ensuring that it remains bracketed within the interval.
- **Theoretical Background**: The Bisection method is robust and guarantees convergence if the initial interval contains a root. However, it can be slow compared to other methods.
- **File**: `bisection.cpp`

#### b. False Position Method (Regula Falsi)

- **Description**: Similar as the bisection method and also to linear interpolation. By function values at the ends, one obtains an estimate about the position of the root.
- **Theoretical Background**: False position generally converges faster than bisection but may stagnate in case of a poorly approximated root.
- **File**: `false_position.cpp`

#### c. Secant Method

- **Description**: This iterative scheme approximates the root based on two initial estimates and the secant line between them. The point where this line intersects the xaxis gives the next estimate.
  Theoretical Background: The Secant method is generally more rapid than either the bisection or the false position method but involves two initial estimates and may diverge for a poor selection of initial estimates.
  File: `Secantt.cpp`

#### d. Newton-Raphson Method

- **Description**: This is a powerful technique using a function's derivative to enhance its root approximation. It offers very good convergence when the initial estimate is around the neighborhood of the root.
- **Theoretical Background**: The Newton-Raphson method is quadratic convergent under appropriate conditions, but it demands that the derivative must not vanish at the root.
- **File:** `newton_raphsonn.cpp`

### 3. Solution of Differential Equations

#### a. Runge-Kutta Method

- **Description**: This is a family of iterative methods for solving ordinary differential equations (ODEs). The fourth order Runge-Kutta method is very popular because it offers an excellent trade-off between accuracy and computational cost.
- **Teorhetical Background**: While there are many numerical methods for solving first-order ODEs, the Runge-Kutta method provides a good estimate of the solution at widely dispersed points and hence it works with a much larger step-size than would be practical for the simpler methods such as Euler's method.
- **File**: `rk.cpp`

### 4. Matrix Operations

#### a. Matrix Inversion

Description: The program provides functions for the inversion of matrices using Gaussian elimination or the adjoint method, among others.
Theoretical Background Matrix inversion is one of the principal manners of solving systems of linear equations, which plays a great role in engineering and physical applications.
File: `matrix_inversion.cpp`

## Application Structure

The application is structured as different C++ files for each method, so that it becomes modular and easier to maintain. The main application file constitutes a menu-driven interface so as to walk the user through the process of choosing their preferred numerical method.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/Rockstatata/Numerical-Lab-Project.git
```

2. Change into project directory:

```bash
cd Numerical-Lab-Project
```

3. The application should be compiled with a C++ compiler:

```bash
g++ main.cpp -o NumericalMethods
```

4. Run the application:

```bash
./NumericalMethods
```

## Usage

1. Run the console application.
2. Follow the screen instructions, and select any of the numerical methods. For instance, linear equations will prompt for coefficients, while root-finding methods will prompt for initial guesses.
3. Observe the output generated in the console.

## Technologies Used

- **Programming Language**: C++
- **Libraries**: [Include specific libraries if applied, such as Standard Template Library (STL)]

## Contributing

Contributions that make the application more robust and feature-rich are welcome. Please follow these steps:

1. Fork the repository.
  
2. Create a feature branch:
  
  ```bash
  git checkout -b feature/YourFeature
  ```
  
3. Commit your changes:
  
  ```bash
  git commit -m 'Add YourFeature'
  ```
  
4. Push to the branch:
  
  ```bash
  git push origin feature/YourFeature
  ```
  
5. Open a pull request for review.
