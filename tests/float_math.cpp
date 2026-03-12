// Native C++ module with float/double functions
#include <cmath>

extern "C" {
    double square(double x) {
        return x * x;
    }
    
    double sqrt_wrapper(double x) {
        return std::sqrt(x);
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    double multiply(double a, double b) {
        return a * b;
    }
}
