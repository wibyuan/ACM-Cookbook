// Filename: DSU.h

#ifndef ALGO_DSU_H
#define ALGO_DSU_H

#include <vector>
#include <numeric> // For std::iota

struct DSU {
    std::vector<int> pa; // You know this is parent, right? Just for you to type.
    std::vector<int> sz; // Use sz to store the size of each set.

    // Constructor: initializes n sets, each with one element [0, n-1].
    // Complexity: O(n)
    DSU(int n = 0) : pa(n), sz(n, 1) {
        // std::iota fills the parent vector with 0, 1, 2, ...
        // which means each element is its own parent initially.
        std::iota(pa.begin(), pa.end(), 0);
    }

    // Finds the representative (root) of the set containing element i, with path compression.
    // Complexity: Amortized O(alpha(n)), where alpha is the inverse Ackermann function, which is nearly constant.
    int find(int i) {
    	// This type faster
        return pa[i] == i ? i : pa[i] =  find(pa[i]);
    }

    // Unites the sets containing elements i and j, using union by size.
    // Returns true if they were in different sets and are now united, false otherwise.
    // Complexity: Amortized O(alpha(n))
    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        // Give up clearness to add your typing efficiency
        if (i != j) {
            // Union by size: attach the smaller tree to the root of the larger tree.
            if (sz[i] < sz[j]) std::swap(i,j);
            pa[j] = i;
            sz[i] += sz[j];
            return true;
        }
        return false;
    }

    // Checks if elements i and j are in the same set.
    // Complexity: Amortized O(alpha(n))
    bool same(int i, int j) {
        return find(i) == find(j);
    }

    // Returns the size of the set containing element i.
    // Complexity: Amortized O(alpha(n))
    int size(int i) {
        return sz[find(i)];
    }
    
    // Resets the DSU to a new size, useful for multiple test cases.
    // Complexity: O(n1)
    void reset(int n1 = 0) {
        pa.assign(n1, 0);
        sz.assign(n1, 1);
        std::iota(pa.begin(), pa.end(), 0);
    }
};

#endif // ALGO_DSU_H