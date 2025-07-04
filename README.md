# ACM-Cookbook: A Practical OOP Template Library for Competitive Programming

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

> "In the battlefield of competitive programming, the best weapon is not the most complex, but the most reliable."

## 🤔 What is this?

This is a collection of C++ templates designed for algorithm competitions like ACM/ICPC and CCPC. It's born from a simple observation: many available templates, even from top competitors, often prioritize theoretical elegance over practical usability in a high-pressure contest environment. They are not always "plug-and-play."

This project aims to bridge that gap. It's a "cookbook" for the competitive programmer, offering recipes (templates) that are ready to use, easy to understand, and battle-tested.

## 📜 Design Philosophy

Every line of code in this repository follows a strict set of principles, tailored for the unique demands of competitive programming:

*   **100% Practical C++:** We use `struct` instead of `class` for our objects. This sacrifices strict encapsulation (inheritance, polymorphism) for ultimate simplicity, direct member access, and easier on-the-fly modifications during a contest.
*   **"Copy-Paste" Deployment:** The library is organized into header files for clarity and maintenance. However, the intended use is **not** `#include`. It's designed for you to copy the entire content of a header file and paste it directly into your solution file. This creates a single, self-contained, dependency-free file for submission, maximizing reliability.
*   **Human-Readable Naming:** We sacrifice some typing speed for clarity. Function and variable names are descriptive English words (e.g., `unite` instead of `U`, `power` instead of `pw`), making the code's purpose immediately obvious.
*   **Embedded Documentation:** Each function is preceded by a comment block detailing its purpose and time complexity in English. This prevents encoding issues and serves as a quick, reliable reference.
*   **Learning from the Best:** The implementations are heavily inspired by, and benchmarked against, templates from proven sources like Topcoder veterans and the OI-wiki community, ensuring both efficiency and elegance.


## 🚀 How to Use: The "One-Copy" Method

This library is designed for maximum simplicity. Each template is a self-contained unit.

**Step 1: Find Your Template**

Navigate to the `headers/` directory and find the single file you need, for example, `MatrixMod.h`.

**Step 2: Copy and Paste (Just Once!)**

Open that one file, select all its content (`Ctrl+A`), copy it (`Ctrl+C`), and paste it at the top of your contest source file.

**That's it. You are done.** You never need to worry about missing a dependency.

**Example:**

```cpp
// Your main solution file: main.cpp
#include <iostream>

// --- Start of pasted code from DSU.h ---
#include <vector>
#include <numeric>
struct DSU {
    // ... all the code from DSU.h ...
};
// --- End of pasted code ---

void solve() {
    // Now, the DSU struct is ready to use.
    DSU dsu(10);
    // ... your logic ...
}

int main() {
    // ...
}
```

This "One-Copy" guarantee is the core promise of this library, ensuring you spend your precious contest time on algorithms, not on managing code dependencies.


## 📚 Available Templates

Below is a list of available templates. Each template has a minimal working example and real-world problem solutions to demonstrate its usage.

| Template Header      | Description                                                  | Minimal Example                                       | Real-World Application                            |
| :------------------- | :----------------------------------------------------------- | :---------------------------------------------------- | :------------------------------------------------ |
| **Foundation**       |                                                              |                                                       |                                                   |
| `DSU.h`              | Disjoint Set Union with path compression and union by size.  | [`example_dsu.cpp`](./examples/example_dsu.cpp)       | [Luogu P3367](problems/luogu/P3367_DSU.cpp)       |
| `MatrixMod.h`        | Fast matrix operations (addition, multiplication, power) under a static modulus. | [`example_matrix.cpp`](./examples/example_matrix.cpp) | [Luogu P1939](problems/luogu/P1939_MatrixMod.cpp) |
| **Geometry**         |                                                              |                                                       |                                                   |
| `Geometry.h`         | (Coming Soon) Basic geometric objects and operations (Point, Vector, Line, etc.). | -                                                     | -                                                 |
| **Advanced**         |                                                              |                                                       |                                                   |
| `SAM.h`              | (Coming Soon) Suffix Automaton for complex string problems.  | -                                                     | -                                                 |
| *... (more to come)* |                                                              |                                                       |                                                   |

## 🤝 How to Contribute

This project is a continuous effort. If you find a bug, have a suggestion for a new template, or want to improve an existing one, please feel free to:

1.  Open an [Issue](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY/issues) to discuss the change.
2.  Fork the repository and submit a [Pull Request](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY/pulls).

All contributions are welcome!

## 🙏 Acknowledgements

A huge thank you to the communities and individuals whose work has inspired this project, including the authors of the [OI-wiki](https://oi-wiki.org/), the Topcoder community, and countless competitive programmers who have shared their knowledge.

## 📝 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.
