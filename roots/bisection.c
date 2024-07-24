#include <stdio.h>
#include <math.h>

typedef float Function(float x);

typedef struct Interval {
    float a;
    float b;    
} Interval;

float bisection(Function* f, Interval* interval, float epsilon) {

    float x = (interval->a + interval->b) / 2;

    float intervalSize = (interval->b - interval->a) / 2;

    printf(
        "%f\t %f \t %f \t %f \t %f \t %f \n", 
        interval->a, 
        interval->b, 
        x, 
        (*f)(x), 
        (*f)(interval->a), 
        (*f)(interval->b)
    );

    if (intervalSize <= epsilon) {
        return x;
    }

    if ((*f)(interval->a) * (*f)(x) < 0) {
        interval->b = x;
        return bisection(f, interval, epsilon);
    }

    interval->a = x;
    return bisection(f, interval, epsilon);
}


float g(float x) {
    return exp(x) - 2 * x - 1;
}

int main() {

    Interval interval = { 1, 2 };
    bisection(g, &interval, 0.01);

}