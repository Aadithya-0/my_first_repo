#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of digits: ");
    // scanf("%d", &n);

    // Approximation using acos function
    double pi = 2 * acos(0.0);

    // Print with desired precision
    printf("Pi to %d digits: %.15lf\n", n, pi);

    return 0;
}
