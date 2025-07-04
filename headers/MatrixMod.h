// Filename: headers/MatrixMod.h
//
// Purpose:
// Provides a matrix structure specifically optimized for competitive programming problems
// involving modular arithmetic. All operations (+, *, ^) are automatically performed
// under a static modulus, which must be set by the user. This design prioritizes
// ease of use and speed in a contest setting over generic applicability.
//
// Design Principles:
// - Specialized for `long long` with modular arithmetic.
// - All operations automatically handle the modulo.
// - A single static `MOD` member simplifies usage across the entire program.
// - Self-contained: No dependencies on other custom headers.

#ifndef ALGO_MATRIX_MOD_H
#define ALGO_MATRIX_MOD_H

#include <vector>
#include <iostream>
#include <cassert>

struct Matrix {
    // The modulus for all matrix operations.
    // This static member MUST be defined and set in the user's main .cpp file.
    // Example: `long long Matrix::MOD = 1e9 + 7;`
    static long long MOD;

    std::vector<std::vector<long long>> e;//elements of matrixs
    int R, C;

    // Constructor: Creates a matrix of size r x c, initialized with zeros.
    // Complexity: O(r * c)
    Matrix(int r = 0, int c = 0) : R(r), C(c), e(r, std::vector<long long>(c, 0)) {}

    // Provides a clean way to resize or reset the matrix.
    // Complexity: O(r * c)
    void resize(int r, int c) {
        R = r;
        C = c;
        e.assign(r, std::vector<long long>(c, 0));
    }

    // Static factory method to create an identity matrix of size n x n.
    // An identity matrix is a square matrix with 1s on the main diagonal and 0s elsewhere.
    // Complexity: O(n^2)
    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) 
            res.e[i][i] = 1;
        return res;
    }

    // Overloads the '+' operator for matrix addition.
    // Matrices must have the same dimensions.
    // Complexity: O(R * C)
    Matrix operator+(const Matrix& ot) const {//You know it's other, right?
        assert(R == ot.R && C == ot.C);
        Matrix res(R, C);
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                res.e[i][j] = (e[i][j] + ot.e[i][j]) % MOD;
        return res;
    }

    // Overloads the '*' operator for matrix multiplication.
    // The number of columns in the first matrix must equal the number of R in the second.
    // Complexity: O(R * ot.C * this->C)
    Matrix operator*(const Matrix& ot) const {
        assert(C == ot.R);
        Matrix res(R, ot.C);
        for (int i = 0; i < R; ++i) 
            for (int j = 0; j < ot.C; ++j) 
                for (int k = 0; k < C; ++k) 
                    // Note: For typical contest MODs (like 1e9+7), `long long` is sufficient
                    // to prevent overflow in `e[i][k] * ot.e[k][j]`.
                    res.e[i][j] = (res.e[i][j] + e[i][k] * ot.e[k][j]) % MOD;
        return res;
    }

    // Performs matrix exponentiation (also known as matrix power).
    // The matrix must be square.
    // Complexity: O(R^3 * log(k))
    Matrix power(long long k) const {
        assert(R == C);
        Matrix res = Matrix::identity(R),b = *this;//means base
        for(; k > 0; b = b * b, k >>= 1)
            if (k & 1) res = res * b;
        return res;
    }

    // Helper function to print the matrix to standard output. Useful for debugging.
    // Complexity: O(R * C)
    // Using std::endl, because it's just a debugger.
    void print() const {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                std::cout << e[i][j] << (j == C - 1 ? "" : " ");
            }
            std::cout << std::endl;//I mean, you won't really print it in a contest, right?
        }
    }
};

// The definition (assignment of a value) must happen in a .cpp file.
// long long Matrix::MOD = sth you like;

#endif // ALGO_MATRIX_MOD_H