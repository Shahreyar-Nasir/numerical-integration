#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define NUM_FUNCS 5
int N = 4; // Number of Gauss-Legendre points

// Function definitions
double f1(double x) { return 5 * x * exp(-2 * x); }
double f2(double x) { return sin(x) * sin(x); }
double f3(double x) { return x * sin(x); }
double f4(double x) { return exp(3 * x) * sin(2 * x); }
double f5(double x) { return exp(-x) * x * x; }

// 4-point Gauss-Legendre Quadrature
double gauss_legendre(double (*f)(double), double a, double b) {
    // Nodes and weights for 4-point Gauss-Legendre Quadrature
    double nodes[] = {
        -0.8611363115940526,
        -0.3399810435848563,
         0.3399810435848563,
         0.8611363115940526
    };
    double weights[] = {
        0.3478548451374539,
        0.6521451548625461,
        0.6521451548625461,
        0.3478548451374539
    };

    double sum = 0.0;

    for (int i = 0; i < 4; i++) {
        double x = 0.5 * (b - a) * nodes[i] + 0.5 * (a + b); // Mapping to [a,b]
        sum += weights[i] * f(x);
    }

    return 0.5 * (b - a) * sum;
}

int main() {
    // Function pointer array
    double (*functions[NUM_FUNCS])(double) = {f1, f2, f3, f4, f5};

    // Integration limits
    double a[NUM_FUNCS] = {0.1, 0.0, 0.0, 0.0, 0.0};
    double b[NUM_FUNCS] = {1.3, M_PI, M_PI / 4.0, M_PI / 4.0, 1.0};

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
        (3 * exp(3 * M_PI / 4.0) + 2.0) / 13.0,
        2.0 - 5.0 * exp(-1.0)
    };

    // Output
    printf("Gauss Legendre Rule Integration (n = %d)\n\n", N);
    for (int i = 0; i < NUM_FUNCS; i++) {
        double result = gauss_legendre(functions[i], a[i], b[i]);
        double error = fabs(result - reference[i]);
        printf("%d. %s\n", i + 1, labels[i]);
        printf("   Calculated: %.10lf\n", result);
        printf("   Reference : %.10lf\n", reference[i]);
        printf("   Error     : %.10le\n\n", error);
    }

    return 0;
}
