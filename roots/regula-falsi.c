#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef float Function(float x);

typedef struct Interval {
    float a;
    float b;    
} Interval;

float regulaFalsi(Function* f, Interval* interval, float epsilon) {
    
    float x = interval->a * (*f)(interval->b) - interval->b * (*f)(interval->a);
    x /= (*f)(interval->b) - (*f)(interval->a);

    printf(
        "%f\t %f \t %f \t %f \t %f \t %f \n", 
        interval->a, 
        interval->b, 
        x, 
        (*f)(x), 
        (*f)(interval->a), 
        (*f)(interval->b)
    );

    if (fabs((*f)(x)) <= epsilon) {
        return x;
    }

    if ((*f)(interval->a) * (*f)(x) < 0) {
        interval->b = x;
        return regulaFalsi(f, interval, epsilon);
    }

    interval->a = x;
    return regulaFalsi(f, interval, epsilon);
}

float g(float x) {
    return exp(x) - 2 * x - 1;
}

int main() {

    Interval interval = { 1, 2 };
    regulaFalsi(g, &interval, 0.01);

}