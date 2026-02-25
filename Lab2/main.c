#include <stdio.h>
#include "isEven.h"
int main() {
    int num;
    printf("Enter an integer: ");

    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isEven(num)) {
        printf("%d is even\n", num);
        return 1;
    }
    if (isEven(num)) {
        printf("%d is even\n", num);
    }
    else {
        printf("%d is odd\n", num);
    }
    return 0;
}
