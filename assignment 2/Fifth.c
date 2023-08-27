/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }

    double result = base;

    // Calculate power using a loop
    for (int i = 1; i < abs(exponent); i++) {
        result *= base;
    }

    // Adjust the result based on the sign of the exponent
    if (exponent < 0) {
        result = 1.0 / result;
    }

    return result;
}

int main () {
	double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double ans = power(base, exponent);
    printf("Result: %lf\n", ans);

    return 0;
}