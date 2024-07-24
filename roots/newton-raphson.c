#include <math.h>
#include <stdio.h>

typedef float Function(float x);

float newtonRaphson(Function* f, Function* fLine, float x, float epsilon) {
    
    printf("%f \t %f\n", x, (*f)(x));

    if (fabs((*f)(x)) <= epsilon) {
        return x;
    }

    float xn = x - (*f)(x) / (*fLine)(x);

    return newtonRaphson(f, fLine, xn, epsilon);
}

float f(float x) {
    return exp(x) - 2 * x - 1;
}

float fLine(float x) {
    return exp(x) - 2;
}

int main() {

    newtonRaphson(f, fLine, 1, 0.01);

}