# Vector Operations Library
> [Bản Tiếng Việt](README.vi.md)
> 
A robust C++ implementation of an n-dimensional mathematical vector class featuring dynamic memory management, exception-safe resource handling, and comprehensive operator overloading.

## Key Features

- **Dynamic Dimension Support**: Supports runtime configuration of vector dimensionality with heap allocation.
- **Rule of Three Compliance**: Implements custom destructor, copy constructor, and copy assignment operator ensuring deep copying and zero memory leaks.
- **Exception-Safe Design**: Incorporates the copy-and-swap idiom for strong exception safety during assignment operations.
- **Arithmetic Overloading**: Provides intuitive vector operations including addition, subtraction, and dot product (scalar multiplication).
- **Safe Element Access**: Implements subscript operators (`[]`) with bounds checking throwing standard exceptions upon invalid access.
- **Robust Error Handling**: Throws `std::invalid_argument` on dimension mismatches and `std::out_of_range` on index violations.

## Project Structure

```text
.
├── Vecto.h        # Class declaration, method prototypes, and operator interfaces
├── Vecto.cpp      # Implementation of member methods and operator overloads
├── main.cpp       # Demonstration program and test driver
├── .gitignore     # Git ignore rules for build artifacts
└── README.md      # Technical project documentation
```

## API Reference

### Constructors and Destructor

| Signature | Description |
| :--- | :--- |
| `Vecto(int dim = 0)` | Constructs a zero-initialized vector of dimension `dim`. |
| `Vecto(const Vecto& v)` | Copy constructor. Allocates independent memory and performs deep copy. |
| `~Vecto()` | Destructor. Deallocates dynamically allocated memory. |

### Member Functions

| Signature | Description |
| :--- | :--- |
| `void Nhap()` | Reads vector dimension and coordinates from standard input. Cleans existing data first. |
| `void Xuat() const` | Outputs vector coordinates to standard output. Prints "Vecto rong" if empty. |

### Operator Overloads

| Signature | Return Type | Description |
| :--- | :--- | :--- |
| `operator+(const Vecto& b) const` | `Vecto` | Element-wise vector addition. Throws `std::invalid_argument` on dimension mismatch or empty state. |
| `operator-(const Vecto& b) const` | `Vecto` | Element-wise vector subtraction. Throws `std::invalid_argument` on dimension mismatch or empty state. |
| `operator*(const Vecto& b) const` | `double` | Computes the scalar dot product. Throws `std::invalid_argument` on dimension mismatch or empty state. |
| `operator=(const Vecto& other)` | `Vecto&` | Deep copies using copy-and-swap semantics. |
| `operator[](int index)` | `double&` | Mutable subscript access. Throws `std::out_of_range` if index is out of bounds. |
| `operator[](int index) const` | `const double&` | Read-only subscript access. Throws `std::out_of_range` if index is out of bounds. |

## Build and Run

### Prerequisites

- GCC / G++ (supporting C++11 or later)
- Make (optional)

### Compilation

Compile the project files using `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp Vecto.cpp -o vector_program
```

### Execution

#### Linux / macOS
```bash
./vector_program
```

#### Windows (Command Prompt / PowerShell)
```cmd
vector_program.exe
```

## Example Usage

```cpp
#include <iostream>
#include "Vecto.h"

int main() {
    try {
        Vecto v1, v2;

        std::cout << "Input Vector 1:\n";
        v1.Nhap();

        std::cout << "Input Vector 2:\n";
        v2.Nhap();

        // Dot product calculation
        double dot_product = v1 * v2;
        std::cout << "Dot product: " << dot_product << std::endl;

        // Subscript access and modification
        v1[0] = 99.9;
        std::cout << "Vector 1 after modifying first coordinate: ";
        v1.Xuat();

        // Vector arithmetic
        Vecto v3 = v1 + v2;
        std::cout << "Vector 1 + Vector 2: ";
        v3.Xuat();

    } catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```
