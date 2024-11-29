# x86-to-64 Interface Programming Project

This repository contains the source files for computing the dot product between two double-precision float vectors, **X** and **Y**, using C and x86-64 kernels. A value of **2.0** was initialized and stored in vector **X**, while a value of **1.0** was used in vector **Y**. The output is stored in **sdot**.

## Performance of the Kernels
To measure the performance of the two kernels, each version was run 20 times with varying sizes for the vector size **n**: \(2^{20}, 2^{24}, 2^{27}\). After each iteration, the average execution time was recorded.

### Debug Mode
#### Vector Size: \(2<sup>20</sup>\)
![debug 20](https://github.com/user-attachments/assets/7c204a94-c755-49f5-b46f-122492f86877)
Program Output in C and x86-64 with Correctness Check

#### Vector Size: \(2<sup>24</sup>\)
![debug 24](https://github.com/user-attachments/assets/24d582a0-5a7f-4c74-b381-d47f291cc064)
Program Output in C and x86-64 with Correctness Check

#### Vector Size: \(2<sup>27</sup>\)
![debug 27](https://github.com/user-attachments/assets/1f5d547d-f823-497e-8acd-7d3759d4196d)
Program Output in C and x86-64 with Correctness Check

### Release Mode
#### Vector Size: \(2<sup>20</sup>\)
![release 20](https://github.com/user-attachments/assets/7b964e13-23a8-429f-8afc-88b6fda4a771)
Program Output in C and x86-64 with Correctness Check

#### Vector Size: \(2<sup>24</sup>\)
![release 24](https://github.com/user-attachments/assets/cb732c17-56d3-4dad-9fd2-46683a86dd14)
Program Output in C and x86-64 with Correctness Check

#### Vector Size: \(2<sup>27</sup>\)
![release 27](https://github.com/user-attachments/assets/8d04c509-514c-4efd-8e0c-c79789349aca)
Program Output in C and x86-64 with Correctness Check

## Comparison and Analysis
### Performance in Debug Mode
In Debug Mode, the x86-64 assembly kernel version consistently outperformed the C version across different vector sizes. This is primarily because, in debug mode, the compiler compiles the code as is. Thus, the C version runs with no optimizations and may run slower due to added debugging information and runtime checks. On the other hand, the assembly code is unaffected by these debug features, as it is already in its optimized, low-level form.

### Performance in Release Mode
In Release Mode, the C implementation yielded faster execution times compared to the x86-64 assembly kernel. During the compilation of release builds, the compiler applies aggressive optimizations, leading to faster execution and minimal memory usage. In this mode, the absence of runtime checks allows for highly efficient execution, often surpassing manually written assembly code.

