# CraneVM

Welcome to **CraneVM**, a versatile virtual machine designed for high performance and flexibility. This README will guide you through the process of building CraneVM from source using CMake and Make.

## Table of Contents

- [CraneVM](#cranevm)
  - [Table of Contents](#table-of-contents)
  - [Prerequisites](#prerequisites)
  - [Building CraneVM](#building-cranevm)
  - [Usage](#usage)

## Prerequisites

Before you can build CraneVM, you need to have the following software installed on your system:

- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/) (version 3.10 or higher)
- [Make](https://www.gnu.org/software/make/)
- A C++ compiler (e.g., GCC, Clang)

## Building CraneVM

Follow these steps to build CraneVM from source:

1. **Clone the repository:**

    ```sh
    git clone https://github.com/yourusername/CraneVM.git
    cd CraneVM
    ```

2. **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the build:**

    ```sh
    cmake ..
    ```

4. **Build the project using Make:**

    ```sh
    make
    ```

After these steps, the CraneVM executable should be built and available in the `build` directory.

## Usage

Once you have built CraneVM, you can run it from the command line. For example:

```sh
./CraneVM [options]
