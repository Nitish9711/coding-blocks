// Functional programming is a programming paradigm that emphasizes the use of functions to solve problems. It is based on the principles of mathematical functions, which take inputs and produce outputs without side effects.

// In functional programming, functions are treated as first-class citizens, which means they can be passed as arguments to other functions, returned as values from functions, and stored in variables.

// One of the key characteristics of functional programming is immutability. In functional programming, data is treated as immutable, which means that once a value is assigned to a variable, it cannot be changed. Instead, new values are created by applying functions to existing values.

// Another important concept in functional programming is higher-order functions, which are functions that take other functions as arguments or return functions as results. Higher-order functions can be used to abstract away common patterns of code and create reusable code.

// Functional programming languages include Haskell, Lisp, ML, and Scala. However, many mainstream languages like C++, Java, Python, and JavaScript also support functional programming features.
#include <iostream>
#include <vector>
#include <algorithm>

int square(int x) {
    return x * x;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};

    // Use std::transform to apply the square function to each element of the input vector
    std::vector<int> output(input.size());
    std::transform(input.begin(), input.end(), output.begin(), square);

    // Print the output vector
    std::cout << "Input: ";
    for (auto x : input) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Output: ";
    for (auto x : output) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
// In this program, we define a square function that takes an integer as input and returns its square.

// We then create a vector called input that contains the integers 1 to 5.

// We use the std::transform function from the standard library to apply the square function to each element of the input vector, and store the result in a new vector called output.

// Finally, we print the contents of the input and output vectors to the console.

// The std::transform function is an example of a higher-order function, which takes a function (in this case, square) as an argument and applies it to each element of a container (in this case, input). This allows us to abstract away the details of the loop and create reusable code.