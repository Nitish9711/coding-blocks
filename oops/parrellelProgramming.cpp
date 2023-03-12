#include <iostream>
#include <omp.h>

int main() {
  const int N = 1000000;
  double x[N], y[N], z[N];
  
  // Initialize arrays
  for (int i = 0; i < N; i++) {
    x[i] = i;
    y[i] = 2 * i;
  }
  
  // Calculate z[i] = x[i] + y[i] in parallel
  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    z[i] = x[i] + y[i];
  }
  
  // Print result
  std::cout << "The result of z[i] = x[i] + y[i] for i = 0 to " << N - 1 << " is: " << std::endl;
  for (int i = 0; i < N; i++) {
    std::cout << z[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
/*In the above example, the program calculates the element-wise sum of two arrays x and y and stores the result in a third array z. The calculation is done in parallel using OpenMP's parallel for construct, which distributes the work among multiple threads to improve performance.

The #pragma omp parallel for directive tells the compiler to parallelize the loop that follows it. The loop is split into multiple iterations, which are executed in parallel by different threads. The number of threads is determined automatically by the OpenMP runtime system, based on the available hardware resources.

Parallel programming can be used to speed up the execution of programs that perform computationally intensive tasks, such as numerical simulations, data analysis, and machine learning. */