#include <math.h>
#include <stdio.h>

typedef float Function(float x);

float fixedPoint(Function* f, Function* g, float x, float epsilon) {
    
    printf("%f \t %f \t %f\n", x, (*f)(x), (*g)(x));
    
    if (fabs((*f)(x)) <= epsilon) {
        return x;
    }

    return fixedPoint(f, g, (*g)(x), epsilon);
}

float f(float x) {
    return exp(x) - 2 * x - 1;
}

float g(float x) {
    return (exp(x) - 1) / 2;
}

int main() {

    fixedPoint(f, g, 1, 0.01);

}