# SqrtAlgo

A minimal C++ implementation of a fast square root algorithm. The project demonstrates an efficient method for computing square roots, suitable for numerical applications where performance and precision are important.

## Overview

The algorithm provides a function to compute the square root of a given number using an iterative method such as Newton's iteration. It offers predictable convergence and good numerical stability.

## Features

* Simple and readable C++ implementation
* Fast convergence using iterative refinement
* Works with standard floating-point types

## Usage

Include the header or source file in your project and call the function:

```cpp
double result = sqrt_algo(25.0);
```

## Build

Compile using any standard C++ compiler:

```bash
g++ -O2 -std=c++17 main.cpp -o sqrtalgo
```

