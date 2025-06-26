#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NUM_FUNCS 5
int N;
// Function definitions
double f1(double x) { return 5 * x * exp(-2 * x); }
double f2(double x) { return sin(x) * sin(x); }
double f3(double x) { return x*sin(x); }
double f4(double x) { return exp(3 * x) * sin(2 * x); }
double f5(double x) { return exp(-x) * x * x; }

// Simpson's 3/8 Rule
double simpsons_rule(double (*f)(double), double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Error: n must be a multiple of 3.\n");
        return NAN;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    return (3 * h / 8) * sum;
}

int main() {
    // Function pointer array
    double (*functions[NUM_FUNCS])(double) = {f1, f2, f3, f4, f5};

    // Integration limits
    double a[NUM_FUNCS] = {0.1, 0.0, 0.0, 0.0, 0.0};
    double b[NUM_FUNCS] = {1.3, M_PI, M_PI / 4.0, M_PI/4.0, 1.0};

    // Descriptions
    const char *labels[NUM_FUNCS] = {
        " 5x * e^(-2x) dx",
        " sin^2(x) dx",
        " x sin(x) dx",
        " e^(3x) * sin(2x) dx",
        " e^(-x) * x^2 dx"
    };
    // Reference values from the problem sheet
    double reference[NUM_FUNCS] = {
        (3.0 * exp(-13.0 / 5.0) * (exp(12.0 / 5.0) - 3.0)) / 2.0,
        M_PI / 2,
        1.517464139167518e-01,
        (3*exp(3*M_PI/4.0) +2.0)/13.0,
        2.0 - 5.0 * exp(-1.0)
    };
    printf("Enter the Value of N =");
    scanf("%d", &N);
    // Output
    printf("Simpson's 3/8 Rule Integration (n = %d)\n\n", N);
    for (int i = 0; i < NUM_FUNCS; i++) {
        double result = simpsons_rule(functions[i], a[i], b[i], N);
        double error = fabs(result - reference[i]);
        printf("%d. %s\n", i + 1, labels[i]);
        printf("   Calculated: %.10lf\n", result);
        printf("   Reference : %.10lf\n", reference[i]);
        printf("   Error     : %.10le\n\n", error);
    }

    return 0;
}
