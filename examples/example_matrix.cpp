// Filename: examples/example_matrix.cpp
// This file demonstrates the basic usage of the MatrixMod template.
// To compile: g++ example_matrix.cpp -o run_example_matrix
// To run: ./run_example_matrix

#include <iostream>

// In a real contest, you would copy the content of MatrixMod.h here.
#include "../headers/MatrixMod.h"

// The ONLY setup required: define the static MOD variable for the Matrix struct.
// This must be done in the global scope of a .cpp file.
long long Matrix::MOD = 1e9 + 7;

int main() {
    std::cout << "--- Matrix (Modulo Arithmetic) Example ---" << std::endl;
    std::cout << "Using MOD = " << Matrix::MOD << std::endl << std::endl;

    // 1. Initialize matrices.
    Matrix A(2, 2), B(2, 2);
    // A = |1 2|
    //     |3 4|
    A.e[0][0] = 1; A.e[0][1] = 2;
    A.e[1][0] = 3; A.e[1][1] = 4;
    
    // B = |5 6|
    //     |7 8|
    B.e[0][0] = 5; B.e[0][1] = 6;
    B.e[1][0] = 7; B.e[1][1] = 8;
    
    std::cout << "Matrix A:" << std::endl; A.print();
    std::cout << "Matrix B:" << std::endl; B.print();
    std::cout << std::endl;

    // 2. Test matrix addition.
    std::cout << "--- Matrix Addition (A + B) ---" << std::endl;
    Matrix C = A + B;
    C.print(); // Should be |6 8|, |10 12|
    std::cout << std::endl;

    // 3. Test matrix multiplication.
    std::cout << "--- Matrix Multiplication (A * B) ---" << std::endl;
    Matrix D = A * B;
    D.print(); // Should be |19 22|, |43 50|
    std::cout << std::endl;

    // 4. Test identity matrix and matrix exponentiation (power).
    // Application: Calculating Fibonacci numbers.
    // Transition matrix T = |1 1|
    //                     |1 0|
    std::cout << "--- Matrix Power (Fibonacci example) ---" << std::endl;
    Matrix T(2, 2);
    T.e[0][0] = 1; T.e[0][1] = 1;
    T.e[1][0] = 1; T.e[1][1] = 0;

    long long n = 10;
    std::cout << "Calculating F(10) using T.power(" << n - 1 << ")..." << std::endl;
    
    // We want F(10). Formula is |F(n) F(n-1)| = |F(2) F(1)| * T^(n-2)
    // Here we use |F(n+1) F(n)| = T^n * |F(1) F(0)|. Let F(0)=0, F(1)=1.
    // We calculate T^9. The result F(10) will be in the top-left entry of T^9 * |F(2) F(1)|
    // A simpler way: F(10) is in the top-left of T^9.
    
    Matrix T_pow = T.power(n-1);
    std::cout << "T^" << n - 1 << " is:" << std::endl;
    T_pow.print();
    std::cout << "F(" << n << ") = " << T_pow.e[0][0] << std::endl; // F(10) should be 55
    std::cout << std::endl;

    // Test with a large power and check modulo.
    n = 1000000000;
    std::cout << "Calculating F(" << n << ") mod " << Matrix::MOD << "..." << std::endl;
    T_pow = T.power(n - 1);
    std::cout << "F(" << n << ") mod " << Matrix::MOD << " is: " << T_pow.e[0][0] << std::endl;

    return 0;
}