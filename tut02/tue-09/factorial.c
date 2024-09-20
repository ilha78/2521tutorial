#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    // base case
    if (n == 0) {
        return 1;
    }

    // recursive case
    // n! = n * (n-1)!
    return n * factorial(n - 1);

}

int main(void) {
    int n = 7;
    printf("%d", factorial(n));

    return 0;
}