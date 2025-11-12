#include <iostream>
#include <cstdio>
#include <cmath>

//I'm going to assume the question does not want us to use any libraries to prevent 
//the question being to straighforward
//My approach will use the Newton's Method and I will use the inbuilt square root function in 
//<cmath> to check the accuracy of the algorithm
//Reference: https://math.mit.edu/~stevenj/18.335/newton-sqrt.pdf

//Newton’s Method for Square Roots
//Iteratively refines an estimate of the square root of the input using:
// x_{k+1} = 0.5 * (x_k + n / x_k)
// Converges quadratically O(log p) to p digits of precision.
//Each iteration costs O(1), so total computational cost is O(log p).


// Custom absolute function for doubles.
// My first model used built-in abs() which only supports integers and would truncate
// floating-point values, breaking the convergence check in Newton’s method leading to poorer accuracy.
// This version correctly handles double precision and produces a far more accurate final answer.


double absolute(double x) {
    return (x < 0) ? -x : x;
}

double squareRoot(double n, float tol, int maxIter = 1000000){
    // This is added for if any other value than 42 was inputted
    if (n < 0) {
        std::cout << "Cannot compute the real square root of a negative number\n";
        return -1;
    }
    if (n == 0) return 0;

    //Initial guess we can say is half of n, is not hugely important but the 
    //assumption that is half will cut iteration number 

    double x = n / 2.0;

    double x_next;

    //Newton's Method and an iteration limit
    for (int i = 0; i < maxIter; i++){
        x_next = 0.5 * (x + (n/x));
        if (absolute(x_next - x) < tol)
            return x_next;
        x = x_next;
    }
    return x;
}

int main(){
    double n = 42;
    float tol = 1e-10;

    // Using printf here so that the final square root value goes to a larger significant value 
    printf("Approximate sqrt(%.1f) = %.12f\n", n ,squareRoot(n, tol));
    // Checking the algorithm agaisnt an inbuilt library
    printf("Accuracy of Algorithm when compared to C++ library: %.12f\n", squareRoot(n, tol) - std::sqrt(n));
    return 0;
}

// Final Comments:
// I believe I have successfully implemented an algorithm to find the square root of a given number
// Increasing both maxIter and tol will bring the outputted value closer to the true value 
// At the values of maxIter and tol the difference between this algorithm and using cmath is negligible 
