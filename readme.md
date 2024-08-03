# CraneVM

Welcome to **CraneVM**, a versatile virtual machine designed for high performance and flexibility. This README will guide you through the process of building CraneVM from source using CMake and Make.

## Table of Contents

- [CraneVM](#cranevm)
  - [Table of Contents](#table-of-contents)
  - [Prerequisites](#prerequisites)
  - [Building CraneVM](#building-cranevm)
    -   [Windows](#windows)
    -   [Linux](#linux)
  - [Usage](#usage)
  - [Contributing](#contributing)
  - [License](#license)

## Prerequisites

Before you can build CraneVM, you need to have the following software installed on your system:

- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/) (version 3.10 or higher)
- [Make](https://www.gnu.org/software/make/)
- A C++ compiler (e.g., GCC, Clang)

## Building CraneVM

Follow these steps to build CraneVM from source:

### Windows

1. **Clone the repository:**

    ```sh
    git clone https://github.com/sam-buckley/CraneVM.git
    cd CraneVM
    ```

2. **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the build:**

    ```sh
    cmake -G "Unix Makefiles" .. -B ./
    ```

5. **Build the project using Make:**

    ```sh
    make
    ```

### Linux

1. **Clone the repository:**

    ```sh
    git clone https://github.com/sam-buckley/CraneVM.git
    cd CraneVM
    ```

2. **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the build:**

    ```sh
    cmake .. -B ./
    ```

5. **Build the project using Make:**

    ```sh
    make
    ```


After these steps, the CraneVM executable should be built and available in the `build` directory.

## Usage

Once you have built CraneVM, you can run it from the command line. For example:

```sh
./CraneVM [options]
```

To see a list of available options use:

```sh
./CraneVM --help
```

## Contributing

We welcome contributions to CraneVM! To contribute, please follow these steps:

1. **Fork the repository:**

    Click the "Fork" button at the top right of the GitHub page.

2. **Clone your fork:**

    ```sh
    git clone https://github.com/sam-buckley/CraneVM.git
    cd CraneVM
    ```

3. **Create a new branch:**

    ```sh
    git checkout -b my-feature-branch
    ```

4. **Make your changes and commit them:**

    ```sh
    git add .
    git commit -m "Description of your changes"
    ```

5. **Push your changes to your fork:**

    ```sh
    git push origin my-feature-branch
    ```

6. **Submit a pull request:**

    Go to the original repository on GitHub and click "New pull request."

## License

CraneVM is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
