#include <math.h>
#include <stdio.h>

typedef float Function(float x);

float secants(Function* f, float x0, float x1, float epsilon) {
    
    printf("%f \t %f \t %f\n", x0, x1, (*f)(x1));

    if (fabs((*f)(x1)) <= epsilon) {
        return x1;
    }

    float xn = (*f)(x1) * (x1 - x0);
    xn /= (*f)(x1) - (*f)(x0);
    xn = x1 - xn;

    return secants(f, x1, xn, epsilon);
}

float f(float x) {
    return exp(x) - 2 * x - 1;
}

int main() {

    secants(f, 1, 2, 0.001);

}