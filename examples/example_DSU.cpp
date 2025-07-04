// Filename: examples/example_dsu.cpp
//
// Purpose:
// This file provides a clear and simple demonstration of the DSU (Disjoint Set Union)
// template's functionalities. It covers initialization, uniting sets, checking for
// connectivity, querying set sizes, and resetting the structure for multiple test cases.
//
// How to compile and run:
// g++ example_dsu.cpp -o run_dsu_example
// ./run_dsu_example

#include <iostream>

// ====================================================================================
// In a real contest, you would copy the entire content of 'DSU.h' and paste it here.
// For this local example, we include it directly to keep the file structure clean.
// The path "../headers/" assumes this file is in the "examples" directory and DSU.h
// is in the "headers" directory, as per our project structure.
#include "../headers/DSU.h"
// ====================================================================================

void print_separator() {
    std::cout << "\n----------------------------------------\n\n";
}

int main() {
    std::cout << "===== DSU (Disjoint Set Union) Template Demonstration =====\n";
    print_separator();

    // === Step 1: Initialization ===
    std::cout << "Step 1: Initializing a DSU with 10 elements (indexed 0 to 9).\n";
    int n = 10;
    DSU dsu(n);
    std::cout << "DSU created.\n";

    // Let's verify the initial state.
    // Every element should be in its own set of size 1.
    std::cout << " - Is element 3 in the same set as element 5? "
              << (dsu.same(3, 5) ? "Yes" : "No") << " (Expected: No)\n";
    std::cout << " - What is the size of the set containing element 7? "
              << dsu.size(7) << " (Expected: 1)\n";

    print_separator();

    // === Step 2: Uniting Sets ===
    std::cout << "Step 2: Performing several 'unite' operations.\n";
    
    // We will create three distinct groups:
    // Group A: {0, 1, 4, 8}
    // Group B: {2, 3, 9}
    // Group C: {5, 6}
    // Element 7 remains alone.

    std::cout << " - Uniting 0 and 1...\n";
    dsu.unite(0, 1);
    std::cout << " - Uniting 1 and 4...\n";
    dsu.unite(1, 4);
    std::cout << " - Uniting 0 and 8...\n";
    dsu.unite(0, 8);

    std::cout << " - Uniting 2 and 3...\n";
    dsu.unite(2, 3);
    std::cout << " - Uniting 3 and 9...\n";
    dsu.unite(3, 9);

    std::cout << " - Uniting 5 and 6...\n";
    dsu.unite(5, 6);

    print_separator();

    // === Step 3: Checking Connectivity and Sizes ===
    std::cout << "Step 3: Verifying the results of the unions.\n";

    // Check connectivity within groups (should all be true)
    std::cout << "Connectivity within Group A:\n";
    std::cout << " - Is 1 same as 8? " << (dsu.same(1, 8) ? "Yes" : "No") << " (Expected: Yes)\n";
    std::cout << " - Is 4 same as 0? " << (dsu.same(4, 0) ? "Yes" : "No") << " (Expected: Yes)\n";

    // Check connectivity between groups (should all be false)
    std::cout << "\nConnectivity between different groups:\n";
    std::cout << " - Is 1 (Group A) same as 9 (Group B)? " << (dsu.same(1, 9) ? "Yes" : "No") << " (Expected: No)\n";
    std::cout << " - Is 3 (Group B) same as 6 (Group C)? " << (dsu.same(3, 6) ? "Yes" : "No") << " (Expected: No)\n";

    // Check set sizes
    std::cout << "\nSet sizes:\n";
    std::cout << " - Size of set containing 4 (Group A): " << dsu.size(4) << " (Expected: 4)\n";
    std::cout << " - Size of set containing 9 (Group B): " << dsu.size(9) << " (Expected: 3)\n";
    std::cout << " - Size of set containing 5 (Group C): " << dsu.size(5) << " (Expected: 2)\n";
    std::cout << " - Size of set containing 7 (alone): " << dsu.size(7) << " (Expected: 1)\n";
    
    print_separator();

    // === Step 4: Edge Cases and Return Value of 'unite' ===
    std::cout << "Step 4: Testing edge cases.\n";

    std::cout << " - Attempting to unite 8 and 4, which are already in the same set...\n";
    bool result = dsu.unite(8, 4);
    std::cout << " - dsu.unite(8, 4) returned: " << (result ? "true" : "false") << " (Expected: false, as no new union occurred)\n";
    std::cout << " - Size of set containing 8 is still: " << dsu.size(8) << " (Expected: 4)\n";

    print_separator();

    // === Step 5: Using the 'reset' Functionality ===
    std::cout << "Step 5: Demonstrating the 'reset' function for multiple test cases.\n";
    
    int new_size = 5;
    dsu.reset(new_size);
    std::cout << " - DSU has been reset to handle " << new_size << " new elements (0 to 4).\n";

    // Verify the reset state
    std::cout << " - Is element 1 same as 2 now? " << (dsu.same(1, 2) ? "Yes" : "No") << " (Expected: No)\n";
    std::cout << " - Size of set containing 4 is now: " << dsu.size(4) << " (Expected: 1)\n";
    
    std::cout << "\n===== Demonstration Complete =====\n";

    return 0;
}